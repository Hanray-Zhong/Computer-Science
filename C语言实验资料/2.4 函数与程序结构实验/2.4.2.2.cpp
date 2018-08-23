#include <stdio.h>
double sum_fac(int);
int main(void)
{
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %lf\n",k,sum_fac(k));
    getchar();
	return 0;
}
double sum_fac(int n)
{
    static double s=0;
    int i;
    static long fac=1;
	fac*=n;
    s+=(1.0/fac);
    return s;
}

