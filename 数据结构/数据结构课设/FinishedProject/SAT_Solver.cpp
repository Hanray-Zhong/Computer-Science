#include "head.h"
/*
在提供cnf范式的前提下判断公式的可满足性。
*/
status Solver(Formula* formula, int* Varies)
{
	Formula* formula_temp;		//用于临时储存生成的公式
	Formula* formula_current = formula;	//用于表示当前公式
	Literal literal;			//用于记录分裂策略选出的文字
	int* current_Varies = 0;	//用于表示当前变元真值状况
	bool token = true;			//用于标记是否为第一次循环
	int i;

	Stack_F* top;
	Stack_F* p;
	top = (Stack_F*)malloc(sizeof(Stack_F));
	top->S = Copy_F(formula);
	top->V = Copy_V(Varies, formula->num_v);
	top->next = NULL;

	/**************DPLL求解**************/
	while ((formula_current->sta != 1) && (top != NULL)) {
		//不是第一次进行DPLL，则进行删除公式和真值关系操作
		if (token == true) {
			token = false;
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
		while (HaveUnitClause(formula_current)) {
			//选择一个单子句，并记录文字
			Literal L;
			Statement* p_s;	//用于遍历公式
			p_s = formula_current->root;
			// 找到单子句
			while (p_s->num_lit != 1) {
				p_s = p_s->next;
			}
			L = *(p_s->elem);
			//记录此单子句所含文字的变元使单子句为真
			if (L.pos == 1)
				current_Varies[L.num] = 1;
			else if (L.pos == 0)
				current_Varies[L.num] = 0;
			//删除所有包含L的子句
			RemoveClause(L, formula_current);

			//对S1中的每个子句，如果它包含文字 非L,则从该子句中去掉这个文字
			if (L.pos == 1)
				L.pos = 0;
			else if (L.pos == 0)
				L.pos = 1;
			//清除公式中L记录文字的负文字
			ClearClause(L, formula_current);

			//如果它是空集，当前CNF范式满足
			if (formula_current->root == NULL) {
				//当公式可满足时，复制当前变元真值关系
				formula_current->sta = 1;
				for (i = 1; i <= formula->num_v; i++) { //复制此时的真值状态 
					Varies[i] = current_Varies[i];
				}
			}
			//如果不是空集，当前CNF范式不满足
			else if (HaveEmptyClause(formula_current)) {
				formula_current->sta = 0;
			}
		}

		//当不存在单子句时，且不知道范式是否满足，则使用分裂策略将S分为S1，S2
		//策略：选出长度最短的子句，在子句中选择出现次数最多的变元
		if (formula_current->sta == -1) {
			literal = Choose_L(formula_current);
			//先向当前范式的子句集合中加入由选出的文字，组成S2
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;

			//再向子句集中加入选出文字的负文字，组成S1
			literal.pos = 0;
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;
		}
	}
	/**************DPLL结束**************/

	if (formula_current->sta == 1) {
		return TURE;
	}
	else if (formula_current->sta == 0) {
		return FALSE;
	}
	else {
		return CONFUSE;
	}
}
