#include <stdio.h>
void function0(double,double,char);
void function1(double,double,char);

int main(void)
{
	double a,b;
	char ch;
	scanf("%lf %lf %c",&a,&b,&ch);
	printf("After if-else processing,the result is : ");
	function0(a,b,ch);
	printf("After switch processing,the result is : ");
	function1(a,b,ch);
	printf("\n");
	
	return 0;
}

/***********************************/
void function0(double a,double b,char ch)
{
	if(ch=='+')
	    printf("%.2lf\n",a+b);
	if(ch=='-')
		printf("%.2lf\n",a-b);
	if(ch=='*')
		printf("%.2lf\n",a*b);
	if(ch=='/')
	    printf("%.2lf\n",a/b);
}

/**********************************/
void function1(double a,double b,char ch)
{
	switch(ch)
	{
		case '+':printf("%.2lf\n",a+b);break;
		case '-':printf("%.2lf\n",a-b);break;
		case '*':printf("%.2lf\n",a*b);break;
		case '/':printf("%.2lf\n",a/b);break;
	}
}
