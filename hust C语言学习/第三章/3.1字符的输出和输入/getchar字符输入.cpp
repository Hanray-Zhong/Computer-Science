#include<stdio.h>
int main()
{
    char ch1,ch2,ch3; 
    ch1=getchar();        //����a���»س������������൱�ڴ���"a","\n",���Եڶ�������Ϊ"\n"
                          //getchar()����ֻ���ȡһ���ַ� 
    ch2=getchar();
    ch3=getchar();        //����b���»س���ch3����ֵb����һ��getchar()��ȡ�س� 
    getchar();
    printf("\n%c%c%c",ch1,ch2,ch3);
    printf("\n%d %d %d",ch1,ch2,ch3);
    getchar();
    return 0;
}
