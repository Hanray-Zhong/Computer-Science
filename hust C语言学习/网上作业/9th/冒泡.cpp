#include<stdio.h>
int main(void)
{
	int num[10],i,j;
	int *p=num;
	while(scanf("%d",p)!=EOF)
	{
		for(i=1;i<=9;i++)
			scanf("%d",p+i); 
		j=0;
		while(j<=9)                      //Ã°ÅÝ·¨ÅÅÐò 
		{
		    for(i=0;i<=8;i++)
		    {
			    if(*(p+i)>=*(p+i+1))
		    	{
	                int t;
	                t=*(p+i);
	                *(p+i)=*(p+i+1);
	                *(p+i+1)=t;
                }
		    }
		j++;
		}
		for(i=0;i<=9;i++)               //´òÓ¡ 
	    {
		    printf("%d",*(p+i));
		    if(i!=9) 
		        printf("->");
			else
			    printf("\n");
		}
	}
	return 0;
} 
