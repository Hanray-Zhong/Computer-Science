#include <stdio.h>
int strlen(char []);
int strstr(char [],char []);
int main(void)
{
	char cs[20],ct[20];
	scanf("%s",cs);
	scanf("%s",ct);
	printf("%d",strstr(cs,ct));
	return 0;
}

/*************strstr()************/
int strstr(char cs[],char ct[])
{
	int j=0,k;
	for(;cs[j]!='\0';j++)
	    if(cs[j]==ct[0])
	    {
	    	k=1;
	    	while(cs[j+k]==ct[k]&&ct[k]!='\0')
	    	    k++;
	    	if(k==strlen(ct))
	    	    return j;
		}
	return -1;
}

/***************strlen()****************/
int strlen(char s[])
{
	int j=0;
	while(s[j]!='\0') j++;
	return j;
}
