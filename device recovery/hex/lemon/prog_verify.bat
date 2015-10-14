@echo off
:restart 
del /q /s D:\hex\log_cling_prog\log.txt
call D:\hex\lemon\prog.bat
find "Verify OK" D:\hex\log_cling_prog\log.txt
if errorlevel 1 echo "!!!!!!Programming Failed!!!!!!" & pause & goto restart else exit
exit


