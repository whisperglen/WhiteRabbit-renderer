#pragma once

#include <stdint.h>

void NormalSmoothing_Reset();
void NormalSmoothing_Mark(int first, int end);
void NormalSmoothing_Run(const float* xyz, float* normals, const uint32_t* indices,
                         int vertexCount, int indexCount, int mode);
