/*
-https://www.youtube.com/watch?v=pet3bOhOXzY&index=1&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS
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
-Block device driver
-Network
-USB
-Under chacracter device driver->it deals with a lot of data strcture(12:04)
-Such as double link list in linux kernel (12:30)
-Tree (data structure) (12:36)
-So before we dig into device driver, we need to go through Unit 5

Unit 5->Linux Kernel core data structure (13:14)









  
*/
