mkdir .\Release\package
mkdir .\Release\package\.trex
rem mkdir .\Release\package\base
copy .\Release\WhiteRabbitRend.asi .\Release\package\
copy .\Release\WhiteRabbitRend.pdb .\Release\package\
copy .\Release\winmm.dll .\Release\package\
rem copy .\resources\bridge.conf .\Release\package\.trex\
rem copy .\resources\autoexec.cfg .\Release\package\base\
7z a -tzip whiterabbit-renderer.zip .\Release\package\*