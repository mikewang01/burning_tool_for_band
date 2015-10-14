::uico firmware file name 
::if needed u can change it
set VAR_UICO_FILE_NAME=Uico.bin

echo %VAR_UICO_FILE_NAME%
cd ./device_programming
call merge.bat %VAR_UICO_FILE_NAME%
call bintohex.bat
call prog.bat
cd ..
pause