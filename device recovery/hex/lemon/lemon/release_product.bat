for /f "tokens=1,2 delims==" %%a in (D:\hex\lemon\fv.txt) do ( set "test=%%a")
echo %test%
nrfjprog.exe --snr 681222873 --eraseall --reset --clockspeed 2000
nrfjprog.exe --snr 681222873 --eraseall --reset --clockspeed 2000
nrfjprog.exe --snr 681222873 --clockspeed 2000 --programs D:\hex\lemon\s110_nrf51_8.0.0_softdevice.hex --program D:\hex\lemon\%test%.hex D:\hex\lemon\lemonBootloader.hex --verify --pinreset