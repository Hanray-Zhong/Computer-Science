#include<stdio.h>
int main(void)
{
	int N,i,j,k,l,d,h;
	char hex[80];
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		d=0;
		int n=0;
		scanf("%s",hex);
		while(hex[n]!='\0') n++;
		n=n-1;
		for(j=2,k=n;j<=n,k>=2;j++,k--)
		{
		    h=1;
			for(l=1;l<=k-2;l++) h=h*16;
			if(hex[j]>='a'&&hex[j]<='f') hex[j]=hex[j]-'a'+10;
			if(hex[j]>='A'&&hex[j]<='F') hex[j]=hex[j]-'A'+10;
			if(hex[j]>='0'&&hex[j]<='9') hex[j]=hex[j]-'0';
			d=d+hex[j]*h;
		}
		printf("%d",d);
		if(i!=N) printf("\n");
	}
	return 0;
}
