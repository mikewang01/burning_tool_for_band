for /f "tokens=1,2 delims==" %%a in (D:\hex\lemon\temp\tf.txt) do ( set "test=%%a")
echo %test%
nrfjprog.exe --snr 681222873 --eraseall --reset --clockspeed 2000
nrfjprog.exe --snr 681222873 --eraseall --reset --clockspeed 2000
nrfjprog.exe --snr 681222873 --clockspeed 2000 --programs D:\hex\lemon\s110_nrf51822_6.2.1_softdevice.hex --program D:\hex\lemon\temp\%test%.hex D:\hex\lemon\bootloader.hex --verify --pinreset >> D:\hex\log_cling_prog\log.txt
