 #include <stdio.h>
int function1(int,int);
int function2(int,int);
int main(void)

{
	int a,b;
	
	scanf("%d %d",&a,&b);
	while((a!=0)||(b!=0))
	{
		printf("%d %d\n",function1(a,b),function2(a,b));
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
 
 /*******求最小公倍数*********/
 int function2(int a,int b)
 {
 	if(a<b)
 	{
 		int t;
 		t=a;a=b;b=t;
	}
	int i=a;
	while(i>=a)
	{
		if((i%a==0)&&(i%b==0))
		{
			return i;
		}
		else
		i++;
	} 
  } 
