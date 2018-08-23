#include <stdio.h>
#include <stdlib.h>
#define N 8
int queen[N],num=1;
void set(int line);
int judge(int line);
void print(void);

int main()
{
    set(0);        /*从第0行开始放皇后，然后向下递归*/
    return 0;
}

void set(int line)
{
    int i;
    for (i=0;i<N;i++)
    {
        queen[line]=i;
        if (judge(line))
        {
            if (line==N-1)
                print();
            else
                set(line+1);
        }
    }
}

int judge(int line) 
{
    int i;
    for (i=0;i<line;i++)
        if (queen[i]==queen[line]||abs(queen[i]-queen[line])==line-i)
            return 0;
    return 1;
}

void print(void)
{
    int i;
    printf("第%d种解决方案：\n",num);
    num++;
    for (i=0;i<N;i++)
        printf("(%d,%d) ",i,queen[i]);
    putchar('\n');
    return;
}
