#include <stdio.h>
int main(void) 
{ 
    int i,n,s=1;
    printf("Please enter n:");
    scanf("%d",&n);                     //  add &
	for(i=1;i<=n;i++)                   //  ,->;
        s=s*i;
    printf("%d! = %d",n,s);
    getchar();getchar();
	return 0;                             //   add return 0;
}

