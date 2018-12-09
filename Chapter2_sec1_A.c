https://www.youtube.com/playlist?list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo
https://www.youtube.com/watch?v=DIePk-tlvgI&list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo&index=2
Linux嵌入式开发和驱动开发--2开发板外设驱动
Section1_c和汇编混合编程   
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
    //mov r1,#5
   int c;
   c=myadd(a,b);
    //bl myadd
   printf("%d\n",c);
    //add r0,pc,#8 ; 0x80cc
    //bl _printf
   
   return 0;
   //mov r0,#0
}
    -bl is to to save/keep the return address 返回地址(22:08)
    -We need to be aware that why it uses r0 and r1 instead of r3 and r4 during the function call 函数调用 (22:20) 
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

