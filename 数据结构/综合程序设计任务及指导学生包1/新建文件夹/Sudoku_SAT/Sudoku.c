#include "head.h"
/*
*****************************
Sudoku()用于生成一个数独格局，并用SAT相关知识解决问题
无输入，输出为转化的cnf公式文件及数独的解
*****************************
*/
void Sudoku(void)
{
    int sud[9][9];//用于保存数独格局，0表示当前格子无数字
    int i;
    int j;
    Formula S;//用于存储公式
    int *Varies;//用于保存变元真值关系
    Varies=NULL;
    hole*  holes;//空格数组
    int hole_num;//空格数
    hole_num=0;

    system("cls");
    printf("\n现在开始随机生成一个数独格局并转化为SAT问题解决！\n\n");
    printf("------------------------------------\n\n");

    //创建数独数组9×9格局
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            sud[i][j]=0;//初始格局为空
        }
    }
    createFinalSud(sud);//生成数独最终格局

    hole_num=createSudProblem(sud);//通过全盘随机，挖洞法生成数独格局

    //展示生成的数独问题格局
    system("cls");
    printf("\n生成的数独问题格局如下：\n\n");
    printf("        -------------------\n");
    for(i=0;i<9;i++)
    {
        printf("\t|");
        for(j=0;j<9;j++)
        {
            if(sud[i][j])
                printf("%d|",sud[i][j]);
            else
                printf(" |");
        }
        printf("\n");
    }
    printf("        -------------------\n\n");

    //数独问题转化为SAT问题
    holes=(hole*)malloc(hole_num*sizeof(hole));//开辟空格数组的空间
    S.num_st=0;//初始化公式
    S.num_v=0;
    S.root=NULL;
    S.sta=-1;
    Varies=transfSud(sud,&S,holes);

    //输出cnf文件
    cnfToFile(&S);

    //利用dpll算法解决数独产生的SAT问题
    solver(&S,Varies);

    //输出dpll算法求出的解
    showSudResult(Varies,holes,sud);
}
