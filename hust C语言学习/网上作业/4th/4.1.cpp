#include <stdio.h>
int main(void)
{
	int year,month,day,amount;
    scanf("%d %d %d",&year,&month,&day);
		if((((year%4==0)&&(year%100!=0)))||(year%400==0))
		{
			switch(month-1)
	    {
		case 0:amount=day;break;
		case 1:amount=(day+31);break;
		case 2:amount=(day+31+29);break;
		case 3:amount=(day+31+29+31);break;
		case 4:amount=(day+31+29+31+30);break;
		case 5:amount=(day+31+29+31+30+31);break;
		case 6:amount=(day+31+29+31+30+31+30);break;
		case 7:amount=(day+31+29+31+30+31+30+31);break;
		case 8:amount=(day+31+29+31+30+31+30+31+31);break;
		case 9:amount=(day+31+29+31+30+31+30+31+31+30);break;
		case 10:amount=(day+31+29+31+30+31+30+31+31+30+31);break;
		case 11:amount=(day+31+29+31+30+31+30+31+31+30+31+30);break;
	    }
			printf("该日期是这一年中的第%d天\n",amount);
		}
		else
		{
			switch(month-1)
	    {
		case 0:amount=day;break;
		case 1:amount=(day-1+31);break;
		case 2:amount=(day-1+31+29);break;
		case 3:amount=(day-1+31+29+31);break;
		case 4:amount=(day-1+31+29+31+30);break;
		case 5:amount=(day-1+31+29+31+30+31);break;
		case 6:amount=(day-1+31+29+31+30+31+30);break;
		case 7:amount=(day-1+31+29+31+30+31+30+31);break;
		case 8:amount=(day-1+31+29+31+30+31+30+31+31);break;
		case 9:amount=(day-1+31+29+31+30+31+30+31+31+30);break;
		case 10:amount=(day-1+31+29+31+30+31+30+31+31+30+31);break;
		case 11:amount=(day-1+31+29+31+30+31+30+31+31+30+31+30);break;
	    }
			printf("该日期是这一年中的第%d天\n",amount);
		}
	
	return 0;
}
