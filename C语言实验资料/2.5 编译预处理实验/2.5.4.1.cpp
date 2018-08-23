#include<stdio.h>
#include<math.h>
#define s(a,b,c) ((a)+(b)+(c))/2
#define AREA(s,a,b,c) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))
int main(void)
{
	int a,b,c;
	printf("输入三角形的三条边的长度：");
	scanf("%d %d %d",&a,&b,&c);
	getchar();
	while(a+b<=c||a+c<=b||b+c<=a) 
	{
	    printf("无法形成三角形！请重新输入:");
	    scanf("%d %d %d",&a,&b,&c);
	    getchar();
	}	 
    printf("s=%d ",s(a,b,c));
	printf("area=%lf\n",AREA(s(a,b,c),(double)a,b,c)); 
	getchar();
	return 0;
}
