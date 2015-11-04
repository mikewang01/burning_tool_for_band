del Lemon.hex
ping localhost -n 1 > nul

.\binhextool\srec_cat ../cling_binary/Lemon.bin  -binary -offset 0x00018000  -Output_Block_Size 16 -o Lemon.hex -intel
