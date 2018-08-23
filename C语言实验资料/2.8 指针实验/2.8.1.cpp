#include "stdio.h"
int main(void)
{
    float num;
	float *p=&num;      //1st
    scanf("%f",p);
    printf("%f\n",*p);
    return 0;
}

