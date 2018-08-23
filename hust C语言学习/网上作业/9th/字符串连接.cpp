#include<stdio.h>
int main(void)
{
	int n,i,j;
	scanf("%d",&n);
	getchar();
	while(n!=0)
	{
		char *all,str_all[100];
		all=str_all;
		for(j=0;j<=n-1;j++)
		{
			char str[n][100];
			i=0; 
			str[j][i]=getchar();
			while(str[j][i]!='\n')
			{
				*all=str[j][i];              //链接数组 
				all++;
				i++;
				str[j][i]=getchar();
			}                                  //输入n个数组 
	    }
	    printf("%s\n",str_all);
	    for(j=0;j<100;j++) str_all[j]='\0';
	    scanf("%d",&n);
	    getchar();
	}
	return 0;
} 
