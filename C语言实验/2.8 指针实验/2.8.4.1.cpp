#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num,i,j,t,m;
	j=0;
	char Binary[32];
	char *p=Binary; 
	for(i=0;i<=31;i++) *(p+i)='0';
	printf("������long��(32-bit)����: ");
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
	printf("�õ��Ķ�����Ϊ��");
	for(i=31,t=1;i>=0;i=i-8,t++)
	{   
		printf("��%d�ֽ�:\n",t);
		printf("����λ��"); 
	    for(j=i;j>=i-3;j--) printf("%c",*(p+j));
	    printf("\t����λ��");
	    for(j=i-4;j>=i-7;j--) printf("%c",*(p+j));
	    printf("\n");
	}
	getchar();
	return 0;
}
