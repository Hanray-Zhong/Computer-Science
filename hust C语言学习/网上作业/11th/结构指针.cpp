#include<stdio.h>
struct Student
{
    int num;
	char name[19]; 
	double score;
}s[3],*p;
int main(void)
{
	int j,i,N;
	scanf("%d",&N);
	for(j=1;j<=N;j++)
	{
	    for(i=0;i<=2;i++)
	        scanf("%d %s %lf",&s[i].num,s[i].name,&s[i].score);
        p=s;
        for(i=0;i<=2;i++)
            printf("%d\t%-20s%lf\n",s[i].num,s[i].name,s[i].score);
        for(i=0;i<=2;i++)
            printf("%d\t%-20s%lf\n",(p+i)->num,(p+i)->name,(p+i)->score);
	}
	return 0;
}
