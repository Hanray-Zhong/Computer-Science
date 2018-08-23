#include <stdio.h>
int main()
{
    int i1=12,i2=12345;
    float x=3.1416;
    double y=123.4567;
    char s1[20]="Technology";
    printf("i1=%-8.3d,i2=%8.3d",i1,i1);      //-代表左对齐，8代表至少有8个字符，没有的话用空格补齐
                                             //3代表保留3位整数，不够用0补齐，多了不影响 
    getchar();
    printf("\ni2=%-8.3d,i2=%8.3d",i2,i2);    
    getchar();
    printf("\ny=%4.2f",y);                  //4代表至少4个字符 ；2代表保留2位小数，溢出的四舍五入，不够的用0补齐 
    getchar();
    printf("\nx=%8.3f,x=%.3f",x,x);         //小数点前的域宽可以省略，由要输出的内容自己判断 
    getchar();
    printf("\n%s,%8.4s",s1,s1);              
    getchar();
    return 0;
}
