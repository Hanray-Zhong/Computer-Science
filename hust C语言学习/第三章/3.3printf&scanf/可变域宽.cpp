#include <stdio.h>
int main()
{
    int max=6;
    char s[10]="123456789";
    printf("%*c",max,' ');
    getchar();
    printf("\n%.*s",2*max,s);
    getchar();
    printf("\n%.*s",max,s);          //*´ú±ímax
    getchar();
    return 0;
}
