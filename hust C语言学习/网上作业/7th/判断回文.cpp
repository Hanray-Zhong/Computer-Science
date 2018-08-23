#include <stdio.h>
int Check(char[],int,int);
int main(void)
{
	int N,i;
	scanf("%d",&N);
	getchar();
	for(i=1;i<=N;i++)
	{
		char str[80];
		int n=0,t=0;
		str[t]=getchar();
		while(str[t]!='\n') str[++t]=getchar();
		while(str[n]!='\n') n++;
		n=n-1;
		if(Check(str,0,n)==1) printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}
/********************************/
int Check(char str[],int j,int n)
{
	if(j>=n) return 1;
	else
	{
		if(str[j]==str[n]) Check(str,j+1,n-1);
		else return 0;
	}
}
