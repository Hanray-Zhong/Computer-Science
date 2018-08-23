#include <stdio.h>
long sum_fac(int);
int main(void)
{
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
    getchar(); 
	return 0;
}
long sum_fac(int n)
{
    static long s=0;
    int i;
    static long fac=1;
	fac*=n;
    s+=fac;
    return s;
}

