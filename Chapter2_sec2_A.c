ITEC 5201 Tuesday and Thursday
IMD  4701 Tuesday and THursday
IMD  4901 Tuesday and THursday

计算机存储介质
https://www.youtube.com/watch?v=Tsyw7xqRwCE&list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo&index=7

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
        -
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
        -
        -
        -
        -
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
        -
        -
        -
        -
        -
        -
        -
        -
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
