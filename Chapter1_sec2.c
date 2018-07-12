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
      in R14 (6:27)
  -#4:after the function branch, the program needs to continue execue here (5:35). 
     Here it is called the return address(5:41)
  -#5:
  -LR是链接寄存器，是ARM处理器中一个有特殊用途的寄存器，当调用函数时，返回地址即PC的值被保存到LR中（mov lr,pc）。
good link 4->https://blog.csdn.net/vincent_fang/article/details/17166509
good link 5->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0211h/ch02s08s01.html



*/
