Linux嵌入式开发和驱动开发--1ARM体系结构和汇
5 led灯实验
https://www.youtube.com/watch?v=xPONsaWO8gE&index=5&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS
->USB to RS232 connnector (0:24)
  -Reciever and transmitter (0:34)
  -So you need to go to the system control->Device Driver->COM AND LPT
    -Then you will see "COM4" in this case (1:16)
    -Use a terminal which will match as line 7 as "COM4" in this case (1:41)
    -baud rate=115200. It means it can sends 115200 bit per second (bps) (1:52)
      -unit is in 比特位 (2:00)= 115200/8 can be transmitted 传送 in 字节 (2:02)
      -link->https://blog.csdn.net/qq_25077833/article/details/53386562 
      -link->https://blog.csdn.net/dagefeijiqumeiguo/article/details/68921820
    -Databits->In each 8 bits= a data packet (数据包) (2:08)
    -Stop bit->after sending the 8 bits 比特位, we will send a stop 停止 bit 位/标志 (2:12)
    -parity check 奇偶校验 (2:18)
->When system starts, it boots from U-Boot (2:43) or boot loader like the one in BIOS (2:47)
->type "help" to what command line does the system board support (2:59)
      -This is boots from SD card (3:11)
      -I can also choose the boot from NAND flash as well (3:18)
      -Treat NAND flash like a hard disk(256 兆 MB) where linux sysetem is installed (3:22) and 线程(thread)/进程(process) (3:23) 
      browsing 浏览 (3:23)
      -using pwd->it will list where which direcotory 目录 you are in 
      -type pwd and result is "/" it means you are in root directory (根目录) (4:05)
      -After starting the linux on the target board, I can send the elf executable to the linux board (4:17)
      -AFter boot  启动 from SD card, I am like entering the BIOS (4:27) so it only boot 启动 from boot loader(4:31)
      -using "~" to boot 启动 from bootloader (4:31)(??) you will see sth like "U-Boot"
        -Whenn boot 启动 from bootlaoder only, it can't execute ELF file (4:35)
      -It can only deal with pure binary file (二进制文件)(4:38)
->Our development board 开发板 has four LED light (4:46)
   -We need to touch electronic schematic diagram 电子原理图 and data sheets 数据表 (5:07)
   -(6:09)
AREA asm1test,CODE,READONLY
   ENTRY
LED_TEST
   LDR R0,=0XE0200280
   LDR R1,=0x1111
   STR R1,[R0]
   
   LDR R0,=0XE0200284
   LDR R1,=0x3
   STR R1,[R0]
   B LED_TEST

   END
  -after typing "help"
  -you will see that there is a command as "mv" for memory write 写入内存 (6:35)
  -mv 0XE0200280 0x1111 (7:06) so LED light will be ON (7:25)
  -mv 0XE0200280 0x0000 (7:32) so LED light will be OFF (7:25)
  -bootloader only provides a command  命令  to operate it (7:39) via operating its address 地址 (7:43)
  -We can also write the assemlby 汇编 code to operatge LED as well. (7:48)
 ->When we want to operate the LED (7:59)
    -1) you need to see the electronic schematic diagram 电子原理图 (8:06)
    -2) Find the LED light (8:24)(8:46)
    -3) In (8:55) you will see LED x 4, you will see a diode (二极管)
    -4) On the right, it is 3.3V as VOD_SYS_3.3V (8:59). 3.3V is as high voltage (9:02)
    -5) On the left it is LED1 (9:07)
    -6) So in order to turn on the LED1 , we need to set LED1 to low level (低电平) and right with high level(高电平) (9:14)
    -7) On right with high level (高电平) has been fixed so what we need to do is to set the low level(低电平) on the left (9:23)
    -8) Where does this LED light connect to? (9:36)
    -9) We will see that it connects to GPJ2_0 to GPJ2_3 (9:40)
    -10)We will see that GPJ2_0 to GPJ2_3 are inside S5PV210 (9:54) which menas the CPU (9:59)
    -11)so GPJ2_0 to GPJ2_3 connects to four pins (引脚) of CPU (10:13)
    eg GPJ2_0-GPJ2_3，通过控制GPJ2_0-GPJ2_3的寄存器使对应GPIO引脚输出电平为低电平
    link->http://blog.51cto.com/9291927/1786139
    link->https://blog.csdn.net/lushoumin/article/details/82107715
    -12)we have known the name as GPJ2_0, GPJ2_1 and so on. How dowe know the address?(10:18)
      -GPJ2_0 is a general purpose I/O 通用输入输出 as GPIO so it can be used for various function  功能(10:31)
    -13)How do we control the GPJ2_0? (10:46)
    -14)There are two registers in GPIO (11:14)
        a)one is configuration 配置 registers 寄存器 (11:14)
          -It is used to determine the pin's 引脚 or 管脚 working mode 工作模式 (11:41)
        b)the onter is data register 数据寄存器 (11:16)
          -It is used to determine the pin's 引脚 or 管脚 voltage level 电平 (11:49)
    -15)For example we have a CPU (12:02) with a pin 引脚 or 管脚 (12:05)
      -At first, we need to have a configuration 配置 registers 寄存器 to control 控制 its status 状态 then you are able to set
      the low level 低电平 or high level voltage 高电平 via data register 数据寄存器 (12:27)
    -16)The pin 引脚 or 管脚 connected CPU and LED light 灯 (12:38). The LED light also connects to the 
    high voltage in (3.3V) (12:49)
      -I need to set the pin 引脚 or 管脚  as the 输出 (12:55) so it is in working mode 工作模式 (12:57) as the low voltage level 低电平.(13:08)
          -Therefore, we have to set the working mode  工作模式 as ouput mode 输出模式 (13:03) and output as the low voltage 低电平 so
          LED light is turned on (13:07)
      -Ouput mode 输出模式 is setted up through configuration 配置 registers 寄存器 (13:15)
      -For Low or high voltage 低电平 or 高电平, it is controlled by the data register 数据寄存器(13:22)
      -You need to restart the board after compiling
      -Use assemly(汇编) lanauage to control LED light through RS-232 and RS-242 ports 串口 (35:39)
    
-> code example (34:39)
AREA asm1test,CODE,READONLY
ENTRY
CODE 32
LED_TEST
  LDR R0,=0XE02200280;load the address of control register 控制寄存器 into R0
  LDR R1,=0X1111;set output working mode  工作模式
  STR R1,[R0]
  
  LDR R0,=0xE0200284;load the address of data register 数据寄存器 to R0
  LDR R1,=0x0;load the data of content as 0 for low level voltage 低电平 so LED can be turned on
  STR R1,[R0]
  
delay1
   LDR R4,=0XFFFFFFFF; Can't use MOV R4,#0XFFFFFFF since move can only support from 0 to 255 (a byte)
LOOP1
   SUB R4,R4,#1
   BNE LOOP1
   
   LDR R0,=0xE0200284;
   LDR R1,=0xFFFF
   STR R1,[R0]
   
delay2
   LDR R4,=0XFFFFFFFF; Can't use MOV R4,#0XFFFFFFF since move can only support from 0 to 255 (a byte)
LOOP2
   SUB R4,R4,#1
   BNE LOOP2
   
B LED_TEST
   
   
   
  
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
