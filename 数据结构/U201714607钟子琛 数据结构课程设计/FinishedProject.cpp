#include "head.h"
#include "conio.h"
void main(void) {
	int choice = 1;
	while (choice != 0) {
		fflush(stdin);
		long time_start = 0;//记录程序开始时间
		long time_end = 0;	//记录程序结束时间
		printf("1、通过文件生成cnf范式并求解\n\n");
		printf("2、随机生成一个数独并求解\n\n");
		printf("0、退出\n\n");
		printf("------------------------------------\n");
		printf("输入相应序号:\n");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:SAT(time_start, time_end); break;
		case 2:Sudoku(time_start, time_end); break;
		case 0:break;
		default:printf("输入非法\n");
		}
		// setbuf(stdin, NULL);
		system("pause");
		system("cls");
	}
}