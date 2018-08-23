#include<stdio.h>
#define M 3
#define N 5
int main(void)
{
    char courses[M][30],students[N][20];
    float tables[N][M];
    int c,s;
    char *co=&courses[0][0];
    char *st=&students[0][0];
    float *gr=&tables[0][0];
    for(c=0;c<M;c++)
    {
        printf("请输入第 %d 门课程的名字：\n",c+1);
        scanf("%s", courses[c]);
        getchar();
    }
    for(s=0;s<N;s++)
    {
        printf("请输入第 %d 个学生的名字\n",s+1);
        scanf("%s",students[s]);
        getchar();
    }
    for(s=0;s<N;s++)
    {
        printf("学生 %s ：\n",students[s]);
        printf("输入他的成绩:\n");
        for(c=0;c<M;c++)
    	{
            printf("请输入 %s 的成绩： \n",courses[c]);
            scanf("%f",&tables[s][c]);
            getchar();
    	}
    }
    float sum=0;
    for(s=0;s<N;s++)
    {
        sum=0;
    	printf(" %s 的各门课程的平均成绩为:\n",st+s*20);
    	for(c=0;c<M;c++) sum+=*(gr+s*M+c);
	    printf("%f\n",sum/M);
    }
    float sum_=0;
    for(c=0;c<M;c++)
    {
        sum_=0;
    	printf("对于 %s ，全班的平均成绩为:\n",co+c*30);
    	for(s=0;s<N;s++)sum_+=*(gr+s*M+c);
	    printf("%f\n",sum_/N);
    }
    for(c=0;c<M;c++)
    {
        sum_=0;
        printf("低于 %s 课程平均分的人数为：\n",co+c*30);
        int cou=0;
        for(s=0;s<N;s++) 
    sum_+=*(gr+s*M+c);
        for(s=0;s<N;s++)
        {
            if(*(gr+s*M+c)<sum_/N) cou++;
		}
        printf("%d\n",cou);
        cou=0; 
	}
    for(c=0;c<M;c++)
    {
        printf("对于 %s 课程，全班不及格人数为：\n",co+c*30);
        int cou=0;
        for(s=0;s < N;s++)
        {
            if(*(gr+s*M+c)<60)cou++; 
		}
        printf("%d\n",cou);
        cou=0; 
	}
    for(c=0;c<M;c++)
	{
        printf( "对于课程 %s ,全班90分(含90分)以上的人数为:\n",co+c*30);
        int cou=0;
        for(s=0;s<N;s++)
        {
            if(*(gr+s*M+c)>=90) cou++;
		}
        printf("%d\n",cou );
        cou=0; 
	}
	getchar();
    return 0 ;
}
