#include <stdio.h>
#define SIZE 3
double scalar(double *a,double *b,int n);
int main(void)
{
	double x[SIZE],y[SIZE],*px,*py;
	for(px=x;px<x+SIZE;px++) scanf("%lf",px);
	getchar();
	for(py=y;py<y+SIZE;py) scanf("%lf",py++);
	px=x;
	py=y;
	printf("The scalar of vector x and vector y is %lf\n",scalar(px,py,SIZE));
	return 0;
}
/**************************************************************************/
double scalar(double *a,double *b,int n)
{
	double s,*p;
	printf("the vector a is \n");
	for(p=a;p<a+n;) printf("%lf\t",*p++);
	printf("\nthe vector b is \n");
	for(p=b;p<b+n;) printf("%lf\t",*p++);
	printf("\n");
	for(s=0,p=a;p<a+n;)
	    s+=((*p++)*(*b++));
	return s;
}
