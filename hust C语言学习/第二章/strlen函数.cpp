#include "stdio.h"
int strlen(char s[])
{
    int i=0;
    while(s[i]!='\0') ++i;
    return i;
}

int main()
{
    char word[20];
    gets(word);
    printf("%d\n",strlen(word));     //%d代表要输出的字符串 
    getchar();
    return 0;
}
