#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num,i,j,t,m;
	j=0;
	char Binary[32];
	char *p=Binary; 
	for(i=0;i<=31;i++) *(p+i)='0';
	printf("请输入long型(32-bit)整数: ");
	scanf("%d",&num);
	getchar();
	if(num<0) *(p+31)='1';
	num=abs(num);
	while(num!=0&&num!=1)
	{
		m=num%2;
		*(p+j++)='0'+m;
		num=num/2;
	}
	*(p+j)=num+'0';c
	printf("得到的二进制为：");
	for(i=31,t=1;i>=0;i=i-8,t++)
	{   
		printf("第%d字节:\n",t);
		printf("高四位："); 
	    for(j=i;j>=i-3;j--) printf("%c",*(p+j));
	    printf("\t低四位：");
	    for(j=i-4;j>=i-7;j--) printf("%c",*(p+j));
	    printf("\n");
	}
	getchar();
	return 0;
}
