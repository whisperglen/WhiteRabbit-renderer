mkdir .\Release\package
mkdir .\Release\package\.trex
mkdir .\Release\package\base
copy .\Release\WhiteRabbitRend.asi .\Release\package\
copy .\Release\WhiteRabbitRend.pdb .\Release\package\
copy .\Release\winmm.dll .\Release\package\
copy .\resources\bridge.conf .\Release\package\.trex\
copy .\resources\autoexec.cfg .\Release\package\base\
copy .\resources\alice_customise.ini .\Release\package\
7z a -tzip whiterabbit-renderer.zip .\Release\package\*