#include<stdio.h>
int main(void)
{
	int x=100;
	printf("Dec=%d, Octal=%o, hex=%x\n",x,x,x);         //octal�˽���    hexʮ������ 
	printf("Dec=%d, Octal=%#o, hex=%#x",x,x,x);         //ʮ�������У�x�ɴ�д��Сд 
	return 0;
}
