#include<stdio.h>
#include<string.h>
void strnins(char [],char [],int);
char s[20],t[20];
char *ps=s,*pt=t;
int main(void)
{

	int n;
	printf("输入字符串s，t:\n");
	scanf("%s %s",ps,pt);
	getchar();
	printf("输入n：\n");
	scanf("%d",&n);
	getchar();
	strnins(s,t,n);
	printf("输出结果为：\n");
	printf("%s",ps);
	getchar();
	return 0; 
}

void strnins(char s[],char t[],int n)
{
	int ls=strlen(s),lt=strlen(t),i;
	for(i=ls;i>=n;i--)
		*(ps+i+lt)=*(ps+i);
	for(i=0;i<lt;i++)
	    *(ps+n+i)=*(pt+i);
}
