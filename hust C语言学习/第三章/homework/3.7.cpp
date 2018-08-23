#include <stdio.h>
int main()
{
    unsigned short x,y,z,s,mask;
    scanf("%d",&x);
    y=(x<<12);
    z=(x>>12);
    s=y^z;
    mask=4080;
    x=(x&mask)^s;
    printf("the answer is:%d",x);
    return 0;
}
