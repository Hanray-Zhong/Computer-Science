#include<stdio.h>
#include<string.h>
int find(int,int,int []);
int main(void)
{
	int n,i,j,find_score;
	printf("请输入n：");
	scanf("%d",&n);
	getchar();
	char name[n][20];
    int score[n];
	printf("请输入同学的名字和成绩：\n");
	for(i=0;i<n;i++) 
	{
	    scanf("%s %d",name[i],&score[i]);
	    getchar();
    }
	j=0; 
	while(j<=n-1)                      //冒泡法排序 
	{
	    for(i=0;i<=n-2;i++)
	    {
		    if(score[i]<score[i+1])
	    	{
                int t;
                char s[20];
                t=score[i],strcpy(s,name[i]);
                score[i]=score[i+1],strcpy(name[i],name[i+1]);
                score[i+1]=t,strcpy(name[i+1],s);
            }
	    }
	j++;
	}
	printf("排序后为：\n");
	for(i=0;i<n;i++) printf("%s:%d\n",name[i],score[i]);
	printf("请输入你想要查找的分数：");
	scanf("%d",&find_score);
	getchar();
	int t=find(find_score,n,score);
	if(t==-1)
	    printf("Not found!");
	else 
	    printf("%s:%d\n",name[t],score[t]);
	getchar();
	return 0;
}
int find(int find_score,int n,int s[])      //二分法查找 
{
	int start=0,end,mid;
	end=n-1;
	while(end>=start)
	{
		mid=(start+end)/2;
		if(s[mid]==find_score) return mid;
		else
		{
		    if(s[mid]>find_score) start=mid+1;
		    else end=mid-1;
	    }
	}
	return -1;
}
