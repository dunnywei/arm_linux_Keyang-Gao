Linux嵌入式开发和驱动开发--1ARM体系结构和汇
4 ARM汇编指令详解
link->https://www.youtube.com/watch?v=4qziMvvMCjo&index=4&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS

->(39:51)
->ORR (Or 或 bitwise operator) (40:05)
->EOR (异或EOR) (40:14)
  -link->https://blog.csdn.net/decisiveness/article/details/46312607
  Exlusive OR->1 EOR 1=0, 0 EOR 0=0,1 EOR 0=1 (40:27)
  -eg
AREA asm1test,CODE,READONLY
   ENTRY
AAA
   MOV R0, #0X1
   MOV R1, R0
   MOV R2, #0X2
   
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0
   
   MVN R5,#0X0 ;
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
   OR  

   B .
   END
->In embedded Software Development, Bitwise operator 位操作 (40:15) is a mandatory requirement (41:12)
     -In application development, they don't use a lot of bitwise operation 位运算 (41:24)
     -The good application programmer may use the bitwise operation 位运算 (41:27) since it can reduce the
     resource requiremnt in the memory (41:30)
     -In embedded software development, there are a lot of bitwise operation 位运算 required (41:34)
     -You will set 1/0 in the register 寄存器 (41:40) or physical memory (内存) in large bitwise operation 位运算 (41:41)
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

