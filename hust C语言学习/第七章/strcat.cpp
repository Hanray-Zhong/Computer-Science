#include <stdio.h>

char * strcat(char[],char[]);
int main(void)
{
	char t[20],s[20];
	scanf("%s",t);
    scanf("%s",s);
    printf("%s",strcat(t,s));
    return 0;
}

/*********strcat()*************/
char * strcat(char t[],char s[])
{
	int j=0,k=0;
	while(t[j++]!='\0');
	    j--;
	while(t[j++]=s[k++]);
	return t;
}
