#include "head.h"
/*SAT问题求解：通过读取cnf文件，求出其生成的cnf范式的解*/
void SAT(long time_start, long time_end) {
	system("cls");
	FILE* fp;
	char filename[100];
	Formula formula;	//保存生成的cnf范式
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
		printf("文件打开失败\n");
		return;
	}
	printf("文件打开成功\n");
	CNF_Reader(fp, &formula);
	fclose(fp);
	/**************CNF文件读取完毕**************/


	/****运用SAT_Solver验证cnf范式的可满足性*****/
	Varies = (int*)malloc((formula.num_v + 1) * sizeof(int));
	int i;
	//初始化Varies
	for (i = 1; i <= formula.num_v; i++) {
		Varies[i] = -1;
	}
	//开始计时
	time_start = clock();
	SAT = Solver(&formula, Varies);
	time_end = clock();//记录程序结束时间
	/******************************************/

	if (SAT == 1) {
		if (Check(Varies, &formula) == true) {
			printf("经验证，结果正确\n");
		}
		else {
			printf("经验证，结果错误\n");
		}
	}

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
			if (Varies[i]) {
				printf("%d ", i);
				fprintf(fp, "%d ", i);
			}
			else {
				printf("-%d ", i);
				fprintf(fp, "-%d ", i);
			}
		}
		printf("\n");
		fprintf(fp, "\n");
	}
	//输出程序运行时间
	long k;
	k = (time_end - time_start);
	c = 't';
	printf("%c %ldms\n", c, k);
	fprintf(fp, "%c\t", c);
	fprintf(fp, "%ld\n", k);
	fclose(fp);	
}

bool Check(int* Varies_res, Formula* formula) {
	//找每一个子句
	for (int i = 0; i < formula->num_st; i++) {
		//找到子句的每一个文字
		for (int j = 0; j < SearchStatement(i, formula)->num_lit; j++) {
			if (SearchLiteral(j, SearchStatement(i, formula))->pos == Varies_res[SearchLiteral(j, SearchStatement(i, formula))->num]) {
				//一个文字是真的，直接下一条语句
				break;
			}
			else {
				//已经检索到最后一个文字
				if (j == SearchStatement(i, formula)->num_lit - 1) {
					return false;
				}
			}
		}
	}
	return true;
}

Statement* SearchStatement(int k, Formula* formula) {
	Statement* res = formula->root;
	for (int i = 0; i <= formula->num_st; i++) {
		if (i == k) {
			return res;
		}
		else {
			res = res->next;
		}
	}
	printf("ERROR!Beyond the range!");
	return NULL;
}

Literal* SearchLiteral(int k, Statement* statement) {
	Literal* res = statement->elem;
	for (int i = 0; i <= statement->num_lit; i++) {
		if (i == k) {
			return res;
		}
		else {
			res = res->next;
		}
	}
	printf("ERROR!Beyond the range!");
	return NULL;
}