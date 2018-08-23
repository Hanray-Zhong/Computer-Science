#include <stdio.h>
int function(int);

int main(void)
{
	int num,i,times;
	scanf("%d",&num);
	while(num!=0)
	{
	    if(num>=3)
	    {
    		i=1;
    	    times=0;
	        while(i<=num)
	        {
		        int j=1;
        		int N;
	    	    times++;
        		if(function(i)<10) N=9;
        		if(function(i)>=10&&function(i)<100) N=8;
    	    	if(function(i)>=100&&function(i)<1000) N=7;
        		if(function(i)>=1000&&function(i)<10000) N=6;
        		if(function(i)>=10000&&function(i)<100000) N=5;
	        	if(function(i)>=100000&&function(i)<1000000) N=4;
	        	if(function(i)>=1000000&&function(i)<10000000) N=3;
        		if(function(i)>=10000000&&function(i)<100000000) N=2;
        		if(function(i)>=100000000&&function(i)<1000000000) N=1;
	        	while(j<=N)
	        	{
        			printf(" ");
        			j++;
          		}
		
        		printf("%d",function(i));
        		if(times%8==0) printf("\n");
				i++;
        	}
        	printf("\n\n");
		}
        else 
		{
		printf("Error!");
        printf("\n\n");
        }
        scanf("%d",&num);
        getchar();
    }
	return 0;
}

/**************************************************/
int function(int x)
{
	if(x==1||x==2) return 1;
	
	int i=3,a=1,b=1;
	int number;
	while(i<=x)
	{
		number=a+b;
		a=b;
		b=number;
		i++;
	}
	return number;
}
