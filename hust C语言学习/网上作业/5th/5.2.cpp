#include <string.h>
#include <stdio.h>

int main(void)
{
	char n[11];
	int k;
	
	while(scanf("%s %d",n,&k)!=EOF)
	{
	    if(k>strlen(n)) printf("%d\n",-1);
	    else printf("%c\n",n[strlen(n)-k]);
	}
	return 0;
}
