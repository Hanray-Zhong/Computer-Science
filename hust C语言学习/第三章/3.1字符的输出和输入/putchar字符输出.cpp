#include<stdio.h>
int main()
{
    char c1,c2,c3,c4;
    c1='H';          //�ַ����ͼ���� '' ������ "" 
    c2='U';          //ÿһ���ַ�����Ӧ��ASCII�룬�����໥�滻 
    c3='S';
    c4='T';
    putchar(c1);putchar(c2);putchar(c3);putchar(c4);    //putchar()����չʾ 
                                                        //putchar()ֻ���������λ���ַ� 
    getchar();
    return 0;
}
