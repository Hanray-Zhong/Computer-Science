#include <stdio.h>
#include <limits.h>

void PrintBit(int x)
{
	int i;
	int n=sizeof(int)*CHAR_BIT;
	int mask=1<<(n-1);
	for(i=1;i<=n;++i) {
		putchar(!(x&mask)?'0':'1');
		x<<=1;
		if(!(i%CHAR_BIT)&&i<n) putchar(' ');
	}
}


int main(void)
{
	unsigned int x;
	int p,n;
	scanf("%d%d%d",&x,&p,&n);
	PrintBit(x);
    printf("\n");
	int part1,part2;
	part1=(x>>(p)<<(p+32-(p+n))>>(32-(p+n)));
	part2=~part1;
	part2=(part2>>p&(~(~0<<n)))<<p;
	x=(x-part1)+part2;
	PrintBit(x);
	printf("\n");
	return 0;
}
