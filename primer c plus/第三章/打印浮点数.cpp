#include <stdio.h>
int main(void)
{
	float about=32000.0;
	double abet=2.14e9;
	long double dip=5.32e-5;
	
	printf("%f can be written %e\n",about,about);
	printf("And it's %a in hex, powers of 2 notation\n",about);
	printf("%f can be written %e\n",abet,abet);
	printf("%Lf can be written %Le\n",dip,dip);           //并不知道发生了什么。。。 
	return 0;
 } 
