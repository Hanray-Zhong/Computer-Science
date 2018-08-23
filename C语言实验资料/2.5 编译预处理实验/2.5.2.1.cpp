#include<stdio.h>                 //1st
int max(int,int,int);             //2nd
float sum(float,float);           //3rd
int main(void)                    //4th
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
int max(int x, int y, int z)
{
   int t;
   if (x>y)
     t=x;
   else
     t=y;
   if (t<z)
     t=z;
   return t;
}
float sum(float x, float y)
{
  return x+y;
}

