#include "head.h"
/*
在提供cnf范式的前提下判断公式的可满足性。
*/
status Solver(Formula* formula, int* Varies)
{
	Formula* formula_temp;		//用于临时储存生成的公式
	Formula* formula_current;	//用于表示当前公式
	Literal literal;					//用于记录分裂策略选出的文字
	int* current_Varies = 0;					//用于表示当前变元真值状况
	int token = 1;				//用于标记是否为第一次循环,1表示是
	int i;

	Stack_F* top;	//栈顶
	Stack_F* p;		//入栈和出栈
	top = (Stack_F*)malloc(sizeof(Stack_F));
	//将公式和变元的初始状态入栈
	top->S = Copy_S(formula);
	top->V = Copy_V(Varies, formula->num_v);
	top->next = NULL;

	/**************DPLL求解**************/
	//设置初始当前公式
	formula_current = formula;
	while ((formula_current->sta != 1) && (top != NULL)) {
		//判断是否是第一次循环，如果是，则标记为不是;如果不是，则进行删除公式和真值关系操作
		if (token == 1) {
			token = 0;
		}
		else {
			DestoryFormula(formula_current);
			free(current_Varies);
		}
		//栈头公式出栈并作为当前公式，栈头变元真值关系出栈作为当前变元真值关系
		formula_current = top->S;
		current_Varies = top->V;
		p = top;
		top = top->next;
		free(p);
		//当存在单子句时，用单子句传播规则处理公式
		while (JudgeClause(formula_current)) {
			//选择一个单子句，并记录文字
			Literal lit;	//用于记录文字
			Statement* p_s;	//用于遍历公式
			p_s = formula_current->root;
			while (p_s->num_lit != 1)
				p_s = p_s->next;
			lit = *(p_s->elem);//取单子句的文字
			//记录此单子句所含文字的变元使单子句为真
			if (lit.pos == 1)
				current_Varies[lit.num] = 1;
			else
				current_Varies[lit.num] = 0;
			//清除所有含有lit记录的文字的子句
			RemoveClause(lit, formula_current);
			if (lit.pos == 1)//将lit变为其负文字
				lit.pos = 0;
			else
				lit.pos = 1;
			//清除公式中lit记录文字的负文字
			ClearClause(lit, formula_current);
			if (formula_current->root == NULL)
			{
				//当公式可满足时，复制当前变元真值关系
				formula_current->sta = 1;
				for (i = 1; i <= formula->num_v; i++) //复制此时的真值状态
				{
					Varies[i] = current_Varies[i];
				}
			}
			else if (ExistEmptyClause(formula_current))
			{
				formula_current->sta = 0;
			}
		}
		//当不存在单子句时，若满足性标识为-1则使用分裂策略选择特定变元生成两个新的公式
		if (formula_current->sta == -1)
		{
			literal = Choose_v(formula_current);
			//先向子句集合中加入由分裂策略选出的文字组成的单子句
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));//将生成的公式入栈
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;
			//在向子句集中加入由由分裂策略选出文字的负文字组成的单子句
			literal.pos = 0;
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));//将生成的公式入栈
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;
		}
	}
	//当公式可满足时
	if (formula_current->sta == 1)
	{
		return TURE;
	}
	//当公式不满足是返回FALSE
	else if (formula_current->sta == 0)
	{
		return FALSE;
	}
	//当公式不确定满足性时返回CONFUSE
	else
	{
		return CONFUSE;
	}
}
