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
            -What we want here is that we are able to find the bin/sbin/etc (3:45) therefore we are able to copy (3:51)
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
