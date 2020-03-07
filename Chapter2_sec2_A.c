Chinese medicine
->http://yibian.hopto.org/
->ubuntu xdrp->https://askubuntu.com/questions/234856/unable-to-do-remote-desktop-using-xrdp
ITEC 5201 Tuesday and Thursday
IMD  4701 Tuesday and THursday
IMD  4901 Tuesday and THursday



Chapter 2:计算机存储介质
https://www.youtube.com/watch?v=Tsyw7xqRwCE&list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo&index=7

Chapter 3:Linux嵌入式开发和驱动开发--3外设和bootloader
https://www.youtube.com/playlist?list=PLhqasd25bl-joEljBbhILdAJSAwprZRst
Chapter 4:Linux嵌入式开发和驱动开发--4ARM中断编程
https://www.youtube.com/playlist?list=PLhqasd25bl-ia5YgrJxOXLZ3T6njUC-uX

Chapter 5:Linux嵌入式开发和驱动开发--5kernel启动过程和kernel核心结构
https://www.youtube.com/watch?v=lC4nGPJvihY&list=PLhqasd25bl-i5E544dfYthnOcX_iv3smq

Chapter 6:Linux嵌入式开发和驱动开发--6-linux字符设备
https://www.youtube.com/watch?v=e_vX8rFWrh4&list=PLhqasd25bl-j_ELYbdQnzH__tCALKkAyN

Chapter 7:Linux嵌入式开发和驱动开发--7-linux中断
https://www.youtube.com/watch?v=38qK042lHxA&list=PLhqasd25bl-ivgl24XtKBsX6mcn8z0fJU

From other website->
https://www.bilibili.com/video/av31630936/?spm_id_from=333.788.videocard.13

others->
https://www.bilibili.com/video/av65948041/?spm_id_from=333.788.videocard.3

https://www.bilibili.com/video/av73306160/?spm_id_from=333.788.videocard.2

https://www.bilibili.com/video/av45580704/?spm_id_from=333.788.videocard.1

嵌入式之Linux并发程序设计->
https://www.bilibili.com/video/av73202565

嵌入式之Linux网络编程
https://www.bilibili.com/video/av73203918

DO178->
https://www.bilibili.com/video/av31896512?from=search&seid=9658075534689431288

freertos->
        https://www.bilibili.com/video/av24584314?from=search&seid=947590164254792850

Linux block device->
        块设备 国嵌
        http://training.eeworld.com.cn/video/4679

python and c code->
https://www.youtube.com/watch?v=-SvmjCWBX10

 PE与X86/X64汇编 从入门到改行->
         https://www.bilibili.com/video/av53352785?from=search&seid=365745999278957512
Linux嵌入式开发和驱动开发--2开发板外设驱动
Section2_计算机存储介质
->IN this section we need to know how to read hardware data sheet and chip manual 原理图 和 芯片手册(0:20)
-Goal
->1)ARM cpu architecture and assembly
->2)hardware data sheet and chip manual 原理图 和 芯片手册
->3)Understand SOC chip with configuration in UART,NandFlash,Timer and coding the device driver 驱动程序 for all of them
->4)Finish boot loader project including coding and porting (1:29)
->Once you get your develoment board (开发板), u need to answer the folloiling question (2:10)
->1)What does your chip's name and based on on which ARM kernel
        -s5pv210 (2:42)
        -link->https://item.taobao.com/item.htm?id=15592082970&ali_trackid=2:mm_14364811_3440779_59046457:1561854669_194_984915867&pvid=100_11.1.130.21_56537_7881561854648228712&scm=null
        -Using coretex-A8 (2:49)
        -210 means samsung add other external controller configuration (外设控制器) (3:07) to form s5pv210(3:12)
        -          
        -
->2)What is the main frequency of the CPU(1Ghz), what kind of main memory (DDR) it is using(128MB*4=512MB), the size of memory
->3)which OS will run in the development board? what will be the difference->Linux and Android (3:30)
->4)What is BSP (板级支持包)(3:38)? what the BSP for the dvelopment board supports for external configuration (外设)?
        -The development board has the associated boot loader and associated/portable OS (3:47) with external device driver 外围设备 (外设)驱动 (3:54)
        -So the manufacture of develoment board (开发板) must provide
        -1)bootlaoder
        -2)runnable linux os (4:32) and android os->therefore it will attract the custumers to buy it (4:36)
        -3)BSP=OS+boot loader+device driver (4:55)
        -
        -
        -
        -
->Peripheral identification (外设识别) (6:30)
        -reset key
        -key for /home ,/back,/menu
        -Input/ouput (I/O) interface
        -Network interface
        -USB interface
        -SD interface
        -camera interface
        -WIFI heasphone interface
        -AV interface
        -启动跳线->NAND-SDBOOT
        -可变电阻 as ADC
        -LCD interface:Connect to LCD externally
        -             
->Be aware of inserting/removing SD card (6:56)
->Be aware of the power supply voltage 电压. It used 5V. If we apply 110V, it will demage the board (7:39)
->Serial cable->dual female (7:57)
->Use hypertrm instead of terraterm (8:16)
->We need to see data sheet(芯片手册) and schematic diagram (原理图) (原理图 和 芯片手册) (8:47)
->Now reading the data sheet (芯片手册)->S5PV210_REV1.pdf (9:08)
        -Section 01:Overview
            -1:overview of S5P210
            -2:Size and ball map (管脚封装)
        -Section 02:System->系统
        -Section 03:Bus->总线 (9:37)
        -Section 04:interrupt->中断
        -Section 05:memory (内存)->Not only deals with memory (内存). It also deals wtih the "management of saving" (9:47) in DRAM, SRAM, Flash (9:58)
        -Section 06:DMA (Direct Memory Access)->直接存储 (10:04)
        -Section 07:Timer 定时器
        -Section 08:Connectivity storage->serial port (串口) (10:16)
        -Section 09:Multimedia 多媒体
        -Section 10:audio 音频
        -Section 11:security
        -Section 12:_etc
        -
->After u recieve the chip and want to undersstand it in quickly, we must spend time reading it (10:38)
->Hardware engineers select the developmet board, they need to understand the specification of 芯片 (CPU) (10:57),they will check the Section 01:overview. (11:02)
->In Section 01:Overview, it will cover the memory map(内存布局) (11:15) and Size and ball map (管脚封装) (11:18)
->We need to go through Chapter 1 so we will have deep undersatnding about the chip 芯片 (11:26)
->Currenlty we are focusing on Boot loader and ARM so Section 09:multimedia can be ignored (11:41)
->So  -Section 01:Overview
        -based on ARM cortec-a8
        -It supports ARM architecture V-7 指令集(12:34)
        -It supports 64bit bus 总线 architecture (12:42)
        -It support the hardware acceleration 硬件加速 for mulimedia application 多媒体 as Multi Format Codec (MFC) for encoding/decodeding MPGEG-1/2/4, H.263 and H264 and decoding
        of VC1 (12:48)(12:56)
        -S5PV210 has the external interface 接口 to external memory  外部存储(13:04)(13:08)
           -Including flash,ROM,DRAM
           -Low Power 低功耗 DDR (LPDDR) 
           -NAND-Flash-> U 盘 (13:37)->usually it is larger like 10GB (14:43)
           -NOR-Flash->Bios (14:05). It stores the bios code inside the NOR-flash (14:05)
                     ->it can also be used to save bootloader as well (14:21)
                     ->Its memory size is smaller->it is between 2MB 兆字节 to 32MB 兆字节 (14:23)
                     ->It can store bios and bootloader (14:38)
        - TFT 24bit LCD controller
        -USB 
        -Camera interface
        -UART port
        -GPIIO port
->System architecture for S5PV210 (15:39)
        -CortexA8->512KB L2 cache
            -ALU (computing unit),maximum frequency 1Ghz
        -SYSTEM perihpheral, Connectivity, Multimedia and Memory Interface are all supoorted by Samsung
        -(System peripheral)->watchdog timer,timer 
        -(Connectivity) (16:17)
           -UART
           -I2C
           -GPIO 通用IO
        -Mulitmedia->2D/3D graphics, JPEG,H263, H264
        -Memory->SRAM, Low Power DDR(LPDDR)
        -Power Management->provided by samsung 
        -All of them are connected by AHB/AXI bus 总线(17:13)(17:28)
->UART (18:03)
        -There are 4 ports 串口(18:03)
        -Rx/Tx independing 256 byte FIFO 队列 (for 缓存)(18:16)
        -Support IrDA 1.0 SIR (115.2kbps)->it is the baud rate (18:35)
        -
->GPIO is important
   -When we go out to the field,we need to configure GPIO (18:53)
   -When we show the LED light flashing yesterday, we connect LED to the GPIO pin (管脚) (19:03)
   -We can set the GPIO pin as input/ouput (19:08)
   -We can even set LOW/HIGH voltage 电平 in GPIO (19:11)
    -It has 237 pins  (管脚) (19:16) so tthey are divided into groups 组 as ports (19:24)
    -In the example of GPA1->it consits of 4 input ports (19:35)
    -In the example of GPJ0,1,2,3,4,5:35 in/out ports (19:35)
      
->In Convention (19:46)
        -Symbol R->means read only
        -Symbol W->means write only
        -R/W->Read and Write
        -RWC->Read,Write,Clear
        -RWS->Read,Write,Set
        -
        -     
->Memory map->super important (19:57)
        -all of the address showing up here is physical address 物理地址 (20:05). It is not virtual address 虚拟地址 (20:07)
        -It is a 32 bit CPU chip 芯片 so it can see all 4GB physical address 物理地址 (20:11)
        -It is the split of physical address of memory into division. Therefore from physical address 物理地址 of 0x2000 0000 
            to 0x7fff ffff is applied for DRAM1 and DRAM 2 (20:27) 
        -DRAM means 内存 (20:31)
        -The size of DRAM_1 0x4000_0000 to 0x5FFF_FFFF (1GB)
        -The size of DRAM_1 is greater than DRAM_0. DRAM_0 is from 0x2000_0000 to 0x3FFF_FFFF (512MB)(20:41)
        -IF we see the next page, we can see DRAM_0 has size of 512MB 兆字节 and DRAM_1 has the size of 1024MB=1GB (20:53)
        -The maximum is 1.5 GB for physical memory 物理内存. Not unlimited.
        -All physical address is allocated 详述 OR 分配 (21:35)
        -for v210,we have 512MB and refers to DRAM_0 
        -Yeserday we have the "Load a value then go 0x2160 0000" so we use the memory address at DRAM_0 (22:17)
        -For DRAM_1,it be applied for expansion however it is not connected yet(22:36)
        -It is used to save stack, heap,global inside phyical memory (23:17)
        
 ->For SFRS(special function register特殊功能寄存器) from 0xE000_0000 to 0xFFFF_FFF (22:46)
        -It is used to save the all register          
        -it refers to "control register" 控制寄存器 and "data register" 数据寄存器. This is what we have done yesterday in Chapter1_sec5_A.c (22:58) 
        -We used the physial address of "0xE020 8000" (23:09)
        -(23:17)
    
 ->IROM (23:34)
        -IROM from 0xD0000_0000 to 0xCFFF_FFFF (64KB)
        -Read ONLY Memory
        -
->IRAM
        -IRAM from 0xD002_00000 to 0xD003_7FFFF (96KB)
        -Read/Write memory (24:01)
        -
->From (23:55), we know that it has 96KB RAM and 64KB ROM for Multi layer AHB/AXI bus
->It means that Multi layer AHB/AXI bus has physicl memory 内存 (24:06) 
        -96 KB RAM and 64KB ROM are super important for Boot loader (24:13) witin CPU (24:21) 在CPU内部
        -
->Pin assignment 引脚分配/芯片封装 (24:43)
        -It is used for hardware engineer (24:43)
        -How many points(balls)->584 点 (24:58)
        -For hardware engineer, under which row and wich column, it will specifiy which pins 引脚 value and what is it useful (25:11)
        -The manual should be applied on what you are searching for. It shouldn't be like novel for reading from top to buttom (25:55)
        -Like KP_COL[0]->we don't need to know what it is useful and what value it is (26:06). It is for the hardware engineer to make the PCB(26:14)(??)
        -After going through the overview (26:42),we are at the system (26:48)
        -
->Now we are at Section 02_system 
        -It is dealing with GPIO (26:53)
        -
        -
        -
        -          
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
->Section 2_3_Clock Controller
        -It deals with 时钟 (27:12)(27:19)
->Section 2_4:Boot sequence      
        -If we have time, we will cover it(27:31)
        -
        -
        -
        -
        -
        -
        -
        -
->We need to know the store (存储) in CPU (27:41)
        -What will affect the CPU performance with process? (28:15)
        -Usually it deals with I/O operation 输入输出操作(28:27)
        -Which read/write is the most fast?
           -read/write physcial memory 内存(faster)
           -read/wrie  hard drive (硬盘) (28:34)  
        -Whilesaving datato DataBase->everything is saved within hard drive (硬盘) (28:41)
        -cache(高速缓冲存储器是存在于主存)(28:49)
        https://blog.csdn.net/baidu_35679960/article/details/78610804
https://blog.csdn.net/guyongqiangx/article/details/52045849
https://blog.csdn.net/politefish/article/details/5594741
        -physical memory database  物理内存数据库 is applied in baidu (28:49) with size in terabyte 万亿字节 (28:52)
        -All data is saved in the physical memory (物理内存).During the data search between physical memory 内存 vs hard drive (硬盘) (29:04)
        -It will be faster to search in physical memory 内存 than hard drive (29:10) so IO operation 输入输出操作 will affect CPU performance (29:12)
->What will affect the porformance of IO operation 输入输出操作 the speed of the medium interface (介质)(29:17)       
        -We should know which media 介质 is faster/slower (29:20)
        -We can use a pyramid to describe it (29:49)
        -For the top->fastest, more expensive,smaller in storage size during operation (29:56)
       
        -
        -
        -
        -
        -
        -
        -
        -  
->-|_|-|_|-|_|-|_|
             |Rising and wave up
           |falling then wave down
           
->Top of the list   
->1)Register 寄存器,  CPU triggerer  (1 ns)
  -Its speed is really simliar to CPU for each instruction set(30:55)
  -ARM has 37 registers 寄存器 (31:09)          
  -Really fast but most expensive (31:12)
  -触发器 (32:27)
  -
  -
  -
  -
  -
  -
  -              
->2)Cache缓存(31:28), SRAM, 随机静态存储器(Static Random-Access Memory) (10ns), 
  -Fast as well (32:08)
  -explains:
  -https://blog.csdn.net/lvjianxin6015/article/details/53994641
  -ROM,SRAM,RAM,DRAM explaination
  -https://blog.csdn.net/u011403063/article/details/79536547 (important)
  -
  -
  -
           -
  -
  -
  -
  -
  -
  -     
 ->3)physical memory 内存 (32:57): DRAM 随机动态存储器 (Dynamic Random-Access Memory (33:20)(33:25) as 100ms ,
 ->SRAM,DDRAM,电容表显示( capacitor gauge display)  telling u when you should recharge your battery,refresh刷新
  -In PC, the interface is a.k.a DRAM. 
  -In Development board, it is a.k.a as SRAM
  -both of the mare based on DRAM interface (33:04)
  -The difference between Dynamic and Static
  - DRAM->dynamic crystal tube 动态晶体管 (33:40)
  -In DRAM, for one bit 比特位 place, it requires to have one 晶体管 and power 电源 (5V or 3.3V or 12V ) (33:47)
  -What is the special charaters about the 电容 (capacitor)? (33:52) 
        -The store cahrge will be lost after certain duration so we require to keep charging it (34:07) 
        -After capacitor has been charged. One or 1 represents that it has been charged. Zero or 1 represents 
        that it has been discharged (34:15)
        -We need to recharge it the charged capacitor drop around 70% (34:43)
        -
        -
        -
  -SDRAM and DDRAM 随机动态存储器->it requires to recharge afte fixed duration of time(35:16) or refresh刷新
                                              -需要在固定时间后重新充电
  -SRAM 静态随机存取存储器->it doesn't need to charge regularly (35:21)
      -No 電流 (circuitry) but with 晶體管 (transistor) (35:27)
  -晶體管 (transistor) is made up silicon 硅 (35:27)
  -The cost of having six transtitors 晶體管 is greather than the one having one transistor 晶體管 (36:02)
     -Defintely, the one with six transistors has higher performance (36:04)
  -Ususally we use SDRAM and DDRAM for our physical memory (内存)(36:11)
  -For example in DRAM (36:21)
        -In timing diagram, (36:50)
-|_|-|_|-|_|-|_|
 a   b
        -For SDRAM in one cycle from a to b (37:04)
        -0 to 1->rising edge 上升
        -1 (高电平) to 0 (低电平)->falling edge 下降沿 (37:54)
        ->- is high as crest(波峰) and _ is low as trough (波谷) (37:20) (37:42)
        -
  -In SDRAM, within on period-> it only can have one read then write data once (38:05)(38:10)
  -  
->Hard drive 硬盘
        -Nor flash   ,Intel , small in storage size, 2MB to 32MG, save bios/bootloader 
        -NAND flash,Toshibal, large in storage size,1GB to 256GB,it acts as if it is a hard drive 硬盘
-
        -DDRAM->D(Double)DRAM->It can do read/write from 0 to 1 (rising edge) or 1 to 0 (falling edge) within one period(38:15).Therefore read/write can be done twice within a period (38:32) 
        -Without changing the frequency requirement, the speed of writing SDRAM vs DDRAM is 1:2
        -
        -
        -          
       
->Network Drive OR cloud 网络硬盘
        -ROM
        -
        -
        -
        -
        -
        -
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
        -
        -
        -
        -
        -          
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -          
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -          
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -          
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -
        -    
