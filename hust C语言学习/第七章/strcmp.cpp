#include <stdio.h>

int strcmp(char [],char[]);
int main(void)
{
	char s[20],t[20];
	scanf("%s",s);
	scanf("%s",t);
	printf("%d",strcmp(s,t));
	return 0;
}

/********strcmp()***********/
int strcmp(char s[],char t[])
{
	int j=0;
	while(s[j]==t[j]&&s[j]!='\0') j++;
	return s[j]-t[j];
}
