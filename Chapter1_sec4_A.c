Linux嵌入式开发和驱动开发--1ARM体系结构和汇
4 ARM汇编指令详解
link->https://www.youtube.com/watch?v=4qziMvvMCjo&index=4&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS
->MOV
  -Instruction(指令) for data transfer 数据传输 (0:14)
  -
->We should introduce the development  enviroment (开发环境) before introducing the instruction set 指令集 (0:36)
  -ADS 1.2 (1:04)
    -Really important about isntall directory (2:22)
    -Need to install in "C:\Program Files\ARM\" as 64 bit (3:03)
    -Install license (4:53)
    -*.asf is the executable file in arm (11:05)
    -ADS 1.2 helps us to learn the ARM assemly in the easy way (12:05)
    -It lists the CPU state as 
      -Current (当前)
        -CPSR determine the current state (当前) by the lowest 5 bits (12:39) from M4 to M0, Link->https://blog.csdn.net/david_luyang/article/details/6276533
        -the values (值) of r0 to r15, CPSR and SPSR are shown (12:48)(12:53) 
        -The highlighted as red menas the change of register (13:04)
    -How to create the aseembly 汇编 file? (13:28) 
          -Could I have many unrelated(没有关系 or 不相关) files inside one projected (13:39)?
          -It will cause the code segment's size becomes bigger (14:12)
          -If those unrelated files has the same function such as "void m()"(14:19), then the "void m()" 
            will be defined multiple times (多次定义) or (多重定义) (14:21)
          -Therefore inside one project, don't put things are unrelated(不相关) files (14:27)
          -assemlby (汇编) code is named as "*.s" (14:52)
          -start writing assemlby cde (汇编) (15:34)
          -https://blog.csdn.net/renlonggg/article/details/55803742
->Now wa are going to the MOV instruction (指令) (16:14)
  -can be either "MOV" or "mov" BUT NOT "moV" (16:26)
  -MOV R0, #0X1
     -If justtype this as the following since there is certain format (格式) to follow (17:08)
      MOV R0, #0X1    
     -Folow the guideline (17:38) and type as following
          AREA asm1test,CODE,READONLY
          ENTRY
          CODE32
      AAA
          MOV R0, #0X1
          MOV R1, R0
          MOV R2, #0X2
          ADD R3,R1,R2
          SUB R4,R3,R1
          END
          MOV R0, #0X2

     -(17:53)(19:06)(26:04)
     -"Code" means 代码段(18:01)
     -"Area" asm1test means the name of this segment is as "asm1test" (18:05)
     -"ENTRY" 入口(18:18) like the main() in C lanquage (18:23)
     -"CODE32" means 32bit 位 (18:30).If you didn't write, the default 默认 is 32bit位 (18:38)
     -"AAA" is used as a label 标号 (18:52). It is like a function name and can be named differently (18:58)
     -label 标号 (19:08) is used as related address (入口地址) of (19:14) "MOV R0, #0X1" (19:21)
     -With "END" (19:37) as fake instruction 伪指令 (19:48). 
     - fake instruction 伪指令 is not the offical instruction( 指令) sot it won't translate into machine code 机器码. For example the "MOV R0, #0X1"
          will have its corresponding machine code. "AREA asm1test" won't have it. 
     -fake instruction 伪指令 is to let the COMPILER/IDE to read/understand (19:59)
     -if I have "MOV R0, #0X2" after "END". It won't execute (20:09)
     -In the Debug mode (调试模式) (20:51)
     -Step in->going into the function (函数) (21:35)
     -Step->means when see the function(函数), it will finish the execution of the function (21:41)
-> For the following example
      AREA asm1test,CODE,READONLY
          ENTRY
          CODE32
      AAA
          MOV R0, #0X1
          END
      -r0 will be 0x00000001 (21:47)
      -PC will be point to the next intruction to exectue as 0x00006004 (21:57)
      -CPSR register,  (22:15) nzcvqIET_SVC
        -when nzcv is in lower case->0 (22:15) OR when nzcv is in UPPER case->1 (22:17)
      -U can also change the mode of ARM CPU mode eg. Supervisor, System/User (22:32)
      -You can restart the entire debug process by clicking "reload image" (22:48)
      -Q:IN our example, we only have on instruction (指令). After it is done, What will CPU do? (23:00)
      -A: ARM processor raised an exception cause "undefeined (未定义) instruction (指令)" (23:21). Therefore what has been stored in 内存
          maay not be a defined (legal 合法) ARM instruction (指令) (23:31)
        -We only have one but it has more than one (23:37)
      -IN assmelby during memory copy, CPU doesn't know wheer to execute next (23:55). 
        It is a.k.a CPU 跑飞 or a.k.a 程序运行跑飞现象 (23:47) 
                                                                  link->https://blog.csdn.net/Echo_Ana/article/details/52559738
                                                   zynq 程序跑飞原因分析->https://blog.csdn.net/renlonggg/article/details/55803742
      -In C, can 跑飞 occur (23:58)? when programming the C code under any OS, 跑飞 won't occur (24:04). While execution by double clicking in  OS,
        it will create a process 进程 by invoking fork() (24:13). EXVC 执行 this process 进程 (24:14). Wait() recycle (回收) the process 进程.(24:15)
        After this process 进程 finish executing
        its tasks (24:17), OS will take control (接管) of the CPU for continuing to operate 运转 (24:21)
      -However, when I just execute the assemlby code with one instruction without consider the 
        concept of OS (操作系统概念) (24:28),  跑飞 can occur. The reason is that after CPU finish 
        the execution  (eg MOV R0, #0X1), CPU will continue to execute. However  
        which instruction (指令) CPU will execute next is unknown (24:34)
      -THE OS conscept is the larnge energy(大能量) endless loop (死循环) (24:39)(24:51)
      -
->(25:32)          
 AREA asm1test,CODE,READONLY
   ENTRY
AAA
   MOV R0, #0X1
   MOV R1, R0
   MOV R2, #0X2
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0 
   B .
   END
  
  -(27:16) Go to debug mode and see
  -B is the branch (跳转) and dot (.) means the current instruction address 当前指令地址 (27:33) 
     -Therefore it will keep branching at this address (不动.原地跳转) (27:56)
  -Be aware of "SUBS R0,R0,R0" (29:29)
     -DUE to "SUBS", the assciated 相关 flags 标志位 will be set (29:41)
     -so Z and C in CPSR will be in UPPER CASE (29:51)
     -Z is due to zero occurs (29:58) so it is set as 1
     -(30:03) C occurs when thee is no 借位(borrow) during the subtraction, it will be set to 1 (30:13)
     -If there is 借位(borrow), it will be set to 0. It is vice versa w.r.t "ADDS" (30:17)
     -If I use "B AAA" instead of "B .", it means that I wil branch to line 96 and continue to execute (30:51)
->MVN (数据取反传输)(31:09) link-> https://blog.csdn.net/shift_f/article/details/3339741
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
   
   B .
   END
  -"MVN R5,#0X0" (31:22) result is 
0000 0000 0000 0000 0000 0000 0000 0000
1111 1111 1111 1111 1111 1111 1111 1111 (取反 inverse)
   F   F     F    F    F    F    F    F  
   -(31:58) 
->ADC add with carry (32:09)
     -We don't use a lot (32:22)
     -In C lanquage, long long occupies 8 bytes (字节) maximum (32:46)
long a,b,c
     -If I want to do the 64bit addition in ARM, what should I do (33:10)
   a              b  
R1   R0         R3   R2
  

    
-> R1 and R0 registers will comebine as variable a (33:45)
-> R3 and R2 registers will comebine as variable b (34:05)
   -After adding (R0 and R2), there may be a carry bit(进位) to (r1 and R3) (34:12)
   -so C flags 标志位 in CPSR will be set (34:16) due to carry (34:35)
   -so we will use "ADDS" to reserve the carry bit (34:56) between R0 and R2
   -Then we will use "ADC" to add another 1 from C flag 标志位 in CPSR if the carrry bit has been set (35:12)(35:21)
ADDS R4,R0,R2 ;(35:53) To keep the carry bit
ADC  R5,R1,R3 ;R1+R3+ C flag 标志位 in CPSR (36:22)
   -ADC will add 1 if there is carry bit in "ADDS R4,R0,R2" line 151 (36:11)
->SBC (sub with carry 借位) (36:45)
     
->AND (Bitwise operator 位操作)(36:57) 
     -& operator in C lanquage
     -a&B->bitwise for each bit (37:41)
     -a&&b->logical operation (37:45)
     -eg
      -a=5; b=8;
        if(a&b)
          AAA;
        else
          BBB; //0101 &1000=0 (goes here)(39:08)
      -eg2
         a=5;b=8
         if(a&&b)
          AAA; //0101!=0 &&1000!=0 disregards -ve or +ve so goes here (39:43)  
        else
          BBB;   
->(39:51)
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
