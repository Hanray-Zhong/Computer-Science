#include <stdio.h>
int main()
{
	//ÇóÑî»ÔÈı½Ç 
	int str[10][10];
	int i,j=0,t;
	for(i=0;i<=9;i++)
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
	//´òÓ¡ 
	for(i=0;i<=9;i++)
	{
		for(t=18-2*i;t>=1;t--) printf(" ");
		for(j=0;j<=i;j++) printf("%4d",str[i][j]);
		printf("\n");
	}
	getchar();
	return 0;
}


