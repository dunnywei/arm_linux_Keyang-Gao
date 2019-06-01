https://www.youtube.com/playlist?list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo
https://www.youtube.com/watch?v=DIePk-tlvgI&list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo&index=2
Linux嵌入式开发和驱动开发--2开发板外设驱动
Section1_c和汇编混合编程  
----------------Section of C call ASM starts------------------------------------------------------------
->ATPCS protocol (协议)(0:48)
    -link->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0056d/ch02s01s03.html
    -link->http://infocenter.arm.com/help/topic/com.arm.doc.espc0002/ATPCS.pdf
->Use C lanquage to call the function (调用函数) written in assembly or vice versa (0:28)(0:58)
->How to passing the paramter (传递参数) between C and assemlby during function call 函数调用(0:58)
->In C programming lanquage, we have two parameters (参数) (1:06)
    -Code 1
int fun(int a,int b)
{
    
}
int main(void)
{
    fun(4,6)
}
    -They are using stack (堆栈)(2:56) to pass the parameter (参数) from RIGHT to LEFT (3:36)
    -So it will starts from 6 then to 4 a.k.a 压栈 (3:55)
    -graphical view
---------------------------------
//Stack grows down
   6 as b  (Stack Segment)
   4 as a 
        
        
   main (code segment)
   fun
----------------------------


    -main and fun are both saved in the code segment (代码段) (4:28)
    -When main is call the "fun" function,we need to pass two parameters as 4 and 6 (参数)(4:34)
    -They use stack 栈 to pass it from main to "func" (4:37)
    -They will pass from the right to the left while pushing on the stack a.k.a 压栈 (4:44)
    -Therefore, it will put 6 first then put 4 later (4:54)
    -In C programming code, when it start to execute fun(4,6), flow of execution will jump 跳转 to the  function of the address (函数地址)
        from main function to "fun" function (5:07)
    -After the flow of control is at the address of "fun" function, arguments (实参) 6 and 4 passed then obtained during the execution time (5:26)
        link->https://blog.csdn.net/marcelwu/article/details/65629158
    -Within the function of "fun", when function start to obtain the value from parameter 形参 a or b (5:27), it will get from
    the stack 栈 (5:30)
    -While pushing on the stack 压栈, we go from right to the left. While poping out of stack 出栈, we goes from left to the right due to
    FIFO (5:42)
    -During the execution of the "fun" function, PC (R15) points to the address of function (6:08)
    -When function need to get the vale of the paparamter, it will obtain the value from stack 栈
    via index (索引) (6:14)
->Now we need to cross programming in both C and assembly (汇编) (6:21)
->We can write the function 函数 in assembly(汇编) and use C lanquage to call 调用 it (6:25)
->For example, I am writing a bubbble_sort in assemlby (汇编) (6:30) by using the label 标号 (6:47)
-> label 标号 represents the address (地址) (6:51). It is the same as the fuction name 函数名 (6:54)
->What bubble sort is doing is to have the 泡泡排序 (7:15)
->The Following is the demonstration of bubble sort in C lanquage as Code 2. (7:32)
       

->code 2 (10:05)
----------------------------------------------
void bubble_sort(int a[],int n)
{
        
}

/*汇编
 *bubble.s*/
bubble_sort
   move r0
   
/*main.c*/
int main()
{
    int a[10];
    bubble_sort(a,10); (8:10)
}
------------------------------------------------
->Under CODE 2
->The first parameter represents the start address 起始地址 or 首地址 of the array 数组. The second parameter represents the length of
array(7:39)
->IN C programming, I have two paramters (参数) passing (传递) to the bubble_sort function. Therefore, I also need to pass
in two paramters (参数) in assemlby lanquage as well. (7:53)
->If I have already written the bubble_sort and the main function try to call 调用 it (8:04),
->The main function is written in C lanquage (8:37), bubble_sort is written in assembly code (汇编) (8:48)
->When C program needs to call the function in in assembly code (汇编) (9:04)
->When the main function in C program wants to call bubble_sort function in assembly lanquage 汇编代码 
in ARM architecture (体系结构), do we do the same way as in x86 architecture architecture (9:30)
->The answer is Yes. We can use stack 栈 / registers (寄存器) to pass the paramter (传递参数) (9:35)    
->Using the resters 寄存器 vs using the stack 栈. Which is faster? (9:35)
    -Using register 寄存器 is faster (9:51)
    -There are 37 registers 寄存器 in ARM architecutre. Under each mode, ARM can see 17/18 registers 寄存器(9:59)
    -ARM has more registers 寄存器 than x86 (10:01) so it pass the parameter (传递参数) via the registers (寄存器) (10:09)
    -X86 only has the limited registers 寄存器 so it has to use stack 栈 
    -ARM has more registers so it pass the paramter via registers for speeding perfomrance up (提高速度)  (10:19)
    -This is why we have ATPS protocol 协议 (10:25)
    -a) We will use R0 to R3 used for passing the parameter (传递参数) during the function call 函数调用 (10:34)
    -For example, we are going to make a function to the following (10:37)
    -int add(int a,int b,int c, int d) 
    -so R0=a,R1=b,R2=c, R3=d for using registers 寄存器 to pass the paramter (传递参数) (10:55)
    -using stack to passing the parameter (传递参数) if, there are more than "FOUR" (>4) paramters 参数. (11:16)
        -Those will require to use the stack 栈 to passing the parameter (传递参数)
    -R0 is used to keep the return value 返回值 from the function call (函数调用) (12:04)
    -Can a function use return stetement.It can only return one varialbe? (12:14)
        -If we want to return more than one variable. We can use pointer 指针.
        -However, we have to ensure that what pointer doesn't point to a local variable (局部变量)(12:32)
            -The reason is that the local variable 局部变量  will be released 释放 after the function ends (12:35)
            -Usually there are two ways. One is use addressed aloocated from "mollac" through static number 静态数 (12:40)(12:43)
           ->https://blog.csdn.net/wzy_1988/article/details/8687859 (most imporant)
           -link->https://blog.csdn.net/weiyuefei/article/details/51563890
           -link->https://blog.csdn.net/zkangaroo/article/details/61202533?utm_source=blogxgwz1
           -Or you package 封装 as a structure 结构体 (12:46) then return it as a structure 结构体(12:49)
    -b)return value in R0 can be a value 变量 or a pointer 指针 (13:07)
    -c)If more than four parameters 参数 (>4), we will use stack 栈 to pass paremeters 传递参数 (13:12)
->The following is the example (13:32)
->We will use C code to calls 调用  assemly code 汇编 (13:35)
    -There are three modes 模式 between C and assembly lanuages (13:40)
    -1st mode->C code to calls 调用  assemly code 汇编
    -2nd mode->assemly code 汇编 calls 调用 C code (13:44)  
    -3rd mode->embedded assembly code inside C code 内嵌 汇编 (C语言内嵌汇编)(13:50)
               -https://blog.csdn.net/pbymw8iwm/article/details/8227839
               -https://blog.csdn.net/yxc135/article/details/11537763
    -The most common is 1sst mode from C code to assemly code 汇编 (13:55) or 3rd embedded assembly 内嵌汇编(13:58) 
    -2nd mode is less common (14:03)
->code 3 (15:30)(16:07)
--------------------------------------------------------------------------------------------------------
#include <stdio.h>

extern int myadd(int a,int b);

int main(void)
{
   int a=3;//R0
   int b=5;//R1
   int c;
   c=myadd(a,b);
   printf("%d\n",c);
   
   return 0;
}

;save as myadd.s (16:21)(17:05)
   AREA MYADD,CODE,READONLY
   ENTRY;We shoudn't use entry (16:56)
   EXPORT myadd
myadd
   ADD R2,R0,R1
   MOV R0,R2
   MOV R15,R14 ;MOV PC,LR (18:15)

   END
----------------------------------------------------------------------------------------------------------   
    -When we use regsister  寄存器  to pass the parameter (传递参数) (17:16), 
    -During the call function, a and b registers are copy to R0 and R1 registers 寄存器 (17:22) respectively (17:26)
    -Or we can do like this "ADD R0,R0,R1" instead of "ADD R2,R0,R1" (17:41)
    -LR saves the return address of the function 函数的返回地址 (18:44)
    -myadd inside the assembly (汇编) lanquage is with a static 局部 by default 默认 (19:06)
    -if it is a static valuable/function inside the assembly (汇编) code, c code can't call this function (调用函数) or variable. (19:11)
    -Therefore we need to have a keyword "EXPORT" as 对外倒梳(出) (??) (19:19) (19:27)  
        -link->https://blog.csdn.net/uruita/article/details/7496929
    -Then we will use make to compile 编译 and may have an error 错误 (19:33)
    -THe error is named as
 image doesn't have an entry point (入口点) (NOt specified or not set due to multiple choices)
    -images->means executable program 可执行 程序 (19:41)
    -ENTRY 入口 is not equal to the entry point (20:02)
->IN C coding, the main function is the entry point ((入口点) (20:10)
->Therefore, the compiler is confused about which one it should call since there are more than one entry points (20:13)
->ONe come from the main function in C. The other is the main in assemlby 汇编 (20:19)
->Therefore compiler 编译器  didn't know which one to choose from (20:24)
->How do we solve the problem?
 ----------------------------------------------------------------------------------------------------------------------------                                                    
-Code 4
 ;save as myadd.s (16:21)(17:05)
   AREA MYADD,CODE,READONLY
   ;ENTRY;We shoudn't use entry (16:56)
   EXPORT myadd
myadd
   ADD R2,R0,R1
   MOV R0,R2
   MOV R15,R14 ;MOV PC,LR (18:15)

   END 
-----------------------------------------------------------------------------------------------------------------------------
    -we just comment out the ENTRY (20:33) then it should compile withoug any issue (20:41)
    -Now the entry point is on the main
->Now we will start the debug tool (调试工具) (20:51) 
->When the program enters the diassemly, it will starts as "__MAIN" (20:55). 
->In linux platform, it is called __start (21:03)
->So what does the start code 起动代码 do? (21:08)
                                                       -
    -Initialize the memory
    -load 加载 the shared library 共享库(21:10)
    -Then it will call the main function 函数 (21:12)
    -In ARM compiler, it uses __main which has the same functinality as __main                                                  
    -When we see the value of int a=3 or int b=5, the comppiler in arm assign the register 寄存器 directly (21:43) instead of the
    fucntion local variable 函数局部变量  (21:37) 
    -The reason is that ARM has more registers  寄存器. (21:49).
    -Pass to the registers will be faster than passing to the physical memory 内存(21:52)
->Code 5                                                     
int main(void)
{
   int a=3;//R0
   //mov r0,#3
   int b=5;//R1
    //mov r1,#5 //mov r14,r15 (implicitly)
   int c;
   c=myadd(a,b);
    //bl myadd
    //mov r1,r0
   printf("%d\n",c);
    //add r0,pc,#8 ; 0x80cc
    //bl _printf
   
   return 0;
   //mov r0,#0
}
----------------------------------------------------------------------------------------------------------------------------
    -bl is to to save/keep the return address 返回地址(22:08) so it will save as 0x0000 80B8
    -We need to be aware that why it uses r0 and r1 instead of r3 and r4 during the function call 函数调用 (22:20) of myadd
    -bl will save the the return address of myadd then jump to the assembly of myadd. In assembly 汇编 We can see that R0
    is 0x0000 0003 and R1 is 0x0000 0005 while getting into the code warrior during diassemly 反汇编 (22:47)
    -The value of R0 and R3 are the paramters 形参 of A and B in function myadd (22:53)
       -实参(argument)和形参(parameter)
       -link->https://bbs.csdn.net/topics/30240920
                                                     
   -In Code4, The myadd function is in Code, R0 and R1 are saved to R2 (22:46)
   -5+3=8(23:00)
   -In Code4 if we have the return value, we need to save it to R0 (23:03) so the value of R0 is 8 as well(23:09)
   -We save the R14 address to PC or R15 since R14 keeps the fuction return address 函数返回地址 as 0x0000 8088 (23:15)                                                  
   -After executing the myadd function, it returns to line 206 (23:22)
    -It needs to invoke the printf function 函数 (23:28)
    -How many parameter (参数) does printf have currently? (23:31)
    -Two for now (23:36)
    -双引号 as " " with 字符串 string character (23:41) 
    -C is a integer 整型 variable (23:42)
    -Move the value of r0 to r1 (23:47)
    -The reason is the return value 返回值 of myadd function 函数 is saved in r0 (23:55)
    -IN order to pass the parameter to the funtion 函数 of printf(), the value is saved in r1 register 寄存器 (24:02)
    -What does value c corresponding 对应 register 寄存器? It is r1
    -What does 双引号 as " " with 字符串 corresponding r0 (24:09)
    -"Mov r1,r0"->It is for copying the return value of C as "C=myadd(a,b)" (24:15) to r1 (24:19)
    -Then assigning another value of r0 with new value from the address of 字符串 string character as (24:17)
add r0,pc,#8 :#0x80cc 
    -Once r0 and r1 are ready (24:24), we will branch to _printf as 
       "bl _printf" (24:27)
    -Execution/Debug
    -Load the parameter 形参 in r0 and r1 (25:23)
    -The entry point of the application starts at main function 函数 
    -Before main function 函数 call/invvoke myadd, it will load values into r0 and r1 as parameter 形参 from left to right for preparation (25:08)
    -Then it will invoke myadd (25:16)(25:27)
    -Inside myadd function, it will utilize r0 and r1 then compute the value to r2 in line 175(25:34)
    -The return value is saved in r0 (25:49)
    -To return to the caller's address in assemlby, it is done by using " MOV R15,R14 ;MOV PC,LR" (25:54)
    -LR(Link Register) keeps the return address (26:02)
    -PC relates to the next instruction set will be executed (26:02)
    -The result of adding two number is 8 then move it to r0 (26:11) according to LINE 177
    -After doing the adding as myadd, move the return address as the content of LR to PC  (26:14)
    -Threfore PC will point to where it should execute (26:16)
    -AFter it returns to the main function, the r0 holds the return value of the function myadd() (26:22)
    -We need to move th content of r0 to r1 LINE 208 since r1 refers to varble c while invoking printf function (26:32) from left to the right (26:40)
    -"%d\n" in C reflects to r0 (26:40)
    -
    -
    -
    -
    -
    -
 ----------------Section of C call ASM ends------------------------------------------------------------
 ----------------Section of ASM call C starts------------------------------------------------------------                                                
->From_ASM_to_call C(27:21)
    -Have to follow the same protocol as well (27:32)
    -Code 6(27:44) of main.c
#include <stdio.h>

extern int fun(int a,int b);
int add(int a,int b) (28:26)
{
    return a+b;  [0000 80a8;
    //add r0,r0,r1
    //mov pc,r14  [0x0000 80ac]
}
/*Start of code shown during execution*/
/*
mov pc,r14
*/
/*End of code shown during execution*/

int main(void)
{
    int res; 
    int a=3,b=5;//mov r14,r15 (implicitly)->after mov, r14 points to the one in printf()
    //mov r0,#3 [0x0000 80b4] 
    //mov r1,#5 [0x0000 80b8]
    res=fun(a,b);
    //bl fun    [0x0000 80bc]
    //mov r1,r0 [0x0000 80c0]
    printf("%d\n",res);//29:06
    //add rp,pc,_8;  [0x0000 80c4]
    //bl _printf     [0x0000 80c8]
    return 0;
    //mov r0,#0      [0x0000 80cc]
}
    -Call function without the paramter (28:13) in fun
    -The "func" will be implemented by assemly (29:26)
    -Create an assembly code by code warrier (30:05)
    -No need to create the key work "ENTRY" in the following Cod 7(30:15)
    -Main will pass two parameters as "a" and "b" into fun then it will cal myadd function (30:31)
    -function of "fun" will carry two paramters (形参) as r0 and r1 then call add (30:31) function (30:35)
    -I want to use bl (30:29) to call add function in assembly (30:34)
    -So the calling procudure will be main()->fun() //wriiten in assemlby->add() //written in C
    -After add() is done in C code, it has to return a variable as r0 (31:09). It is because r0 is the register for
                                                     returning the variable 传递(should be 返回) 参数. (31:19)
    -Then it will return this value back to the main() (31:20)
                                                        
                                                         
    -Code7(30:05) of fun.s
AREA FUN,CODE, READONLY

fun
    add r0,r0,#1;//[0x0000 A498]
    add r1,r1,#1;//[0x0000 A49C]
    mov r8,r14 ;//[0x0000 A4A0]reserve the return address from main() of printf() function //mov r14,r15 (implicitly)->done by C compiler
    bl add;//[0x0000 A4A4]                                                                  //after mov, r14 points to mov r5,r0
    mov  r5,r0;//[0x0000 A4A8] For the convience of monitoring (31:49)
    mov r14,r8 ;//[0x0000 A4AC] r14 is lr(link register)
    mov pc,lr //[0x0000 A4b0] =mov r15,r14 
    
    end
    
    -We need to back up the "return address" 返回地址 from r14 to 48(31:20)
    -For monitoring purpse, we have "mov r5,r0" (31:45)
    -Explaination is in thefollowing (32:00)
    -When you invoke ret=fun(a,b) where a is 3 and b is 5(32:08)
    -Once I am in the function of "func", I add 1 to a as 4 and add 1 to b as 6 (32:13)
    -At first, I will back up the return address of "printf() function" in line 285 by C compiler as "mov r14,15" (32:18)(32:26) according to ATPCS protocol.
    -At second I execute "bl add" in line 398. (32:33)
       -so I will back up the explicitly the returned address of "mov r5,r0" in line 285 by calling the instruction set "mov r8,r14" then "move r14,r15(implictyly)" (32:39)
    -If I don't have "mov r8,r14" in line 307, the r14 of "printf" will be reflush (冲掉) and it will execute from line 309 to line 311 and  NEVER execute line 285 of printf (32:47)
    -In add(), it retunr value of "10" is stored in r0 due to 4+6. (32:59)
    -For the conviniece of monitoring/observation, we will have "mov r5,r0" (33:07)
    -For returning to the main() as 主程序 , we will have "mov r5 , r0" , "mov r14, r8" and "mov pc,lr". (33:13)
    -"mov r14, r8", return the back-up address to r14 (33:18)
    -We can fast track by using "mov pc,r8" instead of {"mov r14, r8" and "mov pc,lr"} (33:33)
       -The reason is to following the coding covention since all of return is done by lr as "mov pc,lr" (33:35)
    -This is the example of assembly code 汇编 call C's function 函數 (33:47)
    -There fore we need to have "IMPORT add" for assembly code 汇编 call C's function 函數 (33:53)
    -IMPORT is as 对内导入 (34:00)
    -fun function will be used by main fuction in C so it required to be "IMPORT fun" 对外导出 (34:11)(34:15)                                                  
->Now it is the executing time (34:52)
                                                       -
    - bl fun->to see if r14 will change or not (34:58)
    -r14 is at [0x0000 80C0] (34:59)->as mov r14,pc OR mov r14,r15->so the return address is kept in r14
    -IN function of fun with assembly
    -variable a holding 3 is added with 1 so (3+1=4)
    -variable b holding 5 is added with 1 so (5+1=6)(35:06)
    -reserve the r14 to r8 as "mov r5,r8" (35:13). If we do this, r14 will pionts to [0x0000 80C0] as "mov r1,r0" (34:51).If we didn't do this, r14 will pionts to [0x0000 A4A8] so it be stuck in fun function in assembly code and never return to main() in C                                         
    -Then it will call "bl add", which returns to C coding (35:21)
    -IN function add() in C codeing
    -the value of a is stored in r0 and value of b is stored in r1 (35:29) then adding r0 and r1 (35:32).
    -Return value is stored in r0 (35:35)
    -How does compiler return to the caller in add function as int add(int a,int b)?
    -It is done by using mov pc,r14 (35:41)
    -add 4 and 6 to 10 (35:47) as we can see the value of r0 will be changed after returning from "bl add" at line 322
    -assign the vale in r0 to r5 as "mov r5,r0" and assign the value in r8 to r14 as "mov r14,r8" (35:55)
    -Then move the content of r14 to PC(r15) (36:00)                                               
    -
    -
    -
    -
    -
   -
    -
    -                                                
    -
    -
    -
    -
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
    -Code8(34:16) of fun.s
AREA FUN,CODE, READONLY
IMPORT add
EXPORT fun
fun
    add r0,r0,#1
    add r1,r1,#1
    mov r8,r14
    bl add
    mov r5,r0
    mov r14,r8
    mov pc,lr
    
    end
    -(31:09)(32:05)(34:20)
                                                 
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    - 
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -                                                   -
    -
    -
    -
    -
    -
    -
                   
      

-----------------------------end of ATPS--------------------------------------------------------------------
      -(starts here)

->code 4 (29:16)

    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
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
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
