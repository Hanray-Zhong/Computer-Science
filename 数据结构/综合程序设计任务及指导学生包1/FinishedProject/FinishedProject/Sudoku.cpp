#include "head.h"


/*
����һ��������֣�����SAT���֪ʶ�������
*/
void Sudoku(void) {
	int sud[9][9];
	int i;
	int j;
	Formula formula;
	int *Varies;
	Varies = NULL;
	hole*  holes;
	int hole_num;
	hole_num = 0;

	system("cls");
	printf("\n�������һ��������ֲ�ת��ΪSAT������\n\n");
	printf("------------------------------------\n\n");

	//������������9��9���
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			sud[i][j] = 0;//��ʼ���Ϊ��
		}
	}
	CreateFinalSud(sud);//�����������ո��

	//���������һ������
	hole_num = CreateSudoku(sud);

	//չʾ���ɵ�����������
	system("cls");
	printf("\n���ɵ�������\n\n");
	printf("        -------------------\n");
	for (i = 0; i < 9; i++)
	{
		printf("\t|");
		for (j = 0; j < 9; j++)
		{
			if (sud[i][j])
				printf("%d|", sud[i][j]);
			else
				printf(" |");
		}
		printf("\n");
	}
	printf("        -------------------\n\n");

	//��������ת��ΪSAT����
	holes = (hole*)malloc(hole_num * sizeof(hole));
	formula.num_st = 0;
	formula.num_v = 0;
	formula.root = NULL;
	formula.sta = -1;
	Varies = TransfSud(sud, &formula, holes);

	//���cnf�ļ�
	CnfToFile(&formula);

	//����dpll�㷨�������������SAT����
	Solver(&formula, Varies);

	//���dpll�㷨����Ľ�
	ShowSudResult(Varies, holes, sud);
}