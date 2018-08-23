#include <stdio.h>
int main(void)
{ 
    int i,n,s=1;
    printf("Please enter n:");
    scanf("%d",&n);
	if(n)
	{
		i=1;
		while(i<=n)
		{
			s*=i;
			i++;
		} 
	} 
    printf("%d! = %d",n,s);
    getchar();getchar();
    return 0;
}

