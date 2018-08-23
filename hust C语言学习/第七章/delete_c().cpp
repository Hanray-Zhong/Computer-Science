#include <stdio.h>

void delete_c(char [], char);
int main(void)
{
	char s[20];
	char ch;
	scanf("%s",s);
	getchar();
	scanf("%c",&ch);
	delete_c(s,ch);
	printf("%s",s);
	return 0;
}

/***************************/
void delete_c(char s[],char c)
{
	int j=0,k=0;
	while(s[j]!='\0')
	{
		if(s[j]!=c)
		    s[k++]=s[j];
		j++;
	}
	s[k]='\0';
}
