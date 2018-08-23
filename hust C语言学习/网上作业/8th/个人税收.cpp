#include<stdio.h>
int main(void)
{
	double money,tax;
	scanf("%lf",&money);
	while(money!=0)
	{
	    if(money<1000) tax=0;
	    if(money>=1000&&money<2000) tax=0.05*(money-1000);
	    if(money>=2000&&money<3000) tax=0.1*(money-2000)+50;
	    if(money>=3000&&money<4000) tax=0.15*(money-3000)+150;
	    if(money>=4000&&money<5000) tax=0.2*(money-4000)+300;
	    if(money>=5000) tax=0.25*(money-5000)+500;
	    printf("%lf\n",tax);
	    scanf("%lf",&money);
    }
	return 0;
}
