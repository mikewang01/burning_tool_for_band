nrfjprog.exe --clockspeed 2000
nrfjprog.exe --eraseall
nrfjprog.exe --reset 


echo "bin to hex convert"
nrfjprog.exe  --program .\s110_nrf51_8.0.0_softdevice.hex --verify
nrfjprog.exe  --program .\Lemon.hex --verify
nrfjprog.exe  --program	.\lemonBootloader.hex --verify
nrfjprog.exe   --pinreset 