#include<stdio.h>
int main(void)
{
	int x=100;
	printf("Dec=%d, Octal=%o, hex=%x\n",x,x,x);         //octal八进制    hex十六进制 
	printf("Dec=%d, Octal=%#o, hex=%#x",x,x,x);         //十六进制中，x可大写可小写 
	return 0;
}
