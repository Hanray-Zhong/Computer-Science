#include <stdio.h>

int Get_num(int);
int main(void)
{
	int times,i,j,a,b,x,y;
	scanf("%d",&times);
	for(i=1;i<=times;i++)
	{
		scanf("%d %d",&a,&b);
		x=Get_num(a);
		y=Get_num(b);
		if(x+y==7||x+y==11) printf("success!\n");
		else if(x+y==2||x+y==3||x+y==12) printf("fail!\n");
		else
		{
			int m;
			m=x+y;
			a++;
			b++;
			for(j=1;j>=1;j++)
			{
				x=Get_num(a);
				y=Get_num(b);
				a++;
				b++;
				if(x+y==7) 
				{
					printf("fail!\n");
					break;
				}
				else if(x+y==m)
				{
					printf("success!\n");
					break;
				}
			}
		}
	}
	return 0;
}

/************************************************/
int Get_num(int y)
{
	int sum,i,x;
	x=y;
	sum=0;
	if(x==10000) return 1;
	else
	{
		sum=x/1000;
		x=x%1000;
		sum=sum+x/100;
		x=x%100;
		sum=sum+x/10;
		x=x%10;
		sum=sum+x;
		
		if(sum%6==0) 
	    	return 1;
		else 
			return sum%6+1;
	}
}
