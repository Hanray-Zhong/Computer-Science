#include<stdio.h>
int main(void)
{
	int JuZhen[3][4];
	int i,j;
	printf("���������:");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
		    scanf("%d",&JuZhen[i][j]);
		    getchar(); 
	}                //����ԭ���� 
	printf("ԭ����Ϊ��\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++) printf("%d\t",JuZhen[i][j]);
		printf("\n");
	}
	int reverse[4][3];
	for(j=0;j<=3;j++)
	{
		for(i=0;i<=2;i++) reverse[j][i]=JuZhen[i][j];
	}
	printf("ת�þ���Ϊ��\n");
	for(j=0;j<=3;j++)
	{
		for(i=0;i<=2;i++) printf("%d\t",reverse[j][i]);
		printf("\n");
	}
	getchar();
	return 0;
} 
