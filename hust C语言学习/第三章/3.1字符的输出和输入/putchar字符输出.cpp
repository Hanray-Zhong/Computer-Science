#include<stdio.h>
int main()
{
    char c1,c2,c3,c4;
    c1='H';          //字符输出图像用 '' 而不是 "" 
    c2='U';          //每一个字符都对应有ASCII码，可以相互替换 
    c3='S';
    c4='T';
    putchar(c1);putchar(c2);putchar(c3);putchar(c4);    //putchar()函数展示 
                                                        //putchar()只能输出最右位的字符 
    getchar();
    return 0;
}
