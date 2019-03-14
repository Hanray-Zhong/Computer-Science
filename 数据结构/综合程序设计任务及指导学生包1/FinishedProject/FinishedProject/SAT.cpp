#include "head.h"
/*通过文件生成cnf范式并验证其可满足性*/
void SAT(long time_start, long time_end) {
	system("cls");
	FILE* fp;
	char filename[100];
	Formula formula;	//保存生成的公式
	int SAT;			//cnf可满足性标记，0为不满足，1为满足

	int* Varies = NULL;	//保存所有变元信息，0为假，1为真，-1为不确定

	//formula初始化
	formula.sta = -1;
	formula.num_st = 0;
	formula.root = NULL;

	/***************CNF文件读取***************/
	printf("输入文件名：\n");
	scanf("%s", filename);
	getchar();
	fp = fopen(filename, "r");
	if (!fp) {
		printf("文件打开失败！\n");
		return;
	}
	printf("文件打开成功");
	CNF_Reader(fp, &formula);//生成cnf公式
	fclose(fp);
	/**************CNF文件读取完毕**************/


	/****运用SAT_Solver验证cnf范式的可满足性*****/
	Varies = (int*)malloc((formula.num_v + 1) * sizeof(int));
	int i;
	// 初始化Varies
	for (i = 1; i <= formula.num_v; i++) {
		Varies[i] = -1;
	}
	//开始计时
	time_start = clock();
	SAT = Solver(&formula, Varies);
	time_end = clock();//记录程序结束时间
	/******************************************/

	/*输出验证结果*/
	//将文件名改为以.res结尾
	int str_length;
	str_length = strlen(filename);
	char str[] = ".res";
	strcpy(filename + str_length - 4, str);
	fp = fopen(filename, "w");//打开一个与算例同名的res文件
	if (!fp)
	{
		printf("文件打开失败！\n");
	}
	//输出可满足性
	printf("s %d\n", SAT);
	//向文件中写入可满足性
	char c = 's';
	fprintf(fp, "%c\t", c);
	fprintf(fp, "%d\n", SAT);
	//文件可满足时，输出一组真值，并向文件中写入一组真值
	if (SAT == 1) {
		c = 'v';
		printf("%c ", c);
		fprintf(fp, "%c\t", c);
		for (i = 1; i <= formula.num_v; i++) {
			//根据value值判断输出，当value为1时输出为正，当value为0或-1时输出为负
			if (Varies[i]) {
				printf("%d ", i);
				fprintf(fp, "%d ", i);
			}
			else {
				printf("-%d ", i);
				int k = -i;
				fprintf(fp, "%d ", k);
			}
		}
		printf("\n");
		fprintf(fp, "\n");
	}
	//输出程序运行时间
	long k;
	k = time_end - time_start;
	c = 't';
	printf("%c %ld", c, k);
	fprintf(fp, "%c\t", c);
	fprintf(fp, "%ld", k);
	fclose(fp);
}
