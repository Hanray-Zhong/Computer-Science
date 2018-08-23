#include<stdio.h>
int main()
{
    char ch1,ch2,ch3; 
    ch1=getchar();        //输入a后按下回车，输入流中相当于存在"a","\n",所以第二个输入为"\n"
                          //getchar()函数只会读取一个字符 
    ch2=getchar();
    ch3=getchar();        //输入b后按下回车，ch3被赋值b，下一行getchar()读取回车 
    getchar();
    printf("\n%c%c%c",ch1,ch2,ch3);
    printf("\n%d %d %d",ch1,ch2,ch3);
    getchar();
    return 0;
}
