#include <stdio.h>
int main(void)
{
	char Capital[27],Lowercase[27];
	int i,delt='a'-'A';
	Capital[0]='A';
	Lowercase[0]=Capital[0]+delt;
	for(i=1;i<26;i++)
	{
		Capital[i]=Capital[i-1]+1;
		Lowercase[i]=Lowercase[i-1]+1;
	}
	Capital[26]='\0';
	Lowercase[26]='\0';
	printf("%s\n",Capital);
	printf("%s\n",Lowercase);
	return 0;
}
