#include<stdio.h>
int main(void)
{
	char c;
	scanf("%c",&c);
	if(c>='A'&&c<='Z')
	{
		c=c-'A'+'a';
		printf("%c\n",c);
	}
	else printf("%c\n",c);
	return 0;
}
