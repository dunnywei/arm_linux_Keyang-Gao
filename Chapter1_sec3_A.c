->3 ARM汇编指令构造格式

//https://www.youtube.com/watch?v=Xi3ioi1213k&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS&index=3
->(0:00)
->We have to be familiar with ARM registers especailly ,r13 (SP), r14 (LR) and CPSR (0:21)
->(0:36) 工作模式 CPSR's lowest five bits on the right (0:36) as link
  https://blog.csdn.net/david_luyang/article/details/6276533
  -10000 USER
  -10001 FIQ
  -10011 SUPERVISOR
->USER and SUPERVISOR are the most common one (0:45)
->Little Endian (小端模式) and Big Endian (大端模式) (0:49)
->little endian-store lowest byte in lowest address (0:52). ARM uses little endian.
->PowerPC uses big endian (1:21)
->CPU instructin cycle->fetch (取指), decode(译码) ,execute (执行) (1:29)
    link->https://bbs.ichunqiu.com/thread-40493-1-1.html?from=csdn
->CPU Pipeline 流水线(1:33)
  -Number of instruction set (指令) the CPU can handle (1:46). It doens't means that the instructions sets (指令) are executing at the same time (1:52)
  -It is at different stages (阶段) (1:54). 
  -For example (1:58), (2:15) When CPU want to execute an instructions set (指令), it has
  to fetch the instruction from memory (内存) (2:22)
  -the instruction set in 4 bytes 字节 is stored into cache (快速缓冲贮存区) or 预取器 of the CPU (2:27)
  -After CPU get the instruction set, it get 10101 (机器码). Thefore it requies to decode 译码 from decoder (译码器) (2:37) so it can
  determine if it is add/subtract by analyzing it.
  -Once the decoder (译码器) know what it means via decoding (2:46) such as ADD R0,R1,R2 
    -adding R1 and R2 to R0 (3:11)
  -decoder(译码器) knows that there is an addition intruction set (指令) (3:35) and registers (including r0,r1 and r12) for doing
  this operation (3:28) and know adding R1 and R2 to R0 (3:30)
  -Therefore, decoder(译码器) will notify the registers module (寄存器模块) to put R2 and R1 as input 输入端 to ALU (3:47) 
    through controller (控制器)
  -There is a connection channel ( 连接通道) between ALU module and register module. Therefore R1 and R2 are passed through
  the channel to ALU module. (3:59)
  -So ALU will do the calculating/operation (运算) and write back (回写) to (4:13)  寄存器 module (4:24)
  -Therefore R0 will be set to recieve/collect 接收 the result of R1 and R2 (4:34)
  -We can split the process into 3 steps/stages (阶段) (4:39)
    -The first is called fetch (预取指令) (4:42)->Put the instruction set (指令) into CPU (5:01)
    -The second is called decoding (译码) (5:05)->Analyze the instruction set to see what it want to do for the registers(5:10)
    -The third is called executing (执行) (5:13)->To perform the operation (操作) (5:17)
      -link1->https://blog.csdn.net/haoge921026/article/details/46686367
      -link2->https://blog.csdn.net/sc_stanley/article/details/39434783
    -Therefore, the ARM CPU has three pipelines (流水线 ) (5:22)
    -The execution 执行 of instructin set is compelted (完成) (5:25) through 3 pipelines (流水线)
    -The assembly line (流水线) for cars (5:35), each worker is only responsible for its module (5:40)
    -These three stages won't be interfeenced (干扰) with each other(6:02)
    -When you fetch 预取 one instruction set 指令 into the CPU (6:07).
    -If each stage in fetch (预取指令), decoding (译码), executing (执行) takes 1 clock cycle (时钟周期)
     (6:22), 
    -Where the clock cycle(时钟周期)=1s/frequency (秒/频率) (6:39) so 1Ghz CPU=1ns 
    -If each stage in fetch (预取指令), decoding (译码), executing (执行) takes 1 clock cycle (时钟周期)
     , so it will take 3 clock cycle (7:48) =3ns 纳秒 (7:53)
    -For one instruction takes at least 3ns (7:56)
    -For the 1st instruction set, it is in the second starge of decoding (译码)  (8:03)
    -Therefore the 1st starge of fetching is empty (空闲的). It can fetch 预取 the 
    second instructin set(指令) 
    -At 1st clock cycle (时钟周期) (8:17), 1st instruction set 指令 is fetched预取 into CPU. (8:19)
    -At 2nd clock cycle (时钟周期) (8:20), 2nd instruction set 指令is fetched预取 into CPU  (8:27)
                                           1st instruction set 指令 is decode (译码) in CPU
    -At 3rd clock cycle (时钟周期) (8:30),  3rd instruction set is fetched预取 into CPU  (8:40)
                                           2nd instruction set is decode (译码) in CPU
                                           1st instruction set is execution (执行) in CPU
    -At 3rd clock cycle (时钟周期), CPU has 3 instruction sets (指令) in total (8:48). However 
    these three instructions are in 3 different pipelines (流水线) modules模块 (8:51) and they don't interference(干扰) 
    wtih each other (8:56)
    -In the stage of executing (执行), there is only one instruction set 指令 being executed (9:02)
    -It is called CPU piepeline 流水线 (9:05)
    -Each instruction set 指令 takes 3ns to complete (完成) but (9:18)
    -Within one second, how many instructions sets (指令) can be executed (执行) (9:29)?
    -10^9 instructions sets (指令) (9:37) within one second (9:48)(10:06)
    -Why don't we divide 10^9 with 3? (10:10)
    -Even though one instruction set (指令) requires 3ns (纳秒) to complete (10:15), there are
    three instruction sets (指令) at each 1ns (纳秒) (10:23). Therefore putting ns (纳秒) to one second (秒) (10:27) as
    微观 (Microscopic view)(10:27) , since the difference between one second and one nanoseconds are too large.
    -Therfore, in one second, CPU can execute 10^9 -3 or -2 instructin set (指令) (10:36) apprximately (10:46)
    -In one second, one instruction set takes 1ns (指令) in 宏观 (Macroscopic view) (10:54)
    -In reality, each instruction set takes 3ns to complete since there are 
    three stages/pipelines during the CPU execution cycle (11:00)
->Currenlty, there are more stages (5/7/9/10) in CPU pipelines (流水线) than 3 stages pipelines (流水线). But 3 stages pipelines (流水线)
is the most fundamental among others (11:15) (11:21)
->How do they evolve (演化) into (5/7/9/10) in CPU pipelines (流水线) (11:24)
->In my decode 译码 stage, I refine(细化) it into two more stages CPU pipeline(流水线)(11:30). 
->For cache (快速缓冲贮存区) or 预取器, I also refine 细化 it into two more stages CPU pipeline(流水线) 
  (连接通道 or 连接线) (11:32), 5 , 9, 11 more stages CPU pipeline(流水线)(11:41)
  -link->https://en.wikipedia.org/wiki/Instruction_cycle
->Therefore 5,7,9 and 11 CPU pipleine (流水线) are all based on 3 CPU pipeline(流水线)
(11:47) due to refining (细化)(11:58)
->Refining (细化) has pros and cons for CPU pipeline(流水线) (12:00)
  -Pros
    -We can make the frequency of CPU becomes higher (12:07)
  -Cons
    -It may take a longer time to execute (执行) instructin set (指令)->so slower (12:16)
  -When we have the higher frequnecy (频率) in CPU (12:21), we can execute more instruction set (指令) at any given time (12:23)
  -The performance of CPU is moving up (12:26)
  -
->Thumb state general register (Thumb状态寄存器)  and program counter (13:01)
  -It is a 16 bit instructin set (16位指令集) so what registers(寄存器) it can see are reduced (13:08)
  -It can only read R0 to R7, R13,R14,R15, CPSR,SPSR registers (寄存器) (13:10) (13:19)
-> The format of assembly code (汇编指令构造格式) (13:43)
  -The instruction set in ARM is fixed in 32bit (位) (13:59)
  -Cond opt 分类码 s Rd(desination) Rn(From) 立即数 (14:18)
  -English link->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0204j/Cihcdbca.html
  -eg MOV R0, #0X1
    -(14:25) MOV is a 传输数据 (sending data) with #0X1 as a 立即数 (immediate number)
    -MOV #0X1 as a 立即数 or 数字 to R0 register (寄存器)  (14:39)
    -#0X1 means it is in hex mode (十六进制) (14:48)
    -In fornt of 立即数 (immediate number), you must add # (井號) or (hash symbol) (14:55)
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
