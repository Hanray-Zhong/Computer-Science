#include <stdio.h>

int strlen(char []);
int main()
{
	char string[20];
	gets(string);
	printf("%d",strlen(string));
	return 0;
}

/***************strlen()****************/
int strlen(char s[])
{
	int j=0;
	while(s[j]!='\0') j++;
	return j;
}
