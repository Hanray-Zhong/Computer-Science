#include <stdio.h>
int function(int);
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	    printf("%d\n",function(n));
	return 0;
}

/**************************************************/
int function(int x)
{
	if(x==1||x==2) return 1;
	
	int i=3,a=1,b=1;
	int number;
	while(i<=x)
	{
		number=a+b;
		a=b;
		b=number;
		i++;
	}
	return number;
}
