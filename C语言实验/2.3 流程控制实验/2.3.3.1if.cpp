#include<stdio.h>
int main(void)
{
	double money,tax;
	printf("输入工资金额: ");
	scanf("%lf",&money);
	if(money<1000) tax=0;
	if(money>=1000&&money<2000) tax=0.05*(money-1000);
	if(money>=2000&&money<3000) tax=0.1*(money-2000)+50;
	if(money>=3000&&money<4000) tax=0.15*(money-3000)+150;
	if(money>=4000&&money<5000) tax=0.2*(money-4000)+300;
	if(money>=5000) tax=0.25*(money-5000)+500;
	printf("应收取税金额度: %lf￥",tax);
	getchar();getchar();
	return 0;
}
