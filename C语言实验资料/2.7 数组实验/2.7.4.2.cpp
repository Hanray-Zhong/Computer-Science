#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num,i,j,m;
	j=0;
	char Binary[32];
	for(i=0;i<=31;i++) Binary[i]='0';
	printf("请输入int型整数: ");
	scanf("%d",&num);
	getchar();
	if(num<0) Binary[31]='1';
	num=abs(num);
	while(num!=0&&num!=1)
	{
		m=num%2;
		Binary[j++]='0'+m;
		num=num/2;
	}
	Binary[j]=num+'0';
	printf("得到的二进制为：");
	for(i=31;i>=0;i--)
	    printf("%c",Binary[i]);
	getchar();
	return 0;
}
