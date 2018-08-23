#include<stdio.h>
enum month {January,February,March,April,May,June,July,August,September,October,November,December};
int main(void)
{
	int year;
    scanf("%d",&year);
    getchar();
    int days1[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int days2[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char *name[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    if((year%4==0)&&(year%100!=0)||(year%400==0)){
    printf("%s,%d\n",name[January],days1[January]);
    printf("%s,%d\n",name[February],days1[February]);
    printf("%s,%d\n",name[March],days1[March]);
    printf("%s,%d\n",name[April],days1[April]);
    printf("%s,%d\n",name[May],days1[May]);
    printf("%s,%d\n",name[June],days1[June]);
    printf("%s,%d\n",name[July],days1[July]);
    printf("%s,%d\n",name[August],days1[August]);
    printf("%s,%d\n",name[September],days1[September]);
    printf("%s,%d\n",name[October],days1[October]);
    printf("%s,%d\n",name[November],days1[November]);
    printf("%s,%d\n",name[December],days1[December]);
    }
    else
    {
	printf("%s,%d\n",name[January],days2[January]);
    printf("%s,%d\n",name[February],days2[February]);
    printf("%s,%d\n",name[March],days2[March]);
    printf("%s,%d\n",name[April],days2[April]);
    printf("%s,%d\n",name[May],days2[May]);
    printf("%s,%d\n",name[June],days2[June]);
    printf("%s,%d\n",name[July],days2[July]);
    printf("%s,%d\n",name[August],days2[August]);
    printf("%s,%d\n",name[September],days2[September]);
    printf("%s,%d\n",name[October],days2[October]);
    printf("%s,%d\n",name[November],days2[November]);
    printf("%s,%d\n",name[December],days2[December]);
    }
    return 0;
}
