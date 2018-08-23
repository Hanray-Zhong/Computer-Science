#include <stdio.h>
int main()
{
    int i=1,s=0;
    while(i<=100)
    {
                 s=s+i;
                 i++;
    }
    printf("The answer is:%d",s);
    getchar();
    return 0;
}
