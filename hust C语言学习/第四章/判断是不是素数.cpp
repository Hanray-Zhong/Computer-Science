#include <stdio.h>
#include <math.h>
int main(void)
{
	int num,i,j;
	
	printf("Input a number or input 0 to exit:\n");
	inx:
	scanf("%d",&num);
	while(num!=0){
	i=2;
	if(num<=1)
	{
		printf("Input error!Input it again:\n");
		goto inx;
    }
    else if(num>=2&&num<=3)
        j=1;
    else
    	while(i<=(sqrt(num)))
    	{
    		if(num%i==0)
    		{
				j=0;
				goto iny;
			}
			else
			    j=1;
			i++;
		}
	iny:
	if(j==0)
	    printf("No!\n");
	else if(j==1)
	    printf("yes!\n");
	scanf("%d",&num);
    }
	return 0;
}
