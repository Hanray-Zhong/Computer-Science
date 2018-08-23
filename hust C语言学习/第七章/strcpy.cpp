#include <stdio.h>

void strcpy(char [],char []);
int main()
{
	char c[20],s[20];
	gets(c);
	strcpy(s,c);
	printf("%s",s);
	return 0;
}

/***********strcpy()*********/
void strcpy(char t[],char s[])
{
	int j=0;
	while(t[j]=s[j++]);
}
