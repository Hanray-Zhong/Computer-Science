#include <stdio.h>
void swap(int *,int *);
int main(void) 
{
	int x,y;
	printf("Input two integers for x and y please!\n");
	scanf("%d%d",&x,&y);
	printf("Before swap, x=%d, y=%d.\n",x,y);
	swap(&x,&y);
	printf("After swap, x=%d, y=%d.\n",x,y);
	return 0;
}
/*****************************************/
void swap(int *x, int *y)                                      //将指针作为函数的参数可以在函数中改变的实参。 
{
	int t;
	t=*x,*x=*y,*y=t;
}
