#include "stdio.h"
char *strcpy(char *,char *);
int main(void)
{
    char a[20],b[60]="there is a boat on the lake.";
    printf("%s\n",strcpy(a,b));
    return 0;
}
char *strcpy(char *s,char *t)
{
    int i=0;
	while(*s++=*t++) i++;
    for(i;i>=0;i--) s--;
    return (s);
}

