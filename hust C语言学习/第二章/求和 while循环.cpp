#include "stdio.h"
int main()
{
    int sum,i,n;
    printf("Please enter the number of the \'n\':");
    scanf("%d",&n);
    getchar();
    i=1;
    sum=0;
    while(i<=n)
         sum=sum+i++;
    printf("sum=%d",sum);
    getchar();
    return 0;
}
