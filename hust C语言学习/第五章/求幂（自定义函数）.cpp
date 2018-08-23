#include <stdio.h>
#include <math.h>
void Math(int);

int main(void)
{
	int i=1;
	
	printf("Int\tSquare\tCube\tQuartic\tQuintic\n");
    while(i<=10)
    {
	    printf("%d\t",i);
        Math(i);
        printf("\n");
	    i++;
	}
	return 0;
}

void Math(int x)
{
	int i=1,j,n;
	n=x;
	
	while(i<=4)
	{
		x=n;
		j=1;
		while(j<=i)
		{
			x=x*n;
			j++;
		}
		printf("%d\t",x);
		i++;
	}
}
