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
             if(x==i*i*i+j*j*j+k*k*k)       //==��ʾ�ж��Ƿ���ȣ���=Ϊ��ʼ�� 
                
				printf("%d,%d,%d,%d\n",i,j,k,x);
			 x+=1;
       }
    return 0;
}
