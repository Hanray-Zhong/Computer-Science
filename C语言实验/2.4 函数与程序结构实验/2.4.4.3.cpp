#include <stdio.h>
#define BEGIN 10
#define END 20
int Prime_number(int n);
int main(void)
{
	int i,j,m,n;
	int prime_number[10];
	for(m=0;m<10;m++)
	    prime_number[m]=Prime_number(m+1);
	for(n=BEGIN;n<=END;n++)
	{
	    if(n%2) continue;
		for(i=0;i<10;i++)
	    {
	        for(j=0;j<10;j++)
	        {
	            if(n==prime_number[i]+prime_number[j])
	            {
	                printf("%d=%d+%d.\n",n,prime_number[i],prime_number[j]);
			        break;
				}
			}
			if(n==prime_number[i]+prime_number[j]) break;
		}
	}
	getchar();
	return 0;
}
/******************************/
int Prime_number(int n)
{
	static int s=0,t=2;
	while(n!=1)
	{
		int i;
		for(i=2;;i++)
		{
			if(t%i==0&&i!=t) break;
			if(i==t)
			{
			    s++;
			    break;
			}
		}
		if(s!=n) t++;
		if(s==n) break;
	}
	if(n==1) return 2;
	else return t++;
}
