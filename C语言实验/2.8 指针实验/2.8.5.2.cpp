#include<stdio.h>
#include<string.h>
int main(void)
{
	char *(*p[2])(char*,const char*);
	p[1]=strcpy;
	p[2]=strcat;
	char s[20],t[20];
	printf("�������������飺\n");
	gets(s);
	gets(t);
	printf("���������֣�\n1-������ĸ����\n2-����һ��������ӵ�ǰһ�������\n");
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
