#include "stdio.h"
int main()
{
    int i,n,sum;
    printf("Please enter the number of the \'n\':");
    scanf("%d",&n);
    getchar(); 
    sum=0;
    i=1;
    for(i;i<=n;i=i+1)
    {
                   sum=sum+i;
    }
    printf("sum=%d",sum);
    getchar();
    return 0;
}
