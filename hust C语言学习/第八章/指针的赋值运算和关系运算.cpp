#include <stdio.h>
int main(void)
{
	long x=0x1234ABCD,k;
	char *p=(char *)&x;           //(char *) 强制类型转换
	char up_half, low_half;
	for(k=0;k<4;k++)
	{
		low_half=(*p) & 0x0f;          //取低四位
		if(low_half<10) low_half|='0';
		else low_half=(low_half-10)+'A';
		up_half=(*p>>4)&0x0f;
		if(up_half<10) up_half|='0';
		else up_half=(up_half-10)+'A';
		p++;
		printf("%c   %c\n",up_half,low_half);
	} 
	return 0;
}
