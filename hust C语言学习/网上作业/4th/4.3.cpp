#include <stdio.h>
void function0(double,double,char);
void function1(double,double,char);

int main(void)
{
	int i;
	double a,b;
	char ch;
	while(scanf("%d %lf %lf %c",&i,&a,&b,&ch)!=EOF)
	{
		switch(i)
		{
			case 0:printf("After if-else processing,the result is : ");
			       function0(a,b,ch);
			       printf("\n");
			       break;
			case 1:printf("After switch processing,the result is : ");
			       function1(a,b,ch);
			       printf("\n");
				   break;
			case 2:printf("After if-else processing,the result is : ");
			       function0(a,b,ch);
			       printf("After switch processing,the result is : ");
			       function1(a,b,ch);
			       printf("\n");
			       break;
		}
	}
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
