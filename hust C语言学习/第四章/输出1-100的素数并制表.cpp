#include <stdio.h>
#include <math.h>
int main(void)
{
	int n,i,j,m;
	
	n=2;
	j=0;
	while(n<=100)
	{
		m=0;
		i=2;
		while(i<=sqrt(n))
		{
			if(n%i==0)
			{
				m=0;
				break;               //break 可以跳出循环和 switch 
			}
			else m=1;
			i++;
		}
		if(m==1||n==2||n==3)
		{
			printf("%d\t",n);
			j++;
			if(j%10==0) printf("\n");
		}
		n++;
	}
	return 0;
}
