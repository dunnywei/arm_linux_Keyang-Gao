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
->Pipeline 流水线(1:33)
  -Number of instruction set the CPU can handle (1:46). It doens't means that the instructions sets (指令) are executing at the same time (1:52)
  -It is at different stages (阶段) (1:54). 
  -For example (1:58), (2:15) When CPU want to execute an instructions set (指令), it has
  to fetch the instruction from memory (内存) (2:22)
  -the instruction set in 4 bytes 字节 is stored into cache (快速缓冲贮存区) or 预取器 of the CPU (2:27)
  -After CPU get the instruction set, it get 10101 (机器码). Thefore it requies to decode 译码 from decoder (译码器) (2:37) so it can
  determine if it is add/subtract by analyzing it.
  -Once the decoder (译码器) know what it means via decoding (2:46) such as ADD R0,R1,R2 
    -adding R1 and R2 to R0 (3:11)
  -(译码器) knows that it is an addition intruction set (指令) (3:35)
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
