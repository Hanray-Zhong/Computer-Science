#include <stdio.h>
int main()
{
    int i1=12,i2=12345;
    float x=3.1416;
    double y=123.4567;
    char s1[20]="Technology";
    printf("i1=%-8.3d,i2=%8.3d",i1,i1);      //-��������룬8����������8���ַ���û�еĻ��ÿո���
                                             //3������3λ������������0���룬���˲�Ӱ�� 
    getchar();
    printf("\ni2=%-8.3d,i2=%8.3d",i2,i2);    
    getchar();
    printf("\ny=%4.2f",y);                  //4��������4���ַ� ��2������2λС����������������룬��������0���� 
    getchar();
    printf("\nx=%8.3f,x=%.3f",x,x);         //С����ǰ��������ʡ�ԣ���Ҫ����������Լ��ж� 
    getchar();
    printf("\n%s,%8.4s",s1,s1);              
    getchar();
    return 0;
}
