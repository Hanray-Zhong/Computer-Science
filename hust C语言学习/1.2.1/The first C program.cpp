#include "stdio.h"
void show(char str[]);
int main()
{
    char name[20];
    printf("Input your name please.\n");
    gets(name);
    
    printf("Hello %s!\n",name);          //需要输出输入字符串时，就需要用%s来代表字符串 
    show(name);
    getchar();
    return 0;
}

void show(char str[])
{
     printf("This is the first program for %s to learn C programming!\n",str);
}
