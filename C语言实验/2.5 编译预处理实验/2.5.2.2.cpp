#include<stdio.h>
#define max(x,y,z) ((((x)>(y))?(x):(y))<(z))?(z):(((x)>(y))?(x):(y))
float sum(float,float);
int main(void)
{
    int a, b, c;
    float d, e;
    printf("Enter three integers:");
    scanf("%d,%d,%d",&a,&b,&c);
    getchar();
    printf("\nthe maximum of them is %d\n",max(a,b,c));

    printf("Enter two floating point numbers:");
    scanf("%f,%f",&d,&e);
    getchar();
    printf("\nthe sum of them is  %f\n",sum(d,e));
    getchar();
    return 0;
}

float sum(float x, float y)
{
  return x+y;
}

