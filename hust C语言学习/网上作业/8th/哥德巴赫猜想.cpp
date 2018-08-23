#include <stdio.h>
int Prime_number(int n);
int main(void)
{
	int i,j,m,n,begin,end;
	scanf("%d %d",&begin,&end);
	int prime_number[1000];
	for(m=0;m<1000;m++)
	    prime_number[m]=Prime_number(m+1);
	while(begin!=0)
	{
	    for(n=begin;n<=end;n++)
	    {
	        if(n%2) continue;
		    for(i=0;i<begin;i++)
	        {
	            for(j=0;j<begin;j++)
	            {
	                if(n==prime_number[i]+prime_number[j])
	                {
	                    printf("%d=%d+%d\n",n,prime_number[i],prime_number[j]);
			            break;
			    	}
			    }
			    if(n==prime_number[i]+prime_number[j]) break;
		    }
	    }
	    printf("\n");
	    scanf("%d %d",&begin,&end);
	}
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
