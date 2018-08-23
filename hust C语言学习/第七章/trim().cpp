#include <stdio.h>
int strlen(char []);
int trim(char []);
int main(void)
{
	char s[30];
	scanf("%s",s);
	printf("%d words: %s",trim(s),s);
	return 0;
}

/***********trim()********/
int trim(char s[])
{
	int i,num,j=0,k=0,l=strlen(s);
	while(s[j]==' '||s[j]=='\n'||s[j]=='\t'||s[j]=='\r') j++;
	i=l-1;
	while(s[i-k]==' '||s[i-k]=='\n'||s[i-k]=='\t'||s[i-k]=='\r') k++;
	num=l-k-j;
	for(i=0;i<num;i++)
	{
		s[i]=s[i+j];
	}
	s[num]='\0';
	return strlen(s);
}

/***************strlen()****************/
int strlen(char s[])
{
	int j=0;
	while(s[j]!='\0') j++;
	return j;
}
