#include <stdio.h>
int find(int, int, int, int);
int main(void)
{
	int a,b,n,m;
	n=1;
	printf("Input two integers:");
	scanf("%d %d",&a,&b);
	getchar(); 
	printf("最大公约数: %d\n",find(a,b,n,m));
	getchar();
	return 0;
}
/********************************/
int find(int a, int b, int n,int m)
{
	if(n>a||n>b) return m;
	if(a%n==0&&b%n==0) 
	{
		m=n;
		find(a,b,n+1,m);
	}
	else find(a,b,n+1,m);
}
