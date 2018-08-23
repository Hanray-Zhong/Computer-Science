#include <stdio.h>
#define SIZE 1000
void mycpy(char[],char[],int);
int main(void)
{
	int N,n,i,j;
	char s[SIZE],t[SIZE];
	scanf("%d",&N);
	getchar();
	for(i=1;i<=N;i++)
	{
	    j=0;
	    t[j]=getchar();
	    while(t[j]!='\n') t[++j]=getchar();
	    scanf("%d",&n);
	    getchar();
		mycpy(s,t,n);
	}
	return 0;
}
/***********************************/
void mycpy(char s[],char t[],int n)
{
	int j;
	for(j=0;j<=n-1;j++) s[j]=t[j];
	for(j=0;j<=n-1;j++) printf("%c",s[j]);
	printf("\n");
}
