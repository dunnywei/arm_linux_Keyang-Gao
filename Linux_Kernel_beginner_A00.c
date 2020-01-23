Link->https://www.bilibili.com/video/av73306160/?spm_id_from=333.788.videocard.2
->Day P01
         -host->required arm-none-gcc
         -target->Need to let LINUX OS running
        -1)Power ON
        -2) bootloadder as U-Boot in binary
        -3)Kernel->zimage or uimage in binary
        -4)rootfs as file system in binary
            -bin->command
            -sbin->command
            -etc->config
            -lib
        -          
        -
        -
->Day P02
        -Require configuration of ubuntu (either on virtual machine or host) for linux device driver configuration (3:10)
                 -Copy arm-gcc-4.6.4.tar as the folder of linux_4412\toolchain within ubuntu (01:40)
                 -"Cross_tool" or "tool chain" on host (01:44)
                 -Required to unzip it by "tar -xvf *.tar ~/Linux_4412/toolchain"
                     -where ~ means the main directory (3:17) as the example in this lecture
        -Require to set the enviroment variable 
             -required to edit ~/bin/bashrc (03:44)
             -What we need to do is to add the following at the end (04:08)
export PATH=$PATH:/home/goerge/Linux_4412/toolcahin/gcc-4.6.4/bin
        -upate the patch by type the following (4:54)
source ~/.bashrc
        -Type the follwoing
arm-none-linux-gnueabi-gcc -v
        -we will see (05:11)
 Using build-in specs
 Collect_GCC=arm-none-linux-gnueabi-gcc
 COLLECT_LTO_WRAPPER=/home/george/linux_4412/toolchain/gcc-4.6.4/bin
        -after seening above, it means that our cross compiler is working
        -We need to add kernel/our modified code on the host (05:41)
        -
        -
        -
        -
        -
        -
        -
        -
->p03->tftps and nfs
        -We are setting up the tool chain for cross platform development (00:26) (交叉工具开发)
        -At the final stage, we deliver the final product in our development board
        -We will have two types of memory medias
         -DDR (1GB)(All the codes will be load in the physical memory 内存 so CPU can run)
         -eMMC (1GB)(01:20)
                 ->U-BOOT.bin (binary)->burned in
                 ->uimage
                 ->rootfs file system (2:00)
                 ->Think this as the type of NOR-Flash for saving the U-BOOT image and kernel image as described in the following link
                    -https://www.cypress.com/documentation/white-papers/comparing-nor-flash-slc-nand-emmc-and-ufs-embedded-system-booting
        -Executing, U-BOOT.bin will be loaded into DDR physical memory 内存 (2:32)
        -After U-BOOT.bin finish executing, it will load the linux kernel into the DDR physical memory 内存 (02:56)
        -The uimage will be at 0x41000000 in RAM (03:12). We could locate in other location if we need to. it is a.k.a
        kernel executing (03:24).
        -We need to mount 卦载 the rootFs file system to RAM as well (3:33)
            -What we want here is that we are able to find the bin/sbin/etc (3:45) therefore we are able to use "cp","ls" commands (3:51)
        ->U-Boot will mount both uimage and dtb file for new kernel (4:16)
         -dtb file only exist after kenel 3.0 (04:33)
         -it is the device descriptor 设备描述 (04:40)
         -It will be mounted into RAM at address of 0x42000000 (05:02)
        ->Therefore when kernel is executing, the kernel will be able to understand how many number of external configuration is available by reading it (05:16)
        -it is the device descriptor 设备描述 which will describe peripheral device 外围设备
           -Such as LCD, external keyboard, DM9000 for network card, even the I2C bus (5:49) (5:54)
           
         -final product
                    -DDR (固话) (fixed)
                          -
                          -
                          -dtb文件 at 0x42000000
                          -rootfs will be mounted here
                          -uimage as (0x41000000)
                          -U-boot
                          
                    -NandFlash/eMMC (7:03)
                           -rootfs
                           ->Uimage
                           ->U-BOOT
                           -
        -However in the development, we may use another way (6:37)
        -IMPORTANT:we will have the development board (6:48)
/**********************************start of development board (target)**************************************************/                    
                   -Has DDR
                          -Dtb file loaded from HOST
                          -UImage at 0x41000000 from HOST
                          -
                          -U-boot (it is the same 07:30) from EMMC will mount the rootfs file system
                          
                    -NandFlash/eMMC (7:03)
                           -
                           -
                           -
                           -
                           ->U-BOOT.bin
                           -
/**********************************end of development board (target)**************************************************/                    

                    -Ubuntu (Host)
                           -"/tftpboot"
                              -uimage
                              -
                              -
                           -"/opt/rootfs"
                           -
                    -
                    -
                    -
        -However, the U-image and rootfs will be different than the original one (7:34)
        -In development, we will utilize "/tftpboot" folder  (07:56)
                 -Under the "tftpboot" folder, we will have uimage and dtb file (08:04)
                 -The rootfs file system will be under "/opt/rootfs" (08:11)
                 -The reason is to mimic the same file system in DDR for the final product (8:27)
                 -U-BOOT will load the "uimage" and "dtf file system" from tftp via UDP to the developmeent board->like load VxWorks.stc to the development board (8:43)
                 -Host is regarded as server and target is regarded as client (9:01)
                 -Uimage will be load to DDR at deveopment board but U-Boot will be loaded from eMMC or NORFlash (9:13)
                 -dtb file will be loaded into DDR as well from host via tftp (9:22)
                 -It is using Linux 4101 and Linux 3200 (9:37)
                 -For developoment board , "Dtb file" and "uimage" are loaded from host. For production, both of them are loaded from eMMC(09:46)
                 -While kernel is running, it will load the "dtf" file then mount rootfts file system (10:04),therefore kernel is able to access ~/sbin, ~/sbin and ~/etc (10:11)  
                 -Now the system is running (10:16)
                 -
                 -
                 -
                 -
                 -
        -If we need to run all development board with linux->we need to run: U-BOOT,U-Image,Rootfs
                 -All of these are in binary and stored in DDR RAM (10:37)
                 -In the developoment enviroment, we did this via network in tftp
                 -The advantage of doing this:if we add more files such as .ko (driver) or elf, we only need 
                 to copy those files into "/opt/rootfs" (11:06)
                          -Link for elf isin the following->https://blog.csdn.net/TaylorPotter/article/details/90247231
                 -
                 -
        -
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
