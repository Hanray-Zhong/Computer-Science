 #include <stdio.h>
int function1(int,int);
int main(void)

{
	int a,b;
	
	scanf("%d %d",&a,&b);
	while((a!=0)||(b!=0))
	{
		printf("%d %d\n",function1(a,b),a*b/function1(a,b));
		break;
	}
	return 0;
}

/*********求最大公约数**********/
int function1(int a,int b)
{
	if(a<b)
	{
		int t;
		t=a;a=b;b=t;
	}
	int i=1;
	int j;
	while(i<=b)
	{
		if((a%i==0)&&(b%i==0))
		    j=i;
		i++;
	}
	return j;
 } 
