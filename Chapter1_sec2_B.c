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
