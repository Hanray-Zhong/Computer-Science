#include "head.h"
/*通过cnf文件生成cnf范式*/
void CNF_Reader(FILE* fp, Formula* formula) {
	char buff[1000];//存储注释
	//将注释存到buff数组中
	while (fgetc(fp) == 'c') {
		fgets(buff, 1000, fp);
	}
	//通过fscanf读取变元数和子句数
	int i;
	//读取“ cnf ”字符串
	for (i = 1; i <= 5; i++) {
		fgetc(fp);
	}
	//将cnf文件中给出的变元数和子句数写入公式中
	fscanf(fp, "%d %d", &(formula->num_v), &(formula->num_st));
	//读取换行符
	fgetc(fp);

	/******************根据文件创建公式*******************/
	Statement* statement;//创建子句
	formula->root = (Statement*)malloc(sizeof(Statement));
	statement = formula->root;
	statement->next = NULL;
	statement->num_lit = 0;
	for (i = 1; i <= formula->num_st; i++) {
		if (formula->root->num_lit != 0) {
			statement->next = (Statement*)malloc(sizeof(Statement));
			statement = statement->next;
			statement->next = NULL;
			statement->num_lit = 0;
		}
		//创建第一个文字
		Literal* literal;
		statement->elem = (Literal*)malloc(sizeof(Literal));
		literal = statement->elem;
		literal->next = NULL;
		int k;
		//将文件中目前读取的文字写入k
		fscanf(fp, "%d", &k);
		//完成后续文字的读取
		while (k != 0) {
			if (statement->num_lit != 0) {
				literal->next = (Literal*)malloc(sizeof(Literal));
				literal = literal->next;
				literal->next = NULL;
			}
			if (k > 0) {
				literal->pos = 1;
				literal->num = k;
			}
			else {
				literal->pos = 0;
				literal->num = (-k);
			}
			(statement->num_lit)++;//每读取一个文字，子句的文字数加一
			fscanf(fp, "%d", &k);
		}
		fgetc(fp);//读取每行子句尾的换行符
	}
}