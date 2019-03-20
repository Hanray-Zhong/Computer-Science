#include "head.h"
/*
*****************************
Sudoku()��������һ��������֣�����SAT���֪ʶ�������
�����룬���Ϊת����cnf��ʽ�ļ��������Ľ�
*****************************
*/
void Sudoku(void)
{
    int sud[9][9];//���ڱ���������֣�0��ʾ��ǰ����������
    int i;
    int j;
    Formula S;//���ڴ洢��ʽ
    int *Varies;//���ڱ����Ԫ��ֵ��ϵ
    Varies=NULL;
    hole*  holes;//�ո�����
    int hole_num;//�ո���
    hole_num=0;

    system("cls");
    printf("\n���ڿ�ʼ�������һ��������ֲ�ת��ΪSAT��������\n\n");
    printf("------------------------------------\n\n");

    //������������9��9���
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            sud[i][j]=0;//��ʼ���Ϊ��
        }
    }
    createFinalSud(sud);//�����������ո��

    hole_num=createSudProblem(sud);//ͨ��ȫ��������ڶ��������������

    //չʾ���ɵ�����������
    system("cls");
    printf("\n���ɵ��������������£�\n\n");
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

    //��������ת��ΪSAT����
    holes=(hole*)malloc(hole_num*sizeof(hole));//���ٿո�����Ŀռ�
    S.num_st=0;//��ʼ����ʽ
    S.num_v=0;
    S.root=NULL;
    S.sta=-1;
    Varies=transfSud(sud,&S,holes);

    //���cnf�ļ�
    cnfToFile(&S);

    //����dpll�㷨�������������SAT����
    solver(&S,Varies);

    //���dpll�㷨����Ľ�
    showSudResult(Varies,holes,sud);
}
