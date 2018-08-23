#include <stdio.h>
int main()
{
    int a=3,b=2,c=5;
    if((a>b)&&(a>c))
      printf("%d",a);
    else
      if(b>c)
        printf("%d",b);
      else
        printf("%d",c);
    getchar();
    return 0;        
}
