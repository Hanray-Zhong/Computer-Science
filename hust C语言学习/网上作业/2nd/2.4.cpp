#include <stdio.h>
int main(void)
{
	int x,y;
	while((scanf("%d",&x))==1){
		y=(x%3==0&&(x%5==0&&x%10!=0));
		printf("%d\n",y);
	}
    return 0;
}
