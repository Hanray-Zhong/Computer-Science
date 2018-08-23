#include <stdio.h>
int main(void)
{
	int n,s,t,i,j,min;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		t=n,s=n;
		int str_0[n], str_1[n];
		for(i=0;i<=n-1;i++) scanf("%d",&str_0[i]);
		for(i=0;i<=s-1;i++) 
		{
			min=0;
			for(j=0;j<=t-2;j++) if(str_0[j+1]<=str_0[min]) min=j+1;          //ÕÒ×îÐ¡Öµ 
			str_1[i]=str_0[min];
			for(j=min;j<t-1;j++) str_0[j]=str_0[j+1];
			t--;
		}
		for(i=0;i<=n-1;i++)
		{
			printf("%d",str_1[i]);
			if(i!=n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
