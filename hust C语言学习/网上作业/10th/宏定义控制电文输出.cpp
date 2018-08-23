#include <stdio.h>
#define CHANGE(c) (c)%2
void Output1(char [],int);
void Output2(char [],int);
int main(void)
{
	int N,j,i;
	scanf("%d",&N);
	getchar();
	for(j=1;j<=N;j++)
	{
		i=0;
		char str[80];
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
		for(i=0;i<80;i++) str[i]='\0';
	}
	return 0;
}
void Output1(char str[],int i)
{
	int t;
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
	for(t=0;t<i;t++) printf("%c",str[t]);
	printf("\n");
}
