#include <stdio.h>
int main(void)
{
	char c;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
		{
			printf("%c",c);
			while(c==' ')
			{
			    c=getchar();
			    continue;
			}
		}
		printf("%c",c);
	}
	getchar();
	return 0;
}
