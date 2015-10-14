for /f "tokens=1,2 delims==" %%a in (fv.txt) do ( set "test=%%a")
echo %test%
nrfjprog.exe  --eraseall 
nrfjprog.exe --reset 
nrfjprog.exe --clockspeed 2000

nrfjprog.exe  --eraseall 
nrfjprog.exe --reset 
nrfjprog.exe  --clockspeed 2000 
nrfjprog.exe  --program s110_nrf51_8.0.0_softdevice.hex --verify
nrfjprog.exe --program %test%.hex --verify 
nrfjprog.exe --program lemonBootloader.hex --verify 
nrfjprog.exe --pinreset
pause