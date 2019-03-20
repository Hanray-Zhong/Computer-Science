#include "head.h"

/*------------solver中需要的函数--------------*/
/*拷贝当前的公式*/
Formula* Copy_F(Formula* formula) {
	Formula* S1;                                                                                                                                         
	S1 = (Formula*)malloc(sizeof(Formula));
	//复制当前公式中的所有信息
	S1->sta = formula->sta;
	S1->num_st = formula->num_st;
	S1->num_v = formula->num_v;
	S1->root = (Statement*)malloc(sizeof(Statement));
	S1->root->next = NULL;
	//复制公式链表
	Statement* p_s1;
	Statement* p_s;
	p_s1 = S1->root;
	p_s = formula->root;
	while (p_s != NULL) {
		p_s1->num_lit = p_s->num_lit;
		p_s1->elem = (Literal*)malloc(sizeof(Literal));
		p_s1->elem->next = NULL;
		Literal* p_l1;
		Literal* p_l;
		p_l1 = p_s1->elem;
		p_l = p_s->elem;
		while (p_l != NULL) {

			p_l1->num = p_l->num;
			p_l1->pos = p_l->pos;
			if (p_l->next != NULL) {
				p_l1->next = (Literal*)malloc(sizeof(Literal));
				p_l1 = p_l1->next;
			}
			p_l1->next = NULL;
			p_l = p_l->next;
		}
		if (p_s->next != NULL) {
			p_s1->next = (Statement*)malloc(sizeof(Statement));
			p_s1 = p_s1->next;
		}
		p_s1->next = NULL;
		p_s = p_s->next;
	}
	return S1;
}

/*拷贝当前变元真值关系*/
int* Copy_V(int* V, int num_v) {
	int* V1;//拷贝者
	int i;
	V1 = (int*)malloc((num_v + 1) * sizeof(int));
	for (i = 1; i <= num_v; i++) {
		V1[i] = V[i];
	}
	return V1;
}

/*判断当前公式是否含有单子句*/
status HaveUnitClause(Formula* formula) {
	int token = 0;//用于标识公式是否含有单子句，如有则标志为1，如没有则标志为0
	Statement* p_s;
	p_s = formula->root;
	//遍历公式检验公式中是否含有单子句
	while ((token != 1) && (p_s != NULL)) {
		if (p_s->num_lit == 1)
			token = 1;
		p_s = p_s->next;
	}
	//当标志为1的时候返回有单子句，不为1时返回无单子句
	if (token == 1) {
		return TURE;
	}
	else {
		return FALSE;
	}
}

/*去除含有指定文字的子句*/
void RemoveClause(Literal lit, Formula* formula) {
	int token = 0;			//用于标记当前子句是否含有特定文字,1代表含有
	int token_root = 0;		//用于标记根节点是否被检验,1表示已检验
	Statement* p_s = NULL;	//用于遍历公式
	Statement* p_sf = NULL;	//用于删除子句
	Literal* p_l = NULL;	//用于遍历子句
	Literal* p_lf = NULL;	//用于删除文字
	//遍历所有子句，碰到含有特定文字的子句则删除之
	//先判断根子句是否含有特定文字
	while ((token_root != 1) && formula->root != NULL)
	{
		p_l = formula->root->elem;
		while ((token != 1) && (p_l != NULL)) {
			if ((p_l->pos == lit.pos) && (p_l->num == lit.num))
				token = 1;
			p_l = p_l->next;
		}
		if (token == 1) {
			p_sf = formula->root;
			formula->root = formula->root->next;
			p_l = p_sf->elem;
			free(p_sf);
			p_sf = NULL;
			while (p_l != NULL) {
				p_lf = p_l->next;
				free(p_l);
				p_l = p_lf;
			}
			(formula->num_st)--;//子句数减一
		}
		else {
			token_root = 1;
		}
		token = 0;
	}
	if (formula->root) {
		//遍历剩余公式
		p_sf = formula->root;
		p_s = p_sf->next;
		while (p_s != NULL) {
			p_l = p_s->elem;
			while ((token != 1) && (p_l != NULL)) {
				if ((p_l->pos == lit.pos) && (p_l->num == lit.num))
					token = 1;
				p_l = p_l->next;
			}
			//删除含有特定文字的子句
			if (token == 1) {
				p_s = p_s->next;
				p_l = p_sf->next->elem;
				free(p_sf->next);
				while (p_l != NULL) {
					p_lf = p_l->next;
					free(p_l);
					p_l = p_lf;
				}
				p_sf->next = p_s;
				(formula->num_st)--;//子句数减一
			}
			else {
				p_s = p_s->next;
				p_sf = p_sf->next;
			}
			token = 0;//重置标记
		}
	}
}

/*清除子句中的特定文字*/
void ClearClause(Literal lit, Formula* formula) {
	Statement* p_s = NULL;	//用于遍历公式
	Literal* p_l = NULL;	//用于遍历子句
	Literal* p_lf = NULL;	//用于删除文字
	int token = 0;			//用于标记根文字是否被检验,1表示已检验
	p_s = formula->root;
	while (p_s != NULL) {
		while ((token != 1) && (p_s->elem != NULL)) { //先检验根文字
			p_l = p_s->elem;
			if ((p_l->pos == lit.pos) && (p_l->num == lit.num)) { //根文字为特定文字
				p_s->elem = p_s->elem->next;
				free(p_l);//删除根文字
				p_l = NULL;
				(p_s->num_lit)--;//子句文字数减一
			}
			else {
				token = 1;//根文字已检验
			}
		}
		if (p_s->elem) {
			p_lf = p_s->elem;
			p_l = p_lf->next;
			while (p_l != NULL) { //检验其他文字
				if ((p_l->pos == lit.pos) && (p_l->num == lit.num)) { //此文字为特定文字
					p_l = p_l->next;
					free(p_lf->next);//删除根文字
					(p_s->num_lit)--;//子句文字数减一
					p_lf->next = p_l;
				}
				else {
					p_l = p_l->next;
					p_lf = p_lf->next;
				}
			}
		}
		p_s = p_s->next;
		token = 0;//下一句根文字未检验
	}
}

/*判断当前公式是否含有空子句，有则返回TRUE*/
status HaveEmptyClause(Formula* formula) {
	int token;
	token = 0;
	Statement* p;
	p = formula->root;
	while ((token != 1) && (p != NULL)) {
		if (p->num_lit == 0) {
			token = 1;
		}
		p = p->next;
	}
	if (token == 1)
		return TURE;
	else
		return FALSE;
}

/*
在公式中选择一个特定的正文字并返回
遍历公式选出长度最短的子句，在子句中选择出现次数最多的变元，返回其正文字
*/
Literal Choose_L(Formula* formula) {
	Literal lit;		//用于返回选择变元的正文字
	Statement* shortest;//用于指向最短的子句
	Literal* p_l;		//用于遍历最短子句
	Statement* p;		//用于遍历公式
	int v[2];			//用于保存出现次数最多的变元及出现次数
	int i;
	//遍历公式找出最短的子句
	p = formula->root;
	shortest = p;
	while (p != NULL) {
		if ((p->num_lit) < (shortest->num_lit))
			shortest = p;
		p = p->next;
	}
	//在最短子句中找出出现次数最多的变元
	int** num_v;//保存变元及其出现数目的二维数组
	num_v = (int**)malloc((shortest->num_lit) * sizeof(int*));
	for (i = 0; i < shortest->num_lit; i++) {
		num_v[i] = (int*)malloc(2 * sizeof(int));
		num_v[i][0] = 0;
		num_v[i][1] = 0;
	}
	p_l = shortest->elem;
	i = 0;
	while (p_l != NULL) {
		for (i = 0; (num_v[i][0] != p_l->num) && (num_v[i][0] != 0) && (i < shortest->num_lit); i++);
		if (num_v[i][0] == p_l->num)
			num_v[i][1]++;
		else if (num_v[i][0] == 0) {
			num_v[i][0] = p_l->num;
			num_v[i][1] = 1;
		}
		p_l = p_l->next;
	}
	v[0] = num_v[0][0];
	v[1] = num_v[0][1];
	for (i = 0; i < shortest->num_lit; i++) {
		if (num_v[i][1] > v[1])
		{
			v[0] = num_v[i][0];
			v[1] = num_v[i][1];
		}
	}
	lit.pos = 1;
	lit.num = v[0];
	return lit;
}

/*
将一个给定的文字加入一个公式中
输入一个文字和一个公式
返回一个新的公式(该公式的另外开辟储存空间)
*/
Formula* AddClause(Literal lit, Formula* formula) {
	Formula* S1;			//用于返回生成的公式
	Statement* p_s;			//用于生成一个单子句
	Statement* p;			//用于遍历公式
	S1 = Copy_F(formula);	//拷贝公式
	//根据文字生成一个单子句
	p_s = (Statement*)malloc(sizeof(Statement));
	p_s->elem = (Literal*)malloc(sizeof(Literal));
	p_s->elem->num = lit.num;
	p_s->elem->pos = lit.pos;
	p_s->elem->next = NULL;
	p_s->num_lit = 1;
	p_s->next = NULL;
	//将单子句纳入公式中
	p = S1->root;
	while (p->next != NULL)
		p = p->next;
	p->next = p_s;
	S1->num_st++;//子句数加一
	return S1;
}

/*
销毁输入指针所指向的公式所占用的内存区域
*/
void DestoryFormula(Formula* formula) {
	Statement* p_s;	//用于遍历公式
	Statement* p_sf;//用于删除子句
	Literal* p_l;	//用于遍历子句
	Literal* p_lf;	//用于删除文字
	//删除公式，记录根子句位置
	p_s = formula->root;
	free(formula);
	//外层循环遍历删除子句，内层循环遍历删除文字
	while (p_s != NULL) {
		p_sf = p_s;
		p_s = p_s->next;
		p_l = p_sf->elem;//记录根文字位置，删除子句
		free(p_sf);
		while (p_l != NULL) {
			p_lf = p_l;
			p_l = p_l->next;
			free(p_lf);
		}
	}
}