#include<stdio.h>
double Newton(double);
double y;
int main(void)
{
	printf("%lf\n",Newton(1.0));
	return 0;
}
/************Å£¶Ùµü´ú*********************/
double Newton(double x)
{
	y=x;
	x=x-(3.0*x*x*x-4.0*x*x-5.0*x+13)/(9.0*x*x-8.0*x-5);
	if(y>x)
	{ 
	    if(y-x<1e-6) return x;
	    else Newton(x);
	} 
	else
	{ 
	    if(x-y<1e-6) return x;
	    else Newton(x);
	} 
} 
