#include "head.h"
void main(void) {
	system("cls");
	long time_start = 0;//记录程序开始时间
	long time_end = 0;	//记录程序结束时间

	int choice = 0;
	printf("1、通过文件生成cnf范式并验证其可满足性\n\n");
	printf("2、随机生成一个数独并进行求解\n\n");
	printf("------------------------------------\n");
	printf("   并输入相应序号【1||2】:\n");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
		case 1:SAT(time_start, time_end);
		case 2:Sudoku();
		default:printf("输入非法\n");
	}
	system("pause");
}