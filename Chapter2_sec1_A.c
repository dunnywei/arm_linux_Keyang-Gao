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



3G---------------------------------
   6
   4
        
   main
   fun



    -main and fun are both saved in the code segment (代码段) (4:28)
    -When main is call the "fun" function,we need to pass two parameters as 4 and 6 (参数)(4:34)
    -
    -(starts here)
        
       
->code 2 (10:05)
void bubble_sort(int a[],int n);

/*bubble.s*/
bubble_sort
   move r0
   

/*main.c*/
int main()
{
    int a[10];
    bubble_sort(a,10);
}
->code 3 (15:10)(16:07)
#include <stdio.h>

extern int myadd(int a,int b);

int main(void)
{
   int a=3;
   int b=5;
   int c;
   c=myadd(a,b);
   printf("%d\n",c);
   
   return 0;
}
    
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
    
    
    ->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->

