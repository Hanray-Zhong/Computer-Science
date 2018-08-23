#include <stdio.h>
int main()
{
    char s[20]="Hello,";
    char *pc="world!";
    puts(s);
    puts(pc);             //puts函数会在串尾输出"\n" 
    getchar();
    return 0;
}
