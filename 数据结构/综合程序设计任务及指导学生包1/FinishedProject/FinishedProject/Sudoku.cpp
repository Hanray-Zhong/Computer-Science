#include "head.h"


/*
生成一个数独格局，并用SAT相关知识解决问题
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
	printf("\n随机生成一个数独格局并转化为SAT问题解决\n\n");
	printf("------------------------------------\n\n");

	//创建数独数组9×9格局
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			sud[i][j] = 0;//初始格局为空
		}
	}
	CreateFinalSud(sud);//生成数独最终格局

	//生成完成了一个数独
	hole_num = CreateSudoku(sud);

	//展示生成的数独问题格局
	system("cls");
	printf("\n生成的数独：\n\n");
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

	//数独问题转化为SAT问题
	holes = (hole*)malloc(hole_num * sizeof(hole));
	formula.num_st = 0;
	formula.num_v = 0;
	formula.root = NULL;
	formula.sta = -1;
	Varies = TransfSud(sud, &formula, holes);

	//输出cnf文件
	CnfToFile(&formula);

	//利用dpll算法解决数独产生的SAT问题
	Solver(&formula, Varies);

	//输出dpll算法求出的解
	ShowSudResult(Varies, holes, sud);
}