//After (30:00)
//https://www.youtube.com/watch?v=GddifYkmZsI&index=2&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS
->RAIN3 as Non Priviledge (非特权级别) with lowest priority->(ARM) User
->RAIN0 as priviledge(特权级别) with highest priority-> (ARM) FIQ (快速中断), IRQ 普通中断
                                                            , Supervisor(超级管理模式)(监视模式)
                                                            , Abort (终止模式), Undefined(未定义指令模式),System (系统模式)
(30:09)(30:20)(30:31)(31:16)
->IF CPU is at priviledge level, it is like running at RAIN0 (31:24), it can access to any address
in the kernel space in the memory (内核内存) (31:27)
->Linux in ARM CPU, the user application (普通用户程序) is running in user mode (用户模式)(31:35). With lowest
priority level (级别最低)
 ->(31:41) When Kernel is running it is in the Supervisor mode(超级管理模式) (31:48)
  -When you want to have a system call(调用) on two procecesses (进程) (31:52), kernel (内核) 
  is running in Supervisor mode(超级管理模式) (31:56)
->Let's go back to the CPSR (程序状态寄存器) (32:30)
->GOOD reference->https://blog.csdn.net/david_luyang/article/details/6276533
->So how do we know which mode does the ARM cpu is running (32:41)?
->we will see from bit 0 to bit 4 on the right (32:41)
->T for State bit->we rarely use it (32:48)
  -It supports both ARM and THUMB instruction set (32:55)
  -So it use T to switch between thumb vs ARM (33:01) so
    T=1,ARM instruction set
    T=0, Thumb instruction set (33:15)
   -Reference for the difference between ARM and THUMB
    ->https://blog.csdn.net/itismine/article/details/4753701
->The difference between ARM and thumb instruction set is the bit width (位宽) of intruction set when CPU get the instruction
from the RAM 内存 (33:24)
->In ARM instructions set, it will get 4 bytes (字节) at once (33:31)
->In thum instruction set, it will get 2 bytes (字节) at once (33:38)
->F is for FIQ for enable (0)/disable fast interrupt (1)->(33:58)
->I is for IRQ for enable (0)/disable regular interrupt (1) 普通中断
->Bit 8 to Bit 27 is reserved 保留(34:23)
->(34:32)
->Condition code flags (条件码标志) from bit 31 to bit 28(NZCV) is really important (34:35)
->It tells the status(状态) when the program (程序) is running(运行) (34:40) 
