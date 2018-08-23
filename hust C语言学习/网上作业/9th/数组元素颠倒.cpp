#include<stdio.h>
void reverse(int *, int);
int main(void)
{
	int N,n,i,j;
	scanf("%d",&N);
	getchar();
	for(j=1;j<=N;j++)
	{
		scanf("%d",&n);
		getchar();
		int num[n], *p;
		p=num;
		for(i=0;i<n;i++) scanf("%d",&num[i]);
		reverse(p,n);
		for(i=0;i<n;i++)
		{
			printf("%d",num[i]);
			if(i!=n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
void reverse(int *p, int n)
{
	int i,j,t;
	for(i=0,j=n-1;i<j;i++,j--) 
	{
		t=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=t;
	}
}
