#include <stdio.h>
int main(void)
{
	int i,times,sum,m;
	double ave;
	
	scanf("%d",&times);
	for(i=1;i<=times;i++)
	{
		int string[11];
		scanf("%d %d %d %d %d %d %d %d %d %d %d"\
		    ,&string[0],&string[1],&string[2],&string[3],&string[4],&string[5],&string[6],&string[7],&string[8],&string[9],&string[10]);
	    if(string[0]==0)
	    {
	    	int j=1;
	    	m=0;
	    	sum=0;
	    	ave=0;
	    	
	    	for(j;j<=10;j++)
	    	{
	    		if(string[j]<=0) continue;
		        sum=sum+string[j];
		        m++;
			}
			if(m!=0)
			{
				ave=(double)sum/(double)m;
	            printf("In \"continue\" way,numbers=%d,average=%.6f\n",m,ave);
			}
		}
	    else
	    {
	    	int j=1;
	    	m=0;
	    	sum=0;
	    	ave=0;
	    	
	    	for(j;j<=10;j++)
	    		if(string[j]>0)
	    		{
	    			sum=sum+string[j];
	    			m++;
				}
			if(m!=0)
			{
				ave=((double)sum)/(double)m;
				printf("In \"no continue\" way,numbers=%d,average=%.6f\n",m,ave);
			}
	    	
		}
	}
	
    return 0;
}

