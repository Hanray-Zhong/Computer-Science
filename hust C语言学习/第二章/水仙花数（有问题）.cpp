#include "stdio.h"
int main(void)
{
    int x,i,j,k;
    x=0;
    while(x<=999);
       {
             i=int(x/100);
             j=int((x-i*100)/10);
             k=x%10;
             if(x==i*i*i+j*j*j+k*k*k)       //==表示判断是否相等，而=为初始化 
                
				printf("%d,%d,%d,%d\n",i,j,k,x);
			 x+=1;
       }
    return 0;
}
