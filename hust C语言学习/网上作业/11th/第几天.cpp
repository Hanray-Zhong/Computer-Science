#include<stdio.h>
int main(void)
{
	int N,i,amount;
	scanf("%d",&N); 
	struct time
	{
		int year;
		int month;
		int day;
	}date[N];
	getchar();
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&date[i].year,&date[i].month,&date[i].day);
		getchar();
	}
	for(i=0;i<N;i++)
	{
	    if((((date[i].year%4==0)&&(date[i].year%100!=0)))||(date[i].year%400==0))
	    {
		    switch(date[i].month-1)
            {
	            case 0:amount=date[i].day;break;
            	case 1:amount=(date[i].day+31);break;
	            case 2:amount=(date[i].day+31+29);break;
            	case 3:amount=(date[i].day+31+29+31);break;
            	case 4:amount=(date[i].day+31+29+31+30);break;
            	case 5:amount=(date[i].day+31+29+31+30+31);break;
        		case 6:amount=(date[i].day+31+29+31+30+31+30);break;
	            case 7:amount=(date[i].day+31+29+31+30+31+30+31);break;
        		case 8:amount=(date[i].day+31+29+31+30+31+30+31+31);break;
            	case 9:amount=(date[i].day+31+29+31+30+31+30+31+31+30);break;
	            case 10:amount=(date[i].day+31+29+31+30+31+30+31+31+30+31);break;
        		case 11:amount=(date[i].day+31+29+31+30+31+30+31+31+30+31+30);break;
            }
			printf("%d\n",amount);
		}
		else
		{
			switch(date[i].month-1)
	        {
		        case 0:amount=date[i].day;break;
		        case 1:amount=(date[i].day-1+31);break;
		        case 2:amount=(date[i].day-1+31+29);break;
		        case 3:amount=(date[i].day-1+31+29+31);break;
		        case 4:amount=(date[i].day-1+31+29+31+30);break;
		        case 5:amount=(date[i].day-1+31+29+31+30+31);break;
		        case 6:amount=(date[i].day-1+31+29+31+30+31+30);break;
		        case 7:amount=(date[i].day-1+31+29+31+30+31+30+31);break;
		        case 8:amount=(date[i].day-1+31+29+31+30+31+30+31+31);break;
		        case 9:amount=(date[i].day-1+31+29+31+30+31+30+31+31+30);break;
		        case 10:amount=(date[i].day-1+31+29+31+30+31+30+31+31+30+31);break;
		        case 11:amount=(date[i].day-1+31+29+31+30+31+30+31+31+30+31+30);break;
	        }
			printf("%d\n",amount);
		}
	}
	return 0;
}
