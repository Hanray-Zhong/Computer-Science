#include <stdio.h>
void Change(short,short[],short);
int main(void)
{
	short n,k,i;
	
	while(scanf("%hd %hd",&n,&k)!=EOF)
	{
	    if(n>60||k>60) continue;
		short u[n];
	    for(i=0;i<=n-1;i++) 
		{
		    scanf("%hd",&u[i]);
		    if(u[i]>1000||u[i]<-1000) 
		        do
				{
				    scanf("%hd",&u[i]);
				}while(u[i]>1000||u[i]<-1000);
		}
	    Change(n,u,k);
	    for(i=0;i<=n-1;i++) 
		{
		    printf("%hd",u[i]);
		    if(i!=n-1) printf(" ");
		}
	    printf("\n");
	}
	return 0;
}
/****************************************/
void Change(short n,short u[],short k)
{
	short j,i,t;
	for(j=1;j<=k;j++)
	{
	    t=u[0];
	    for(i=0;i<=n-2;i++) u[i]=u[i+1];
	    u[n-1]=t;
    }
}
