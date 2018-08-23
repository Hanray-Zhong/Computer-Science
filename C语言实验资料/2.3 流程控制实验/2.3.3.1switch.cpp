#include<stdio.h>
int main(void)
{
    int money;
	double tax;
	printf("输入工资金额: ");
	scanf("%d",&money);
	switch(money/1000)
	{
		case 0: tax=0;break;
		case 1: tax=0.05*(money-1000);break;
		case 2: tax=0.1*(money-2000)+50;break;
		case 3: tax=0.15*(money-3000)+150;break;
		case 4: tax=0.2*(money-4000)+300;break;
		default: tax=0.25*(money-5000)+500;
	} 
	printf("应收取税金额度: %lf￥",tax);
	getchar();getchar();
	return 0;
}
