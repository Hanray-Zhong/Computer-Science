#include "stdio.h"
enum week {SUN,MON,TUE,WED,THU,FRI,SAT};
int main(void)
{
    enum week day;
    char *week_name[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    for(day=SUN;day<=SAT;day++
        printf("\n %3d \t %s",day,week_name[day ]);
    getchar();
    return 0;
}
