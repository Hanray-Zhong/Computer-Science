#include <stdio.h>
int main()
{ 
	int n;
	scanf("%d",&n);
    while(n)
    {
	    int str[n][n];
	    int i,j=0,t;
	    for(i=0;i<=n-1;i++)
	    {
		    if(i==0) str[i][j]=1;
		    else
		    {
			    for(j=0;j<=i;j++)
			    {
				    if(j==0||j==i) str[i][j]=1;
				    else str[i][j]=str[i-1][j-1]+str[i-1][j];
			    }
		    }
	    } 
	    for(i=0;i<=n-1;i++)
	    {
		    for(t=2*(n-1)-2*i;t>=1;t--) printf(" ");
		    for(j=0;j<=i;j++) 
		    { 
		        if(j==0) 
		        {
		        	printf("1");
		        	continue;
				}
				printf("%4d",str[i][j]);
		    }
		    printf("\n");
	    }
	    printf("\n");
		scanf("%d",&n);
	}
	return 0;
}

