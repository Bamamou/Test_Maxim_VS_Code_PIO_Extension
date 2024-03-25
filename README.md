# ESP32_ECU
+ Evoke Motorcycles ECU Gen 2 Software Source Code
+ This version was built on top of version 2.26
+ The major changed is that the current ANT BMS communication protocol is changed from UART to CAN 2.0
+ The CAN protocol has 11 packets with a baud rate of 250kps
+ To avoid confict with the charger, the packet frame 11 isn't sent and the ECU handle it.
+ The data structure of the can protocol is the small endian or Intel
+ Since the capacity packets were not sent, Nicolas set the physical capacity to 100Ah and map the remaining capacity or residual capacity from SOC with 5% marging
+ We can't display the  highest (Strongest) and lowest (Weakest) cell number or index because it is not sent by the CAN
# Note
+ Pleae make sure to downgrade your PlatformIo to 3.5.0 while compiling and testing this code (platform = espressif32@3.5.0)
+ Please don't just dealete the unused packects from the BMS (Packet11 to Packet17) becasue they called elsewher in the code. If needed, please remember to track them and dealete everywhere otherwise you won't be able to compile the entire code
+ The BMS type is set to 1 in order to call the Task_CANExt.cpp function which allow us to run the CAN BMS instead of the UART on
+ The function Task_BMSUART.cpp is not working and it can work if you change the BMStype function to 0 which will also stop the Task_CANExt.cpp

Changelog
2.28 -> 2.3.0, AntBMS CAN protocol updated at 2.3.0. Moving forward, incrementing 2.3.x versioning system

2.x.y.z
x=major changes and major restructuring of source code
y=newly added features or operational adjustment to source code
z=minor adjustments, bug fixes or general cleanup