#include "head.h"

void CreateFinalSud(int(*sud)[9]) {
	int i;
	int j;
	int k;
	int a;
	//在数独格局中给定最初的位于数独格局中央的3×3格局
	k = 1;
	while (k <= 9) { //由1到9依次赋值
		for (i = 3; i < 6; i++) {
			for (j = 3; j < 6; j++) {
				sud[i][j] = k++;
			}
		}
	}
	//得到初始3×3格局左右3×3位置中的数字
	srand((unsigned)time(NULL));
	k = rand() % 2;//通过随机数决定完全行变换产生的3×3格局的左右位置
	if (k == 1) {
		//初始化左边
		for (j = 0; j < 3; j++) {
			sud[3][j] = sud[5][j + 3];
		}
		for (i = 4; i < 6; i++) {
			for (j = 0; j < 3; j++) {
				sud[i][j] = sud[i - 1][j + 3];
			}
		}
		//初始化右边
		for (j = 6; j < 9; j++) {
			sud[5][j] = sud[3][j - 3];
		}
		for (i = 3; i < 5; i++) {
			for (j = 6; j < 9; j++) {
				sud[i][j] = sud[i + 1][j - 3];
			}
		}
	}
	else {
		//初始化左边
		for (j = 0; j < 3; j++) {
			sud[5][j] = sud[3][j + 3];
		}
		for (i = 3; i < 5; i++) {
			for (j = 0; j < 3; j++) {
				sud[i][j] = sud[i + 1][j + 3];
			}
		}
		//初始化右边
		for (j = 6; j < 9; j++) {
			sud[3][j] = sud[5][j - 3];
		}
		for (i = 4; i < 6; i++) {
			for (j = 6; j < 9; j++) {
				sud[i][j] = sud[i - 1][j - 3];
			}
		}
	}
	//通过列变换得到其他3×3格局
	for (a = 0; a < 9; a += 3) {
		k = rand() % 2;//每个列变换具有两种可能
		if (k == 1) {
			//初始化上边
			for (i = 0; i < 3; i++) {
				sud[i][a] = sud[i + 3][a + 2];
			}
			for (j = a + 1; j < a + 3; j++) {
				for (i = 0; i < 3; i++) {
					sud[i][j] = sud[i + 3][j - 1];
				}
			}
			//初始化下边
			for (i = 6; i < 9; i++) {
				sud[i][a + 2] = sud[i - 3][a];
			}
			for (j = a; j < a + 2; j++) {
				for (i = 6; i < 9; i++) {
					sud[i][j] = sud[i - 3][j + 1];
				}
			}
		}
		else {
			//初始化上边
			for (i = 0; i < 3; i++) {
				sud[i][a + 2] = sud[i + 3][a];
			}
			for (j = a; j < a + 2; j++) {
				for (i = 0; i < 3; i++) {
					sud[i][j] = sud[i + 3][j + 1];
				}
			}
			//初始化下边
			for (i = 6; i < 9; i++) {
				sud[i][a] = sud[i - 3][a + 2];
			}
			for (j = a + 1; j < a + 3; j++) {
				for (i = 6; i < 9; i++) {
					sud[i][j] = sud[i - 3][j - 1];
				}
			}
		}
	}
}

/*
creatSudProblem用于产生数独问题
*/
int CreateSudoku(int(*sud)[9]) {
	int level;
	int hole_num;
	int i;
	//记录挖洞位置
	int hole_x;
	int hole_y;

	//生成挖洞数
	printf("------------------------------------\n");
	printf("输入数字选择难度：【1~3】\n");
	printf("1、easy\n2、normal\n3、evil\n\n");

	scanf("%d", &level);
	while (level > 3 || level < 1)
		printf("输入非法,重新输入：\n");
	hole_num = level * 20;

	//挖洞，利用随机数生成挖洞位置
	srand((unsigned)time(NULL));
	for (i = 1; i <= hole_num; i++) {
		hole_x = rand() % 9;
		hole_y = rand() % 9;
		while (sud[hole_x][hole_y] == 0) {
			hole_x = rand() % 9;
			hole_y = rand() % 9;
		}
		sud[hole_x][hole_y] = 0;
	}
	return hole_num;
}

/*
将给定的cnf范式输入到文件中
输入为给定的cnf范式，输出一个cnf公式
*/
void CnfToFile(Formula* formula) {
	FILE* fp;
	char filename[100];
	Statement* statement;
	Literal* literal;

	printf("请输入保存文件名：\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	char str[] = ".cnf";
	strcpy(filename + strlen(filename), str);//为文件名加上后缀
	if (!fp)
		printf("文件打开失败!\n");
	else {
		time_t t;//用于输出当前时间
		struct tm* lt;
		time(&t);
		lt = localtime(&t);
		fprintf(fp, "c      in %d/%d/%d %d:%d:%d\nc\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		//输入变元数和子句数等信息
		fprintf(fp, "p cnf %d %d\n", formula->num_v, formula->num_st);
		//输入子句部分
		statement = formula->root;
		while (statement) {
			literal = statement->elem;
			while (literal) {
				if (literal->pos)
					fprintf(fp, "%d ", literal->num);
				else
					fprintf(fp, "%d ", -literal->num);
				literal = literal->next;
			}
			fprintf(fp, "0\n");
			statement = statement->next;
		}
	}
}

/*
将数独问题转化为SAT问题
算法：根据每个空格内有且仅有一个数字、1~9中的数字在每行、每列和每个宫内出现且仅出现一次创建子句，通过邻接表记录每个空格中可能出现的数字
优化思路：用9×10的数组保存每个数字可能出现的位置
*/
int* TransfSud(int(*sud)[9], Formula*S, hole* holes) {
	int* Varies;	//用于表示变元真值关系的数组
	int hole_num = 0;//用于记录空格数
	digtal* p_d;	//用于生成空格中可能出现的数字,在生成子句中用于遍历
	digtal* p_df;	//用于指向空格可能的数字的尾位置，在生成子句中用于遍历
	Statement* p_s;	//用于创建子句
	Statement* p_sf = NULL;//用于遍历公式
	Literal* p_l;	//用于创建文字
	Literal* p_lf = NULL;	//用于遍历子句
	//用作循环变量
	int i;
	int j;
	int k;
	//用于保存行列
	int x;
	int y;

	//生成空格及其可能的数字邻接表
	for (i = 0; i < 9; i++) {  //遍历格局找到每一个空格
		for (j = 0; j < 9; j++) {
			if (sud[i][j] == 0) {
				(holes + hole_num)->x = i;
				(holes + hole_num)->y = j;
				hole_num++;
			}
		}
	}
	for (i = 0; i < hole_num; i++) { //找到每个空格对应的数字
		holes[i].elem = NULL;
		p_df = NULL;
		holes[i].dig_num = 0;
		for (j = 1; j <= 9; j++) {   //遍历检查1~9中哪些数可能出现于此空格
			bool found = false;//标志此数是否已出现
			for (k = 0; k < 9 && (found == false); k++) { //在行中查找 
				if (sud[holes[i].x][k] == j)
					found = true;
			}
			for (k = 0; k < 9 && (found == false); k++) { //在列中查找
				if (sud[k][holes[i].y] == j)
					found = true;
			}
			x = (holes[i].x) / 3;//用于记录空格所在的宫
			y = (holes[i].y) / 3;
			for (int a = 3 * x; (a >= 3 * x) && (a < 3 * (x + 1)) && (found == false); a++) { //在宫中查找
				for (int b = 3 * y; (b >= 3 * y) && (b < 3 * (y + 1)) && (found == false); b++) {
					if (sud[a][b] == j)
						found = true;
				}
			}
			//为空格内的数字生成变元编号
			if (found == 0) {
				p_d = (digtal*)malloc(sizeof(digtal));
				p_d->num = j;				//记录该数字
				p_d->v_num = ++(S->num_v);	//给数字一个变元编号
				p_d->next = NULL;
				holes[i].dig_num++;			//空格可能出现的数字数目加一
				if (holes[i].elem == NULL) {
					holes[i].elem = p_d;
					p_df = p_d;
				}
				else {
					p_df->next = p_d;
					p_df = p_d;
				}
			}
		}
	}

	//由空格内最多一个数字，最少一个数字 创建子句
	for (i = 0; i < hole_num; i++) {
		p_d = holes[i].elem;
		p_df = p_d;
		p_s = (Statement*)malloc(sizeof(Statement));
		p_s->elem = NULL;
		p_s->next = NULL;
		S->num_st++;
		if (i == 0 && (S->root == NULL)) { //创建子句,当为第一个子句时，优先考虑公式的根子句指针
			S->root = p_s;
		}
		else {
			p_sf->next = p_s;
		}
		p_sf = p_s;
		while (p_d) { //根据每个空格最少一个数字创建子句
			p_l = (Literal*)malloc(sizeof(Literal));
			p_l->next = NULL;
			p_sf->num_lit++;//子句文字数加一
			if (p_s->elem == NULL) {
				p_s->elem = p_l;
			}
			else {
				p_lf->next = p_l;
			}
			p_lf = p_l;
			p_lf->pos = 1;//文字设为正，以保证析取之后至少有一个为1
			p_lf->num = p_d->v_num;
			p_d = p_d->next;
		}
		while (p_df) { //根据每个空格最多一个数字创建子句
			p_d = p_df->next;
			while (p_d) {
				p_s = (Statement*)malloc(sizeof(Statement));//生成一个新子句
				p_s->next = NULL;
				S->num_st++;
				p_sf->next = p_s;
				p_sf = p_s;
				p_sf->num_lit = 2;//每个子句只有两个文字以代表只有一个文字为真
				p_sf->elem = (Literal*)malloc(sizeof(Literal));
				p_sf->elem->num = p_df->v_num;
				p_sf->elem->pos = 0;//两个文字只有一个为真，故都是负文字
				p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
				p_sf->elem->next->num = p_d->v_num;
				p_sf->elem->next->pos = 0;
				p_sf->elem->next->next = NULL;
				p_d = p_d->next;
			}
			p_df = p_df->next;
		}
	}

	//由每个数字在每行最多出现一次，最少出现一次 创建子句
	j = 0;
	for (i = 0; i < 9; i++) { //遍历每一行
		x = j;//用于记录每一行的开始空格位置
		for (k = 1; k <= 9; k++) { //遍历每个数字
			int v[10];//用于储存在行的空格上每个数字可能出现位置的变元号
			v[0] = 0;//首行用于存储数字在此行出现次数
			int a;//用于遍历v数字
			int b;
			a = 1;
			j = x;
			while ((holes[j].x == i) && j < hole_num) { //找到每个数字对应的空格出现位置保持相应变元号
				p_df = holes[j].elem;
				while (p_df) {
					if (p_df->num == k) {
						v[a] = p_df->v_num;
						v[0]++;
						a++;
						break;
					}
					p_df = p_df->next;
				}
				j++;
			}
			if (v[0] == 0)
				continue;
			p_s = (Statement*)malloc(sizeof(Statement));//根据一个数字在一行内最少出现一次生成公式
			S->num_st++;//子句数加一
			p_s->num_lit = v[0];
			p_s->next = NULL;
			p_sf->next = p_s;
			p_sf = p_s;
			for (a = 1; a <= v[0]; a++) {
				p_l = (Literal*)malloc(sizeof(Literal));
				p_l->next = NULL;
				if (a == 1) {
					p_sf->elem = p_l;
				}
				else {
					p_lf->next = p_l;
				}
				p_lf = p_l;
				p_lf->pos = 1;//保证只有数字最少出现一次，故此子句的文字全为正
				p_lf->num = v[a];
			}
			for (a = 1; a <= v[0]; a++) { //根据一个数字在一行内最多出现一次生成公式
				for (b = a + 1; b <= v[0]; b++) {
					p_s = (Statement*)malloc(sizeof(Statement));
					S->num_st++;//子句数加一
					p_s->num_lit = 2;
					p_s->next = NULL;
					p_sf->next = p_s;
					p_sf = p_s;
					p_sf->elem = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->num = v[a];
					p_sf->elem->pos = 0;//两个文字只有一个为真，故都是负文字
					p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->next->num = v[b];
					p_sf->elem->next->pos = 0;
					p_sf->elem->next->next = NULL;
				}
			}
		}
	}

	//由每个数字在每列最多出现一次，最少出现一次 创建子句
	for (j = 0; j < 9; j++) {
		for (k = 1; k <= 9; k++) { //遍历每个数字
			int v[10];//用于储存在列的空格上每个数字可能出现位置的变元号
			v[0] = 0;//首行用于存储数字在此列出现次数
			int a;//用于遍历v数字
			a = 1;
			int b;
			for (i = 0; i < hole_num; i++) { //找到每个数字对应的空格出现位置保持相应变元号
				if (holes[i].y == j) {
					p_df = holes[i].elem;
					while (p_df) {
						if (p_df->num == k) {
							v[a] = p_df->v_num;
							v[0]++;
							a++;
							break;
						}
						p_df = p_df->next;
					}
				}
			}
			if (v[0] == 0)
				continue;
			p_s = (Statement*)malloc(sizeof(Statement));//根据一个数字在一行内最少出现一次生成公式
			S->num_st++;//子句数加一
			p_s->num_lit = v[0];
			p_s->next = NULL;
			p_sf->next = p_s;
			p_sf = p_s;
			for (a = 1; a <= v[0]; a++) {
				p_l = (Literal*)malloc(sizeof(Literal));
				p_l->next = NULL;
				if (a == 1) {
					p_sf->elem = p_l;
				}
				else {
					p_lf->next = p_l;
				}
				p_lf = p_l;
				p_lf->pos = 1;//保证只有数字最少出现一次，故此子句的文字全为正
				p_lf->num = v[a];
			}
			for (a = 1; a <= v[0]; a++) { //根据一个数字在一行内最多出现一次生成公式
				for (b = a + 1; b <= v[0]; b++) {
					p_s = (Statement*)malloc(sizeof(Statement));
					S->num_st++;//子句数加一
					p_s->num_lit = 2;
					p_s->next = NULL;
					p_sf->next = p_s;
					p_sf = p_s;
					p_sf->elem = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->num = v[a];
					p_sf->elem->pos = 0;//两个文字只有一个为真，故都是负文字
					p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->next->num = v[b];
					p_sf->elem->next->pos = 0;
					p_sf->elem->next->next = NULL;
				}
			}
		}
	}
	//由每个数字在每个子宫内最多出现一次，最少出现一次 创建子句
	int place;//用于遍历宫
	for (place = 0; place < 9; place++) {
		int ub_x;//表示宫的上界
		int ub_y;
		int lb_x;//表示宫的下界
		int lb_y;
		lb_x = (place / 3) * 3;
		ub_x = (place / 3 + 1) * 3;
		switch (place) { //确定当前宫对应的上下界
			case 0:
			case 3:
			case 6:
			{
				lb_y = 0;
				ub_y = 3;
				break;
			}
			case 1:
			case 4:
			case 7:
			{
				lb_y = 3;
				ub_y = 6;
				break;
			}
			case 2:
			case 5:
			case 8:
			{
				lb_y = 6;
				ub_y = 9;
				break;
			}
		}
		for (k = 1; k <= 9; k++) //遍历每个数字
		{
			int v[10];//用于储存在列的空格上每个数字可能出现位置的变元号
			v[0] = 0;//首行用于存储数字在此列出现次数
			int a;//用于辅助遍历
			int b;
			a = 0;
			b = 1;
			for (a = 0; a < hole_num; a++) { //找到每个数字对应的空格出现位置保持相应变元号
				if ((holes[a].x >= lb_x) && (holes[a].x < ub_x) && (holes[a].y >= lb_y) && (holes[a].y < ub_y)) { //当空格在当前宫内时
					p_df = holes[a].elem;
					while (p_df) { //遍历空格中可能出现的数字
						if (p_df->num == k) { //如果恰为当前数字则计入数组
							v[b] = p_df->v_num;
							v[0]++;
							b++;
							break;
						}
						p_df = p_df->next;
					}
				}
			}
			if (v[0] == 0)
				continue;
			p_s = (Statement*)malloc(sizeof(Statement));//根据一个数字在一行内最少出现一次生成公式
			S->num_st++;//子句数加一
			p_s->num_lit = v[0];
			p_s->next = NULL;
			p_sf->next = p_s;
			p_sf = p_s;
			for (a = 1; a <= v[0]; a++) {
				p_l = (Literal*)malloc(sizeof(Literal));
				p_l->next = NULL;
				if (a == 1) {
					p_sf->elem = p_l;
				}
				else {
					p_lf->next = p_l;
				}
				p_lf = p_l;
				p_lf->pos = 1;//保证只有数字最少出现一次，故此子句的文字全为正
				p_lf->num = v[a];
			}
			for (a = 1; a <= v[0]; a++) { //根据一个数字在一行内最多出现一次生成公式
				for (b = a + 1; b <= v[0]; b++) {
					p_s = (Statement*)malloc(sizeof(Statement));
					S->num_st++;//子句数加一
					p_s->num_lit = 2;
					p_s->next = NULL;
					p_sf->next = p_s;
					p_sf = p_s;
					p_sf->elem = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->num = v[a];
					p_sf->elem->pos = 0;//两个文字只有一个为真，故都是负文字
					p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->next->num = v[b];
					p_sf->elem->next->pos = 0;
					p_sf->elem->next->next = NULL;
				}
			}
		}
	}

	//由变元数生成变元真值关系数组
	Varies = (int*)malloc((S->num_v + 1) * sizeof(int));
	for (i = 1; i < (S->num_v + 1); i++)
		Varies[i] = -1;
	return Varies;
}

/*
将cnf变元真值关系转化为数独的解并输出
输入为一组cnf变元真值关系
输出为数独的解
算法思想：输出数独元素，当此元素为0时，找到空格数组中对应的空格，遍历查看空格中那个数字对应的变元为真则输出此数字
*/
void ShowSudResult(int* Varies, hole* holes, int(*sud)[9]) {
	int i;//用于遍历数独格局
	int j;
	int k = 0;//用于遍历空格数组
	digtal* p;

	printf("\n******************************\n\n");
	printf("数独的解为：\n\n");
	printf("        -------------------\n");
	for (i = 0; i < 9; i++) {
		printf("\t|");
		for (j = 0; j < 9; j++) {
			if (sud[i][j] == 0) { //当此处为空时
				p = holes[k++].elem;
				while (p) {
					if (Varies[p->v_num]) {
						sud[i][j] = p->num;
						break;
					}
					else
						p = p->next;
				}
			}
			printf("%d|", sud[i][j]);
		}
		printf("\n");
	}
	printf("        -------------------\n\n");
}