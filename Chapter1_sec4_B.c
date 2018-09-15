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
   
   MVN R5,#0X0;

   ORR R6,R1,R2; ;R6=R1 OR R2 (41:45)
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
    

   B .
   END
->In embedded Software Development, Bitwise operator 位操作 (40:15) is a mandatory requirement (41:12)
     -In application development, they don't use a lot of bitwise operation 位运算 (41:24)
     -The good application programmer may use the bitwise operation 位运算 (41:27) since it can reduce the
     resource requiremnt in the memory (41:30)
     -In embedded software development, there are a lot of bitwise operation 位运算 required (41:34)
     -You will set 1/0 in the register 寄存器 (41:40) or physical memory (内存) in large bitwise operation 位运算 (41:41)
->RR R6,R1,R2
 -(41:52) R6 should be 0X0000 0011=3d (43:02)
->AND R3,R1,R2
 -(43:21) R3=0x0000 0000=0d (43:21) due to and operation 与操作 (43:37)
->CMP (compare 比较)
AREA asm1test,CODE,READONLY
   ENTRY
AAA
   MOV R0, #0X1
   MOV R1, R0
   MOV R2, #0X2
   
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   CMP R3,R1 (44:14);R3-R1 for change the flag 标志位 in CPSR  寄存器
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0
   
   MVN R5,#0X0;

   ORR R6,R1,R2; ;R6=R1 OR R2 (41:45)
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
    

   B .
   END
   -It is like SUB. There is a difference (44:08)
   -"CMP" doesn't save the result to another register 寄存器 as "Sub" (44:34)
   -"CMP" only compares these two registers  寄存器 but don't save the result to another register  寄存器(44:42)
   -Its pupurse is to change the flag 标志位 in CPSR  寄存器 (44:54)
   -like the example in "if(A>B)", we only care which one is bigger (45:12)
      -We DON'T care what is the different amount between A and B(45:18)
      -so We only care about the flag 标志位 in CPSR but not the resulted difference between A and B(45:24)
     
->BIC (Bit clear 位清零) command (45:33)
     -It will set the bit 位 as 0 (45:37)
     -eg.
AREA asm1test,CODE,READONLY
   ENTRY
AAA
   MOV R0, #0X3
   BIC R0,R0,#0x1; 
   MOV R1, R0
   MOV R2, #0X2
   
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0
   
   MVN R5,#0X0;

   ORR R6,R1,R2; ;R6=R1 OR R2 (41:45)
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
    

   B .
   END
   -"BIC R0,R0,#0x1" set the lowest bit to 0 in R0 (46:15) then save to R0 寄存器 (46:19)
   -When PC(R15) points to line 77,the R0 will be 2d (46:40) 
->LDR and STR
  -It has the concept of Load and Store (47:14)
  -When you want to move from one address 地址 of physical memory 内存 to another 另一个 address 地址 of physical memory 内存
    -you have to load it into the register 寄存器 (or CPU 内部) then store into another 另一个 address 地址 of physical memory 内存 (47:47)(47:52)
    -load from memory 内存 to register 寄存器 (48:03)
    -store from register 寄存器 to memmory 内存 (48:03)
    -eg
AREA asm1test,CODE,READONLY
   ENTRY
AAA
   MOV R0, #0X3
   BIC R0,R0,#0x1; 
   MOV R1, R0
   MOV R2, #0X2
   
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0
   
   MVN R5,#0X0;
   MOV R6,#0X9000
   STR R5,[R6]; [] refer to the content of address as brackets 括号 (51:20)
   LDR R7,[R6];obtain the data from the memory (51:28)(51:35)

   STR R5,[R6,#0X4]; 
   ORR R6,R1,R2; ;R6=R1 OR R2 (41:45)
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
    

   B .
   END
   -(49:07) Compile and see 
   -Click memory block and set 0x9000 (49:57)
   -Due to MVN so R5 will contain the inverse of 0->FFFF FFFF (50:30)
   -When PC points to line 116, we should see the content of address at  0x9000 is FFFF FFFF (51:01)
   -When PC pionts to line 118, R7=FFFF FFFF (52:26)
   -Thare are more advanced assembly instruction as "STR R5,[R6,#0X4]" (53:09)
     -It means the base (基地址) + offset 偏移地址 (53:15)
     -So R6+0x4 at first then get the content at location of [R6+0x4] (53:19)
     - 90000+4 then get the content at [90004] (53:23)
     -
-> STMFD (PUSH) (53:47) as push operation and LDMFD(POP)
  -link->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0068b/Cacbgchh.html
  -It will cover later (53:50)
  
->B is branch (跳转) operation (指令) (53:54)
    
->BL means branch while retaining the return address (54:03) to LR(L14)
  -link->http://www.keil.com/support/man/docs/armasm/armasm_dom1361289865686.htm
  -eg
AREA asm1test,CODE,READONLY
   ENTRY
AAA;(Start of Case I)
   MOV R0, #0X3
   BIC R0,R0,#0x1; 
   MOV R1, R0
   MOV R2, #0X2
   
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0
   
   MVN R5,#0X0;
   MOV R6,#0X9000
   STR R5,[R6]; [] refer to the content of address as brackets 括号 (51:20)
   LDR R7,[R6];obtain the data from the memory (51:28)(51:35)

   STR R5,[R6,#0X4]; 
BBB
   ORR R6,R1,R2; ;R6=R1 OR R2 (41:45)
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
    

   BL BBB
   
   MVN R5,#0X1;
   MOV R6,#0X9000
   
   END;(End of case I)
  -With "BL BBB" it will jump (跳转) to BBB (54:51)
  -When CPU execute line 164 and PC(L15) is at line 167, the content of R14 is 0000 0000 (55:12)
  -L14 (LR) is used to keep return address (55:22)
  -BBB refers to the address of 0x8038 in line 163 of "ORR R6,R1,R2" (56:02)
   
  -When CPU execute line 167, PC(L15) points to line 163. and R14(LR) points to "MVN R5,#0X1"as 0x8044 (56:07) in case 1
  -eg case II starts
AAA;(Start of Case II)
   MOV R0, #0X3
   BIC R0,R0,#0x1; 
   MOV R1, R0
   MOV R2, #0X2
   
   ADD R3,R1,R2  ;R3=R1+R2 (26:54)
   SUB R4,R3,R1  ;R4=R3-R1 (26:35)分号 (26:43) 
   SUBS R0,R0,R0
   
   MVN R5,#0X0;
   MOV R6,#0X9000
   STR R5,[R6]; [] refer to the content of address as brackets 括号 (51:20)
   LDR R7,[R6];obtain the data from the memory (51:28)(51:35)

   STR R5,[R6,#0X4]; 
BBB
   ORR R6,R1,R2; R6=R1 OR R2 (41:45)
   AND R3,R1,R2; (40:51)R3=R1 AND R2 (40:49) 
    

   B BBB
   
   MVN R5,#0X1;
   MOV R6,#0X9000
   
   END;(End of case II)
   -use "B BBB" instead of "BL BBB" (56:23)
   -It is required to clean up the register 寄存器 first. (56:39). How to do it (56:52)
   -The value of R14 won't change when CPU execute line 201, PC(R15) points to (57:03) address of "ORR R6,R1,R2" 
   as line 197, LR(R14) WON'T reserve the address of
   (57:03) of "MVN R5,#0X1" at line 203 (57:09))
   -Observe what happen (57:12)
   ->The diference between BL and B are preserving the return address (保存返回地址)of 
   LR(L14) or not (57:32)
->SWP intruction 指令. We rarely use it (57:47)
->MRS and NSR are used to operate 操作 (modify) CPSR status 状态 register 寄存器 (57:54)
     -link->https://blog.csdn.net/minsophia/article/details/53068097
     -MRS R0, CPSR; move content of CPSR to R0
     -MSR CPSR,R0; move content of R0 to CPSR 
     -It is used to change the status mode from SUPERVISOR mode to USER mode (58:35)
     -The lowest 5 bit  in CPSR status register 状态 寄存器(58:50) determines if it is in USER mode
     or kernel mode (59:00)
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
