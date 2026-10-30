#include "normal_smoothing.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

extern "C" void RendererLogPrintf(const char* fmt, ...);

/* Experimental per-batch smoothing; 1 retains triangle area weighting. */
#ifndef NORMALS_KEEP_AREA_WEIGHT
#define NORMALS_KEEP_AREA_WEIGHT 0
#endif
static const int MAX_SMOOTH_VERTICES = 30000;
static uint8_t s_smoothVertex[MAX_SMOOTH_VERTICES];
static uint16_t s_smoothSortedVertices[MAX_SMOOTH_VERTICES];
static float s_smoothAccumulated[MAX_SMOOTH_VERTICES][3];
static const float* s_smoothPositions = nullptr;
static bool s_smoothLargeGroupWarned = false;

static float smooth_dot(const float* a, const float* b)
{
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

static bool smooth_normalize(float* v)
{
    const float lengthSquared = smooth_dot(v, v);
    if (!(lengthSquared > 1e-20f))
        return false;
    const float inverseLength = 1.0f / sqrtf(lengthSquared);
    for (int i = 0; i < 3; ++i)
        v[i] *= inverseLength;
    return true;
}

static int __cdecl compare_smooth_positions(const void* lhs, const void* rhs)
{
    const float* xyz = s_smoothPositions;
    const float* a = xyz + 4 * *static_cast<const uint16_t*>(lhs);
    const float* b = xyz + 4 * *static_cast<const uint16_t*>(rhs);
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

static float g_smooth_cosine = 0.48f;

void NormalSmoothing_Run(const float* xyz, float* normals, const uint32_t* indices,
                         int vertexCount, int indexCount, int mode)
{
    if (vertexCount <= 0 || vertexCount > MAX_SMOOTH_VERTICES ||
        indexCount <= 0 || indexCount > 180000 || indexCount % 3 != 0)
        return;

    s_smoothPositions = xyz;
    int smoothVertexCount = 0;
    for (int i = 0; i < vertexCount; ++i)
    {
        if (s_smoothVertex[i])
        {
            s_smoothSortedVertices[smoothVertexCount++] = (uint16_t)i;
            memset(s_smoothAccumulated[i], 0, sizeof(s_smoothAccumulated[i]));
        }
    }
    if (!smoothVertexCount)
        return;

    for (int i = 0; i < indexCount; i += 3)
    {
        const uint32_t a = indices[i], b = indices[i + 1], c = indices[i + 2];
        if (a >= (uint32_t)vertexCount || b >= (uint32_t)vertexCount ||
            c >= (uint32_t)vertexCount || !s_smoothVertex[a] ||
            !s_smoothVertex[b] || !s_smoothVertex[c])
            continue;
        const float* p = xyz + a * 4;
        const float* q = xyz + b * 4;
        const float* r = xyz + c * 4;
        const float e1[3] = { p[0]-q[0], p[1]-q[1], p[2]-q[2] };
        const float e2[3] = { r[0]-q[0], r[1]-q[1], r[2]-q[2] };
        float n[3] = { e1[1]*e2[2]-e1[2]*e2[1], e1[2]*e2[0]-e1[0]*e2[2],
                       e1[0]*e2[1]-e1[1]*e2[0] };
        if (!(smooth_dot(n, n) > 1e-20f))
            continue;
        /* Match the orientation of Alice's existing vertex normals. */
        if (smooth_dot(n, normals + a * 4) < 0.0f)
            for (int j = 0; j < 3; ++j) n[j] = -n[j];
#if !NORMALS_KEEP_AREA_WEIGHT
        smooth_normalize(n);
#endif
        const uint32_t vertices[3] = { a, b, c };
        for (int v = 0; v < 3; ++v)
        {
            float* dst = s_smoothAccumulated[vertices[v]];
            for (int j = 0; j < 3; ++j) dst[j] += n[j];
#if !NORMALS_KEEP_AREA_WEIGHT
            smooth_normalize(dst);
#endif
        }
    }

    qsort(s_smoothSortedVertices, smoothVertexCount, sizeof(uint16_t), compare_smooth_positions);
    for (int first = 0; first < smoothVertexCount; )
    {
        const float* anchor = xyz + s_smoothSortedVertices[first] * 4;
        int end = first + 1;
        while (end < smoothVertexCount)
        {
            const float* p = xyz + s_smoothSortedVertices[end] * 4;
            const float dx = p[0]-anchor[0], dy = p[1]-anchor[1], dz = p[2]-anchor[2];
            if (dx*dx + dy*dy + dz*dz >= 1e-10f) break;
            ++end;
        }
        const int count = end - first;
        if (count > 32)
        {
            if (!s_smoothLargeGroupWarned)
            {
                RendererLogPrintf("WARN: surface normal group exceeds 32 vertices; retaining original normals\n");
                s_smoothLargeGroupWarned = true;
            }
            first = end;
            continue;
        }

        if (mode == 0)
        {
            // exclusive grouping
            bool visited[32] = {};
            for (int i = 0; i < count; ++i)
            {
                if (visited[i]) continue;
                const float* base = s_smoothAccumulated[s_smoothSortedVertices[first + i]];
                float reference[3] = { base[0], base[1], base[2] };
                if (!smooth_normalize(reference)) { visited[i] = true; continue; }
                float sum[3] = { base[0], base[1], base[2] };
                bool members[32] = {};
                members[i] = true;
                for (int j = i + 1; j < count; ++j)
                {
                    if (visited[j]) continue;
                    const float* other = s_smoothAccumulated[s_smoothSortedVertices[first + j]];
                    float unit[3] = { other[0], other[1], other[2] };
                    if (!smooth_normalize(unit) || smooth_dot(reference, unit) <= g_smooth_cosine) continue;
                    members[j] = true;
                    bool duplicate = false;
                    for (int k = 0; k < j; ++k)
                    {
                        if (!members[k]) continue;
                        const float* prior = s_smoothAccumulated[s_smoothSortedVertices[first + k]];
                        float priorUnit[3] = { prior[0], prior[1], prior[2] };
                        if (smooth_normalize(priorUnit) && smooth_dot(priorUnit, unit) >= 0.999999f)
                            { duplicate = true; break; }
                    }
                    if (!duplicate)
                        for (int k = 0; k < 3; ++k) sum[k] += other[k];
                }
                if (smooth_normalize(sum))
                    for (int j = i; j < count; ++j)
                        if (members[j])
                        {
                            float* dst = normals + s_smoothSortedVertices[first + j] * 4;
                            memcpy(dst, sum, sizeof(sum));
                            visited[j] = true;
                        }
                visited[i] = true;
            }
        }
        else
        {
            // per-vertex averaging
            for (int i = 0; i < count; ++i)
            {
                const float* base = s_smoothAccumulated[s_smoothSortedVertices[first + i]];
                float reference[3] = { base[0], base[1], base[2] };
                if (!smooth_normalize(reference)) continue;
                float sum[3] = { base[0], base[1], base[2] };
                int added[32] = { i };
                int addedCount = 1;
                for (int j = 0; j < count; ++j)
                {
                    if (j == i) continue;
                    const float* other = s_smoothAccumulated[s_smoothSortedVertices[first + j]];
                    float unit[3] = { other[0], other[1], other[2] };
                    if (!smooth_normalize(unit) || smooth_dot(reference, unit) <= g_smooth_cosine) continue;
                    bool duplicate = false;
                    for (int k = 0; k < addedCount; ++k)
                    {
                        const float* prior = s_smoothAccumulated[s_smoothSortedVertices[first + added[k]]];
                        float priorUnit[3] = { prior[0], prior[1], prior[2] };
                        if (smooth_normalize(priorUnit) && smooth_dot(priorUnit, unit) >= 0.999999f)
                            { duplicate = true; break; }
                    }
                    if (!duplicate)
                    {
                        added[addedCount++] = j;
                        for (int k = 0; k < 3; ++k) sum[k] += other[k];
                    }
                }
                if (smooth_normalize(sum))
                {
                    float* dst = normals + s_smoothSortedVertices[first + i] * 4;
                    memcpy(dst, sum, sizeof(sum));
                }
            }
        }
        first = end;
    }
}

void NormalSmoothing_Reset()
{
    memset(s_smoothVertex, 0, sizeof(s_smoothVertex));
}

void NormalSmoothing_Mark(int first, int end)
{
    if (first >= 0 && first <= end && end <= MAX_SMOOTH_VERTICES)
        memset(s_smoothVertex + first, 1, end - first);
}
