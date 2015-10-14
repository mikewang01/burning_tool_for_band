for /f "tokens=1,2 delims==" %%a in (D:\hex\lemon\uico\fv.txt) do ( set "test=%%a")
echo %test%
nrfjprog.exe  --eraseall 
nrfjprog.exe --reset 
nrfjprog.exe --clockspeed 2000

nrfjprog.exe  --eraseall 
nrfjprog.exe --reset 
nrfjprog.exe  --clockspeed 2000 
nrfjprog.exe  --program D:\hex\lemon\uico\s110_nrf51_8.0.0_softdevice.hex --verify
nrfjprog.exe --program D:\hex\lemon\uico\%test%.hex --verify 
nrfjprog.exe --program D:\hex\lemon\uico\lemonBootloader.hex --verify 
nrfjprog.exe --pinreset
pause