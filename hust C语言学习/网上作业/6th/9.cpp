c#include<stdio.h>
#include<math.h>
int main(void)
{
	int times,i;
	float p,a,b,c;
	float area;
	
	scanf("%d",&times);
	for(i=1;i<=times;i++)
	{
		scanf("%f %f %f",&a,&b,&c);
		p=(a+b+c)/2.0;
		area=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("area=%f\n",area);
	}
	return 0;
}
