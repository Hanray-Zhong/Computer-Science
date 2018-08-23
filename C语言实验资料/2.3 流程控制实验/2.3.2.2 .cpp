#include <stdio.h>
int main(void)
{ 
    int i,S,s=1;
    printf("Please enter S:");
    scanf("%d",&S); 
	for(i=1;;i++) 
	{
		if(!S)
		{
			i=0;
			break;
		}
		s*=i;
		if(s>S) break;
	}
    printf("n=%d",i);
    getchar();getchar();
    return 0; 
}

