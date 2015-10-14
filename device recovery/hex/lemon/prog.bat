for /f "tokens=1,2 delims==" %%a in (D:\hex\lemon\tf.txt) do ( set "test=%%a")
echo %test%
nrfjprog.exe  --eraseall 
nrfjprog.exe  --reset 
nrfjprog.exe  --clockspeed 2000
nrfjprog.exe  --eraseall 
nrfjprog.exe --program D:\hex\lemon\s110_nrf51_8.0.0_softdevice.hex --verify 
nrfjprog.exe --program D:\hex\lemon\ClingBand_1_76.hex --verify 
nrfjprog.exe --program D:\hex\lemon\bootloader.hex --verify 
nrfjprog.exe --pinreset 
pause