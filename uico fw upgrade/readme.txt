V0.0
Feature:
1.modify firmware parameter to support one minutes lighting on for screen  
2.support to merge uico firmware with band firmware automatically
3.only support uico firmware with limitation of 14Kb


//===============================================================================
Folder Structure£º
device_programming£ºinternally used
driver_software£º   related driver software which should be installed when first used by user
uico_binary£º	    folder where the uico firmware locates


//======================================================================================
Reference:
1.install related driver software located in driver_software folder from nordic official website when fist used
2.replace uico binary file need to be burned in folder uico_binary and rename it to Uico.bin
3.make sure to plug burning equipment to pc through usb and put band onto the fixer connected with burning equipment
4.run user_bat.bat, here we go!!

V0.1
NEW Feature:
1.band frimware has the ability to adapt to diffrent uico binary size
2.change parameter of bin to hex tool to set block size to 16 bytes



