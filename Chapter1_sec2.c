/*
link->
https://www.youtube.com/watch?v=GddifYkmZsI&index=2&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS

-Coretex corresponding to instruction set architeture v7 (0:05)
-If the code developed for ARMv7, it will work for ARM Cortex M. But not vice versa (0:21)
-ARM CPU architecuter (0:43)
-If you want to know arm assembly (汇编)(0:48) or programming in arm, u have to understand how the register(寄存器) works
and cooperate. (0:53)
->In x86, what kind of registers do we have?(1:03)
  -EAX, EBX,ECX,EDX (1:14)
  -ESP, EIP
  -EFLAG (1:18)
->In ARM (1:23), there are 37 registers in side ARM (1:27)
->U need to memorize and know what does each register is doing(1:30)
->There are seven modes in ARM cpu (1:59)
  -System &User
  -FIQ=Fast interrup(快速中断)
  -Supervisor (超级管理模式)(监视模式)(2:12)
  -Abort(终止) (2:16)
  -IRQ(普通中断)(2:20)
  -undefined(未定义)(2:24)
  ->helpful linnk https://blog.csdn.net/yjzl1911/article/details/5642957
-At one time, CPU can only operate in one mode(模式)(2:35)
-If CPU is working on supervisor mode(超级管理模式), CPU can only access/read
those registers (2:46)
-helpful link for banking and unbanking->https://stackoverflow.com/questions/13432297/what-does-banking-a-register-mean
-r0 to r7 is unbanked(未分组) registered (3:09).Those eight registers can store data/value (3:16)
-r8 to r12 (3:24). They can also store value/data (3:33)
-r13 and r14(3:41).
-r13 is used as stacking pointer( 栈指针字寄存器)(SP) for storing the stack's address at the top(栈顶地址) (3:58)
  -In x86, it is named as ESP (4:21)
  -Where r13 or stack pointer opoints to relate to address of th stack (4:37)
->r14 is used as the subroutine link register(LR)(链接寄存器)
  -Keep the return address of the program for example if there is any branch occcurred (4:56)
  -Elaboration (5:24)
  -#1:
  -#2:
  -#3:func();//BL func (5:53)
      -When branch occur, the return address or PC的值(It will always point to the next one as #4)is automaticall stored (6:02)
      in R14/LR (6:27)(6:46)
  -#4:after the function branch, the program needs to continue execue here (5:35). 
     Here it is called the return address(5:41)
  -#5:
  -LR是链接寄存器，是ARM处理器中一个有特殊用途的寄存器，当调用函数时，返回地址即PC的值被保存到LR中（mov lr,pc）。
good link 4->https://blog.csdn.net/vincent_fang/article/details/17166509
good link 5->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0211h/ch02s08s01.html
->R15 a.k.a PC register(寄存器) or 程序计数器(6:50)
  -elaboration (7:22)
  -预取器(cache) (7:25) obtains the instruction set from the RAM (7:26)
  -but where it really gets from RAM is controlled by L15/PC (7:32)
  -So what does the address which PC keeps (7:45) will be executed in the program within
  RAM (7:50)
  -(7:59) When I have a branch due to function 函数 (8:04),I want to return to #4 to 
  conitnue to execute (8:09)
  -My return address in L14/LR is #4 (8:17)
  -R15 will point out to the next instructin set to execute (8:27)
  -So what you need to do is to put the content of R14/LR into R15/PC so it will
  points to #4 (9:00)
->Supervisor (超级管理模式) (9:35)
  -r0 to r12 has nothing special to (9:41) to store variables(变量) and data (数据)
  (9:44)
  -all registers are 32 bits(10:36)
  -It can also see R13(SP),R14(LR) and R15(PC),Current Program Status Register (CPSR)
  -Current Program Status Register (CPSR)(当前程序状态寄存器)(10:22)
    -It tells us what is the status of execution (10:46)
    -Refer to p31 top in arm_architecture.pdf
    -Good link->https://blog.csdn.net/wuyuzun/article/details/70332229
    -32 bit registers
    -From bit 0 to bit 4->(11:26) it tells what kind of mode(模式位) you are in(11:29)
    -There are seven modes (11:37)
    -What modes(模式) maater(11:55)?
    -In Linux there is user mode and kernel mode(12:12)
    -Such as segment error (段错误) (12:29) while accessing the kernel (12:35)
    -So how do they implement it (12:36)?
    -When user access the kernel space, there is an error and why?(12:47)
    -This is call the CPU protected mode(保护模式) (13:32)
 good link for x86 protected mode(保护模式)->https://blog.csdn.net/wrx1721267632/article/details/51941638
    -x86 has the RAIN0 to RAIN3 (13:41)
      -RAIN0->highest level of privilege(特权级) (14:12)
            ->Can access any resource in CPU(14:23)
      -RAIN3->Lowest level of privilege(特权级) (14:45)
    ->When linux kernel runs on x86, it only use RAIN0 and RAIN3 (14:48)
    ->RAIN0 for kernel and RAIN3 for user (15:02)

->Physical Memory(物理内存)
->MMU (15:40)
    -Physical memory(物理内存) to virtual memory (虚拟内存) swap 转换(15:56)
->Now if I have two processes(程序) running(16:16) as a.out and b.out (16:28)
->Each of 程序 has its own kernel space(内核空间) between 3G to 4G (16:39) and 
user space(用户空间) between 0G to 3G (17:15)
->What is inside the user space (用户空间) (17:30)?
    -stack(栈) (17:34)
    -shared library 共享庫 (17:40)
    -shared memory 共享内存 (17:42)
    -heap 堆 (17:47)
    -data
    -text (18:01)
    ->bss segment(BSS段)
    ->good link (http://www.360doc.com/content/12/0331/21/8363527_199765130.shtml)
->The code(代码) and data(数据) are all saved in user space用户空间(18:32)
->When there is a system call (系统调用), we can move to ther kernel space(内核空间) (18:33)
->If you just write a line of a code(代码) such as (18:46)
  -0xDFFF FFFF (18:59), a 32bit data (19:01)
  -(19:14) 32 bit for 4G (19:20)
  -3GB(0xC0000 0000) barrier from 0GB to 3GB in userspace(用户空间) (19:25)
  - 80000 0000=2GB since 34359738368d/1024(KB)/1024(MB)/1024(GB)
  - 40000 0000=1GB since 1073741824/1024(KB)/1024(MB)/1024(GB) (19:44)
-For 0xDFFF FFFF, should it be stored between the address of 3GB and 4GB (19:52)
-So I will do some manipuation(操作) on the 0xDFFF FFFF (20:07) as 
((unsigned int*) 0xDFFFFFFF)=0x12345678------------->(S1)
->What does it mean (20:21)?
->It means that I want to put the content into the address of 0xDFFFFFFF (21:03)
->During the execution of my ccode, if the code (代码) of (S1) occurs (21:07)
  
    
*/
