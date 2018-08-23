#include<stdio.h>
#include<math.h>
#define s(a,b,c) ((a)+(b)+(c))/2
#define AREA(s,a,b,c) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))
int main(void)
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		printf("%d ",s(a,b,c));
		printf("%lf\n",AREA(s(a,b,c),(double)a,b,c)); 
	}
	return 0;
}
