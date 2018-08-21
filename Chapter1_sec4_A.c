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
          -
->Now wa are going to the MOV instruction (指令) (16:14)
  -can be either "MOV" or "mov" BUT NOT "moV" (16:26)
  -MOV R0, #0X1
     -If justtype this as the following since there is certain format (格式) to follow (17:08)
      MOV R0, #0X1    
     -Folow the guideline (17:38) and type as following
          AREA asm1test,CODE,READONLY
          ENTRY
          CODE32
          MOV R0, #0X1
          MOV R1, R0
          MOV R2, #0X2
          ADD R3,R1,R2
          SUB R4,R3,R1
          END
     -(17:53)(19:06)(26:04)
     -Code means 代码段(18:01)
     -Area asm1test means the name of this segment is as "asm1test" (18:05)
     -ENTRY 入口(18:18) like the main() in C lanquage (18:23)
     -CODE32 means 32bit 位 (18:30).If you didn't write, the default 默认 is 32bit位 (18:38)
     -
->
->
->
->
->          
 AREA asm1test,CODE,READONLY
   ENTRY       
   MOV R0, #0X1
   MOV R1, R0
   MOV R2, #0X2
   ADD R3,R1,R2
   SUB R4,R3,R1
   END
->(26:24)
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
