#include <stdio.h>
int main()
{
    int x,n,s,t;
    scanf("%d%d",&x,&n);
    getchar();
    while(n>=32) {
                 n=n%32;
                 }
    s=(x>>n);
    t=(x<<(32-n));
    x=s^t;
    printf("%d",x);
    getchar();
    return 0;
}
