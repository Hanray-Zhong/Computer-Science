#include<stdio.h>
#include<string.h>
int main(void)
{
	char *(*p[2])(char*,const char*);
	p[1]=strcpy;
	p[2]=strcat;
	char s[20],t[20];
	printf("请输入两个数组：\n");
	gets(s);
	gets(t);
	printf("请输入数字：\n1-按首字母排序\n2-将后一个个数组接到前一个数组后\n");
	int n;
	scanf("%d",&n);
	getchar();
	switch(n)
	{
		case 1: if(s[0]>t[0])
		        {
		            char l[20];
		            p[1](l,s);
		            p[1](s,t);
		            p[1](t,l);
		            printf("%s\n%s",s,t);
				}
		        break;
		case 2: printf("%s",p[2](s,t));
		        break;
	}
	getchar();
	return 0;
} 
