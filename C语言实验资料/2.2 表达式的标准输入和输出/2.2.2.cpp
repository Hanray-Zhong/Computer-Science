#include<stdio.h>
int main(void)
{
   int a, b;
   printf("Input two integers:");
   scanf("%d %d",&a,&b);
   a+=b; 
   b=a-b;
   a-=b;
   printf("\na=%d,b=%d",a,b);
}

