#include "stdio.h"
#define SUM(a,b) ((a)+(b))                     //1st
#define DIF(a,b) ((a)-(b))                     //2nd
#define SWAP(a,b)  t=a,a=b,b=t          //3rd
int main(void)
{
    int a,b,t;                           //4th
    printf("Input two integers a, b:");
    scanf("%d,%d",&a,&b);
    getchar();
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM(a,b), SUM(a,b)*DIF(a,b));        //5th
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);         //6th
    getchar(); 
    return 0;
}

