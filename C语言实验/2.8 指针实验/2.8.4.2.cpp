#include<stdio.h>
#include<string.h>
void change(char *);
void move(char *,int);
int main(void)
{
	int n,i;
	printf("请输入n:");
	scanf("%d",&n);
	getchar();
	char s[n][80],*ps[n];
    for(i=0;i<n;i++)
	{
        gets(s[i]);
        ps[i]=s[i];
    }

	for(i=0;i<n;i++) 
	    change(ps[i]);
	printf("合并空格后：\n"); 
	for(i=0;i<n;i++) printf("%s\n",ps[i]);
	getchar();
	return 0;
} 

void change(char *s)
{
	int l,i;
	l=strlen(s);
	for(i=0;i<l;i++)
		if(*(s+i)==' ')
			while(*(s+(i+1))==' ')
			{
				move(s,i);
			}
}

void move(char *str,int t)
{
	while(*(str+t)!='\0')
	{
		*(str+t)=*(str+t+1);
		t++;
	}
}
