#include <stdio.h>
int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
		if(a<b)
		{
			if(a<c)
			{
				if(b<=c) printf("B:%d\n",b);
				else printf("C:%d\n",c);
			}
			else    //a>=c
			    printf("A:%d\n",a);
		}
		else       //a>=b
		{
			if(a<=c) printf("A:%d\n",a);
			else //a>c
			{
				if(b>c)
				{
					if(a==b) printf("A:%d\n",a);
					else printf("B:%d\n",b);
				}
				else //b<=c
				{
					if(b==c) printf("B:%d\n",b);
					else printf("C:%d\n",c);
				}
			}
		}
	return 0;
	
}
