#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
    int a[M],b[M];	/* 数组a存放圈中人的编号，数组b存放出圈人的编号 */
    int i, j, k;
    for(i=0;i<M;i++)			/* 对圈中人按顺序编号1-M */
        a[i]=i+1;
    for(i=M,j=0;i>1;i--)/* i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置 */
    {
        for(k=1;k<=N;k++)
		{			/* 1至N报数 */
		    if(a[j]==0)
		    {
		    	k--;
		    	j++;
		    	continue; 
			}
            if(++j>9) j=0;
		}/* 最后一个人报数后第一个人接着报，形成一个圈 */
        b[M-i]=(j?a[j-1]:a[9]);
        (j?a[j-1]:a[9])=0;                         /*将圈外的标0*/
    }
    for(i=0;i<M;i++) 
	    if(a[i]!=0) b[M-1]=a[i];               /*找到最后一个数*/
    for(i=0;i<M;i++)		/* 按次序输出出圈人的编号 */
        printf("%6d", b[i]);
    getchar();
    return 0;
}	
