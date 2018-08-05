ARM books in chinese->
  https://books.google.ca/books?id=TH0nDwAAQBAJ&pg=PA39&lpg=PA39&dq=FIQ%2Br8%2B%E7%8B%AC%E7%AB%8B&source=bl&ots=2MVajLGNrV&sig=aqX9Fo1Vb9T32U_xPmzP9Fxzbck&hl=en&sa=X&ved=2ahUKEwiLtLCuz9TcAhWbn4MKHfX3B38Q6AEwA3oECAcQAQ#v=onepage&q=FIQ%2Br8%2B%E7%8B%AC%E7%AB%8B&f=false

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
->For example, the ALU (算术逻辑单元) can do add(加法), sub(减法), shift (移位) arithmatic operation(运算) (35:09)
->If I have A and B operating variables (操作变量) (35:28)
->Multiplication and division can be considered as shift(35:54)
  -If you shift(移位) left by one bit, it means multiply by 2 (36:01)
  -If you shift(移位) right by one bit, it means divide by 2 (36:01)
->If I want to operate A and B as variables (操作变量) or registers (36:20) to do the add (加法) operation then
put the reslult in D (36:25), C=A+B;
->A,B and D are all registers(寄存器) with 32bit (位) (36:29)
->We will have CPSR (程序状态寄存器) (36:45)
->If two 32bit registeres (寄存器) are added together, we may have overflow (溢出) or carry 进位 (36:51)
->GOOD URL=https://blog.csdn.net/nanfangqiulin/article/details/51122718 and
https://blog.csdn.net/xiaobai00014/article/details/4589057
-> overflow (溢出) when all 1's in both A and B adding together so there is addition 1 in bit 33 (37:00)
  -Therefore, there is a carry (37:12)
  -It will show up in CPSR (程序状态寄存器) as (37:15) C flag (标志) in CPSR(37:17)
  -During addition and cause carry then flag (标志) C=1 in CPSR (37:23), then the register D still maintain
  32 bit (位) (37:40)
  -When there is a overflow (37:51) will be displayed as flag (标志) V in CPSR (程序状态寄存器) (37:51)
  -overfolow vs carry 溢出和进位的区别
    -signed (有符类型) integer 
  link1->https://blog.csdn.net/LDWJ2016/article/details/52586872
  link2 with example ->https://blog.csdn.net/yelbosh/article/details/8208983
->Expalinatin of overvlow 溢出 (38:01)
  -eg, adding two numbers together (38:57)
  -(39:00)
  -Carry(39:35)
        -eg  1000 0101 as register A
            +1100 0000 as register B
 Result->  1|0100 0101 NOTE:the 1st bit on the most left deosn't exist(41:16) due to 8bits width 
           therefore flags (标志) C=1, (标志) V=1 (42:12)(require to go over)
->CPU doesn't know if variable is defined as int (integer) in C lanquage (42:23) 
->If A and B are unsigned int, it only need to consider C flag (标志) in CPSR (程序状态寄存器) (42:39) as Carry(进位)
->if A and B are defined as int, it means signed int. (42:49)
  -so A and B are both -ve (42:53) so after adding them together, we should have a -ve
  number(42:59)
  -but the result is 0100 0101 so we have to check the V flag (标志) in CPSR (程序状态寄存器) as overfolow(溢出)
->This concept is really important and get confused easily (43:37)
->Let's move on to the flag (标志) Z in CPSR(程序状态寄存器) (43:46)
  -it check if it is zero零 or not (43:51)
  -for example if A=0x0000 and B=0x0000
    -by adding them together, we will get flag (标志) C=0 so flag (标志) Z=1 in CPSR (程序状态寄存器) will be set(43:56)
    -or A=1d and b=-1d then add them together flag (标志) C=0 so(44:01) Z=1 in CPSR (程序状态寄存器)(44:10)
    -Why do we need?
    -In C lanuage (44:18)
      if(A==3) //A is register
      //more command 1
        
      else
      //more command 2
    -After the program is compiled into assemlby (汇编), it is done by "if(A-3)==0" (44:38)
      -so if A-3=0, then left is equal to the right as ==0 (4:45) 
    -Then flag(标志) Z=1 in CPSR (程序状态寄存器) (44:49)
    -In C lanquage, if the condition is met as "if(A==3)", we will continue to execute as line 81.
    -In assembly(汇编), once the Z=1 or set, the program will jump to some other address in Code Segment to
    continue executing (45:15)
     -In assembly(汇编), once Z!=1, it will jump to another address in Code Segment to conitue executing
     (45:17)
->There is another flag (标志) as N in CPSR (程序状态寄存器) (45:26)
->N is used as 符号位 eg 有符号 signed integer (45:32) to check if the result of D register is +ve(正)/-ve (负)
value (值) (45:38)
  -It means that it keep the highest bit (最高位) of result Register D after adding A and B together (45:45)
->1's complement=反码
->2's complement=补码
->反码, 补码 link->http://www.cnblogs.com/zhangziqiu/archive/2011/03/30/ComputerCode.html
->good exlanatin for Flag N(标志) in CPSR (程序状态寄存器))
------------------------------------------------------------------------------------------------------------
->In x86, we will use eflag register (46:06)
  good link for eflag->https://blog.csdn.net/jn1158359135/article/details/7761011
-------------------------------------------------------------------------------------
->In Supervisor Mode (超级管理模式), Kernel is running in 3GB to 4GB (46:37).
->Common user(普通用户) can only see (46:47) r0 to r15 and CPSR
->Linux kernel apply the supervisor Mode (超级管理模式) so it can see r0 to r15, CPSR and SPSR(程序状态保存寄存器) (46:54)
  ->SPSR(程序状态保存寄存器) link->https://blog.csdn.net/jamestaosh/article/details/4369213
->SPSR(程序状态保存寄存器)->It is used for backing up(备份) (47:00) CPSR (47:11)
->ARM has 37 registers (47:16) and 7 modes (模式). Within the 7 modes (模式), it will
able to see and access ,r0 to r15, CPSR and SPSR registers (寄存器) (47:24) so kernel
can access and see 18 registers at maximum. (47:26)
->If you are in different mode (模式), the number of registers(寄存器) you can 
see can vary (47:36) 
->If every mode (模式) can see 18 registers, we are going to have 7x18 registers(寄存器)
due to 7 modes (模式). However, it is not true since some registers(寄存器) are shared (共用). (47:39)(47:52)
->For example, registers(寄存器) of r0 to r7 are shares 共用 in all 7 modes (模式) (48:03)
->registers(寄存器) of r8 to r12, under the mode of(模式) FIQ (快速中断), they are independent(独立)
(48:15)
->FIQ (快速中断) and r8
  linkds for FIQ and IRQ->https://blog.csdn.net/dasheng_604/article/details/5976460
->There is a triangle print (三角印) on the manual means (48:17) this register is independent 独立
and not shared (共用) with others (48:19) (48:21)
->In System 系统模式 and User mode (用户模式) they share (共用) r8 to r12 (48:30) with , Supervisor mode,
Abort, IRQ and Undefined Mode (模式)
->Except system 系统模式 and User mode (用户模式), rest of them have their independent r13 and r14 
regusters (寄存器) (48:41) so you will see sth like r8_fiq,r13_fiq, r13_svc,r13_abt,r13_irq, r13_und 
->In System 系统模式 and User mode (用户模式), u will only see r8,r11 without anything following (没任何跟的)
  like previous one in line 126 (48:46)  
->ARM汇编之寄存器
  link->http://blog.51cto.com/tigerjibo/1276155
->r13 is called 堆栈指针(SP) (48:51)  
->r14 is called (LR) as 链接寄存器(LR) (48:56)
->more detailed explaination in r14 链接寄存器(LR)
  link1 as https://blog.csdn.net/qianlong4526888/article/details/7771555
  link2 as https://blog.csdn.net/Aguangg_6655_la/article/details/53613270
  link3 as https://stackoverflow.com/questions/29157427/stmfd-ldmfd-not-restoring-register-values
->r15 as 程序寄存器 (48:58)
->r13 and r14 have their own/independent stack(栈) and return address (返回地址) for FIQ, Supervior, Abort, IRQ and Undefined modes(模式) (49:11)  
->User mode (用户模式) share (共用) with system modes
->r15 is shared (共用) in all modes (49:32)(49:37)
->So what does it mean? At one time (在同一时间 ), there is only one mode (模式)  executing or working (49:48)(49:50)
->There is only ONE CPSR for all modes (模式) (49:55) for sharing (共用) 
->SPSR has is independent for SPSR_fiq, SPSR_svc, SPSR_abt, SPSR_irq, SPSR_und 
->so r0 to r7=8 for all
-r8 to r12=5 + 5 for FIQ mode
->r13 and r14=2*6(user/system+others mode)
->CPSR=1
->SPSR=5  
->PC=1
->so total, we have 37 registers (50:17)(50:58)
->In this 7 modes (模式),
->普通应用程序 is working uner the user mode (用户模式) (51:23) eg using qq, play games.
->When there is a system call (51:36) or process context switch (进程切换) (51:37), the working/executing mode (工作模式 ) will swich from
user/system mode as CPSR to CPSR_svc since the  suerpvisor mode is in (特权模式)(51:41)(51:44)
->Therefore it has its own/indepnedent  r_13_svc, r_14_svc and SPSR_svc (51:48)
->While you are playing games on the phone, a phone rings (51:53), it is an interrupt (中断) to the game. (51:56) The the executing
mode will switch from USER mode to the mode of (模式) (52:00) IQ (快速中断) or IRQ 普通中断 (52:06)
->Most of time, it will be in IRQ. (52:09)
->FIQ is usually for duplication of data (52:14) eg. copying a movie to your phone (52:14) so CPU will enter
the mode of FIQ (52:18)
->Abort mode (模式) for 数据中止(data abort) or 指令中止(instruction abort). It  occurs when 
the program running has a bug (53:43) since it want to access the kernel mode address (52:38) or
want to obtain the empty data at address of 0x8000 (52:43). Therefore CPU will enter ABORT mode (52:50)
->It causes exception (异常) so you need to have the code to deal with this issue (异常处理) (52:57)
->Undefine mode occurs when CPU execute the intruction set (指令) which is illegal(非法) (53:05) so CPU will enter the
undefined mode (53:08). Therefore we will have exception and we need to do exceptoin handling (异常处理) (Not clear in audio) (53:16)
->CPU may reboot/shut down/go back to the program to continue execute (53:17)(53:20)
->Most of time, CPU is in User (Most application running) and Suerpvisor
(where kernel is running) Mode (53:26).If there is an interrupt, we will go to IRQ or FIQ mode.
->
->
->
->
  
