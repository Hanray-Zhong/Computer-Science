#include "head.h"
void main(void)
{
    long time_start;//记录程序开始时间
    long time_end;//记录程序结束时间
    int choice;//记录用户选择的功能
    choice=0;


    printf("\n\n欢迎来到基于SAT的数独求解游戏！\n\n");
    printf("在本游戏中\n");
    printf("您有两个选择：\n\n");
    printf("1、通过文件生成cnf范式并验证其可满足性\n\n");
    printf("2、随机生成一个数独并进行求解\n\n");
    printf("------------------------------------\n");
    printf("选择游戏，并输入相应序号【1||2】:\n");
    scanf("%d",&choice);
    while(choice!=1&&choice!=2)
    {
        printf("请输入正确的序号【1或2】！\n");
        printf("选择游戏，并输入相应序号:\n");
        scanf("%d",&choice);
    }
    if(choice==1)
        SAT(time_start,time_end);
    else
        Sudoku();
}
