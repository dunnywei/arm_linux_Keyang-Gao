Link->https://www.bilibili.com/video/av73306160/?spm_id_from=333.788.videocard.2
link2->https://www.dalipan.com/detail/9c8f2515a2cf016438d9e9c6cc098353
嵌入式+物联网
link3 for list->https://www.yunpanjingling.com/resources/5d0e63704b3f4113b5072714
data structure->
         https://www.dalipan.com/detail/93308f654da0115a6e71e5fc8df5ce84
         https://www.dalipan.com/detail/828ce126ddc52a606516c90ac47e260b

->game engine
https://www.dalipan.com/detail/ae7e9418244bac3d2e273e80aa7c7062
search term->opengl

->Dtft and fft
https://www.youtube.com/channel/UCFJRdk0slyosSdaVlZmsM2A/videos
         -Series 1:Understanding fourier series (7:37)(21:49)(26:30)
         -Series 2:
         -Series 3:
https://www.youtube.com/watch?v=QLCXSxgxRPY
->derive of fourier transform
https://www.youtube.com/watch?v=FGjMZ1uMRrs&list=PLhSp9OSVmeyJ5N-JUEZj7uS6IAT9a79nD

->electrical engineering fourier transform
https://www.youtube.com/watch?v=KRfS_3tnKec
Electrical Engineering: Ch 19: Fourier Transform (1 of 45) What is a Fourier Transform? (done)

->fourier transform sine
https://www.youtube.com/channel/UCrltzuSvRbL3rpsvLDnFkuQ

->radar system
https://www.youtube.com/playlist?list=PLUJAYadtuizA8RC2Qk8LfmiWA56HZsk9y
https://nptel.ac.in/courses/108105154/
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
                 to copy those files into "/opt/rootfs" (11:06). Therefore system is able to run.
                          -Link for elf csdn is in the following->https://blog.csdn.net/TaylorPotter/article/details/90247231
                 -The the system is running, it will mount the "/opt/rootfs" via nfs (11:13)
                 -nfs is like shared 共享 (11:17)
                 -In ubuntu, we write/modify/compile codes in Ubuntu(Host) (11:28)
                 -While ececuting 运行 the code, it will be in the development board after putting the executable files in "/opt/rootfs" (11:36)(double check it)
                 -What we are missing in this step is buring/recording 烧录 (11:41)
                 -
        -Comparing with the FInal product, the difference is
                 -If we update the .ko or elf file(s) (11:47), we required to buring/recording 烧录 each time (11:52)
                 -It will take longer time if we need to burn after these modification (11:59) (12:07)
                 -While working in coperation, we will use burn/record everytime if the re is any update.
                 -However, it is ok to use the other way for my own study->save a lot of time (12:13)->it is called tftp+nfs mode (12:20)
                 -Use tftp to download kernel and use nfs to share the "/opt/rootfs" (12:25) via network
        -we will learn how to do it pratically next lecture (12:38)
        -
        -
        -
        -
        -
         
->p04
        -IF we want to let the system run, we need to copy the uImage and dtb file into the development
        board of DDR RAM from UBoot(host) via network (00:22)
        -We need to ensure the files of "uimage" and "dtb" files are available (00:35)
        -We are requird to config the U-BOOT since U-Boot is designed to load the "uimage" (00:41)
        -We can use either uimage or zimage in (01:21). In addition, we need to have the exynos4412-fs4412.dtb (01:26)
        -Running the development board
        -a. We use tftp to intitalize the kernel
        -1)The "uimage" with "exynos4412-fs4412.dtb" should be put into the folder of "192.168.7.21/tftpboot" in VM machine (01:33)(01:52)
                 where 192.168.7.21 is the host ip of ubuntu (03:01)
        -2)We need to config the U-Boot parameter (3:11) so it can load the linux kernel (3:24)
        -During the "auto reboot" , we will hit the keyboard (03:41), we will see the version of U-BOot,CPU info, Development board info, size of physical memory, eMMC info (4:02)
        -The most important thing is "Hit any key to stop autoboot"->we need to hit any key in the keyboard. Then we will be in the commandline (04:28)
        -The following is the procedure to set up (4:43)
                 -d->set ipaddr 192.168.7.22
                 -a->set serverip 192.168.7.21 
                 -b->"set bootcmd tftp 0x41000000 uImage\; tftp 0x42000000 exynos4412-fs4412.dtb \;bootm 0x41000000 - 0x42000000"
                 -c->"save"
                 -Description (4:43)
                 -we copy all of the chracters of "tftp........-42000000" to bootcmd (5:46)
                 -During the auoto rest while counting down, it will read the content in bootcmd (06:02)
                    -Host is the server and target is the client (06:30)
                 -" tftp 0x41000000 uImage\" is a command or action. Our uimage or linux kernel on tftp server will be downloaded to DRAM at address of 0x41000000 (06:28)
                 -"\; tftp 0x42000000 exynos4412-fs4412.dtb" where ; means coninue and the next command (6:44) so what it does do is the
                 *.dtb file will be downloaded to 0x42000000 (06:50) in RAM via tftp. "\" means to connect all of the commands together (11:32)
                 -";bootm 0x41000000 - 0x42000000" is another command for start up (启动) the kernel (07:14)
                 -THe kernel will start up (启动) at 0x41000000 (07:26).At the the same time, kernel will read *.dtb file from 0x42000000 (07:35)
                 -The "-" within "bootm 0x41000000 - 0x42000000" means RAMDISK (8:01) for preserving the space (8:11)
                 -What is the IP for the host (09:17) so we need to set up the server or host IP (09:15)
                 -"serverip" is for host ip and "ipaddr" is for client ip as 192.168.7.22 (09:31)(09:46)
                 -use "pri" or "print" to print the save stuff (11:11)
                 -After everything has been set, we can reboot the target(11:44) we will see the following  as
                  TFTP from server 192.168.7.21; our IP is 192.168.7.22
                 -The image is loaded to 0x41000000 as
                 Load address:0x41000000
                 -The dtb file is loaded as
                 Filename 'exynos4412-fs4412.dtb'
                 Load address: 0x42000000
                 -Then you will see things relate to bootm such as 
                 Loadking Kernel Image ...ok
                 Loading Device Tree to 4fff4000
                 -Don't worry about 4fff4000 since it is done in internal (12:44) it relates to 0x42000000 (12:48)
                 -You may see Kernel Panic (13:29)
                 1.595000] Kernel Panic -not syncing
                 -It is because that you need to mount "rootfs" (13:38). We need to tell the kernel how to mount the rootfs (13:50)
                 -
                 -
                 -
                 -
                 -
                 -
                 -
                 -
                 -
 
  ->p05                        -
        -We need to mount the nfs to mount the "rootfs"
                 -a)we need to have the file system of "rootfs" as file of "rootfs.tar.xz" then unzip to the unbuntu host directory (1:32) [Host]
                          of /opt/4412 (02:46)
                 -Then you will be able to see the "rootfs" as /opt/4412/rootfs (3:15) by typing
                 "tar -xvf rootfs.tar.xz -C /opt/4412/" (3:25)
                 -b)we need to configure 配置 the nfs server 服务器 (4:02) so the folder of 
                 "/opt/4412/rootfs" could be mounted (04:13) [host]
                           -nfs server required to be installed (4:30)
                          -How do we set up? (5:08)
                          -"sudo vi /etc/exports" (5:13) 
                          -
                 -Within "/etc/exports" (05:22)
                               -We need to add (5:32)
/opt/4412/rootfs *(sub_tree_check,rw,no_root_squash,async)     
                               -"*(sub_tree_check,rw,no_root_squash,async)" is the option (05:36) don't worry about hits for now
                               -This is the tool, we just need to know the steps to set up. We don't need to know why (5:59)
                               -"*" nmeans for all users (6:04)
                                   
                 -c)After everything in "/etc/exports" has been config, we need to restart the nfs service by entering the following in the target shell (ubuntu)(6:14)
 sudo service nfs-kernel-server restart             //for reboot (重啟 nfs)(6:30) [host]                           
                 -How do we know if obt could be mounted or not by entering the following in the host shell (06:35)(6:52)
sudo mount -t nfs localhost:/opt/4412/rootfs /mnt 
cd /mnt
                  -we should be able to see the follwoing direcotories as the following  (6:59)
 /bin    /dev     /etc     /lib     /linuxrc /mnt     /proc    /root    /sbin    /sys     /tmp    /usr      /var                  
                 -d)Within the target or development board, we can tell kernel to mount the "/opt/4412/rootfs" by in target shell (8:05) [target] (9:08)
set bootargs console=ttySAC2,115200 init=/linuxrc root=/dev/nfs rw nfsroot=192.168.7.21:/opt/4412/rootfs ip=192.168.7.22
save         
                 -"rw" means it the root file system can be written or write(9:09)
                 - 
                 -reboot and should see the following in the development board console
Filename 'uimage' as kernel image
VFS:Mount root (nfs filesystem) on device 0:10 as nfs      
                 -It means the mounting of nfs is OK (10:40)
                
                 -We will see the developmont board is running linux system (10:50)
                 -when we create a directory as "/drv_module" in development board,we will find pit that the same directory
                 has been created in "/opt/4412/rootfs/drv_module" under ubuntu host ->threfore they are shared in terms of directory (11:19)
                 -Type "touch abc.txt" within "/opt/4412/rootfs/drv_module" (11:29)
                 -Therefore if we create a file under "/opt/4412/rootfs/drv_module" under ubuntu (host), we can execute it within the direcotory in the development board
                  so the development time is reduced (12:35)
                 -Explaination of 
set bootargs console=ttySAC2,115200 init=/linuxrc root=/dev/nfs rw nfsroot=192.168.7.21:/opt/4412/rootfs ip=192.168.7.22

                 -bootarg->It is the argurment which uboot send to kernel for intialization  (12:56).All of them are in the type of char (13:04) 
                 -consle=ttySAC2->During the Kernel intialization, it will tell ouput configuration info from shich device (13:33)
                 -Example of kenrle configuration info is listed (13:45)
       [ 0.535000] 13810000.serial: ttySAC1 at MMIO
       [ 0.535000] 13810000.serial: ttySAC2 at MMIO
      [ 0.535000]  console [ttySAC2] enabled

                 -withoug putting "console=ttySAC2,115200", system will hangs while at "starting kernel" (14:32)
                 -
                 -
 
->p06 done
        -
        -
        -
->p07 done
        -comple dts file to dtb file so linux kernel is able to load
        -uimage=64 bytes of head + zimage (4:08)
        -dts_>device tree description file (8:07)
        -dtb->device tree binary (8:07)
        -a
        -b
        -c
->p07
        -We require to connect to nfs file system via network so we need to port network driver (0:25)
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
