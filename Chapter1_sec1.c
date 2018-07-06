/*
helpful link->https://0xax.gitbooks.io/linux-insides/DataStructures/linux-datastructures-2.html
or
https://www.youtube.com/watch?v=pet3bOhOXzY&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS

Unit 1->ARM register, ARM CPU mode, ARM assembly, 

Unit 2->External hardware and device driver

Clock->Memory, Flash, port, data sheet, manual

Unit 3->ARM boot loader

Like BIOS
-Boot->like the embedded board to intialized by the minimum hardware enviroment (4:57)
-loader->Let the OS(Linux/Android) inside the flash/hard drive (5:17) into the RAM (5:44)
and redy to execute (5:49)
-U_boot->open source (6:14). They are using tiny-210 development board (6:49) based on ARM 
cortex A8 (1GHz) (@7:48)

Unit 4->ARM interrupt programming (@8:02)
-Software interrupt
-Hardware interrupt(@8:14)
-U must know the interrupt bofore going to the OS. Otherwise, it won't help(@8:26)
-When there is a context switch(切换) required for swapping out one process running on the CPU. It requires
interrupt(@8:42)
-When interrupt happen during the context switch, it needs to keep what have left from previous CPU state (8:48)
-When interrupt ends, it needs to go back to the previous state (8:52)
-how to keep and return to the prvious state, it relates
to the ARM interrupt assembly code (8:55) NOT in C lanquage (9:02)

Unit 6->Linux OS (@9:44)
-After understaning the development board in arm, we will move on to Linux OS
-What we need to know how to register the device driver in Linux (@10:32)
-We will focus on the character device driver (11:11)
  -Block device driver for LED (@18:41)->require development board
  -We can simulate this through our PC(@19:12)
-Network
-USB
-Under chacracter device driver->it deals with a lot of data strcture(12:04)
-Such as double link list in linux kernel (12:30)
-Tree (data structure) (12:36)
-So before we dig into device driver, we need to go through Unit 5

Unit 5->Linux Kernel core data structure (13:14)
-VFS->virtual file system(13:26)
        -file
        -kobject
-data structure
       -double link list (14:26)
       -Radix tree(14:45)
          ->https://0xax.gitbooks.io/linux-insides/DataStructures/linux-datastructures-2.html
          ->Don't use your creat your own data structure (14:55)
       -Data structure->Really important for interviewing
       -Bit array(16:34)
Unit 7->Linux interrupt (17:05)
  -Part 1(上半部)->it relates to kernel while writing device driver (17:55)
  -Part 2(下半部)
  -When there is a requirement to have context switch in process,we need to have interrupt (17:44)
  -
  
 Unit 8->串口驱动(serial port) (18:13)
    -linux interrupt programming
    -character device (18:24)
--------------Now move on to ARM architecture (@20:21)----------------------------------
ARM assembly (@24:20)
-Power Supply(@24:45) usually 5V (24:48)
-Powr ON/OFF (@25:05)
-Push buttom (@25:09)
-USB port(@25:31)
-COM port (25:58)->different COM port (@25:58) relates to RS-232 as desscribed
->https://www.electronicshub.org/types-of-computer-ports/
->https://www.aliexpress.com/item/Tiny210-development-board-with-7-inch-touch-screen-Android-4-0-Cortex-A8/559890438.html
-COM1 usually for transmitting files from PC to target board
-COM3 usually used for writing driver (@26:25)
-audio (26:35)
-microphone (@26:43)
-RJ-45 internet connection (26:50)
-S2 Boot Mode Switch->To boot (@27:03)->important
-Do we start from Nand flash or SD card? (@27:08)
  -It starts from the NAND flash (@27:26). It is like boot from from the hard drive(@27:32)
  -However, you have an optoin to boot from SD card (@27:38)
-Reset(@27:50)->reset the system
-There are extenral periphrals for connecting to the camera such as CDC/COMS switch/COMS camera (@28:04)
-AV2,AV1,TVOUT refers to the TV (@28:09)
-CON14:RS485 (@28:16) 
-adc模数转换器 may be at (@28:29) (Not sure)
-There is a 4.5" screen (@28:45)
-You need to provide the pressure for the touch screen (@29:09)
-There is a smaller board on top of the main board (@29:27)
-Don't ake out the smaller board (29:50)
-What's the core inside the CPU (@30:13)
  -CPU, RAM (30:29)
  -I don't even need a hard drive (@30:33)
-On the small board, there is a CPU (@30:42)
-Coretex A8 core (@30:47)
-In embedded system, the are a.k.a MPU->微处理器 (@31:11)
-Thare are four itmes looks the same (@31:18)->They are DRAM (@31:20)
-Each one has 128MB(兆字节) RAM (@31:27)
-Since there are 4 memories block=4 Channel(通道) (@32:18)
-Each channel provides one 字节(Byte) (@32:22)
-So if you are writing a long (4byte), it will be stored in 4 channels as 32 bytes (@32:39)
-Each byte is stored in each channel/RAM (@32:37)









  
*/
