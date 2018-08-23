#include <stdio.h>
#define CHANGE(c) (c)%2
void Output1(char [],int);
void Output2(char [],int);
int main(void)
{
	int i;
	i=0;
	char str[80];
	printf("请输入字符串：");
	str[i]=getchar();
	while(str[i]!='\n')
	{
		i++;
		str[i]=getchar();
	}
	switch(CHANGE(str[0]))
	{
		case 0:Output1(str,i);break;
		case 1:Output2(str,i);break;
	}
	getchar();
    return 0;
}
void Output1(char str[],int i)
{
	int t;
	printf("对应的电文为：");
	for(t=0;t<i;t++) printf("%c",str[t]);
	printf("\n");
}
void Output2(char str[],int i)
{
	int t;
	for(t=0;t<i;t++)
	{
		if(str[t]>='a'&&str[t]<='z') str[t]=str[t]-'a'+'A';
		else if(str[t]>='A'&&str[t]<='Z') str[t]=str[t]-'A'+'a';
	}
	printf("对应的电文为：");
	for(t=0;t<i;t++) printf("%c",str[t]);
	printf("\n");
}
