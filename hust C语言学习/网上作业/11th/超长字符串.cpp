#include<stdio.h>
int main(void)
{
	char str[50];
	char *ps=str;
	int i=0;
	for(i=0;;i++)
	{
		*(ps+i)=getchar();
		if(*(ps+i)=='#') break;
		printf("%c",*(ps+i));  
	}
	printf("\n\n");
	*(ps+i)='\0';
	printf("%s\n",ps);
	return 0;
} 
