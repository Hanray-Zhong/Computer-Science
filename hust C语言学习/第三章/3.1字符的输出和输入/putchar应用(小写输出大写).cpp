#include<stdio.h>
int main()
{
    char c;
    putchar(((c=getchar())>='a'&&c<='z')?c-'a'+'A':c);
    getchar();
    getchar(); 
    return 0;
}
