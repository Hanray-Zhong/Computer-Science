#include "head.h"
/*
���ṩcnf��ʽ��ǰ�����жϹ�ʽ�Ŀ������ԡ�
*/
status Solver(Formula* formula, int* Varies)
{
	Formula* formula_temp;		//������ʱ�������ɵĹ�ʽ
	Formula* formula_current = formula;	//���ڱ�ʾ��ǰ��ʽ
	Literal literal;			//���ڼ�¼���Ѳ���ѡ��������
	int* current_Varies = 0;	//���ڱ�ʾ��ǰ��Ԫ��ֵ״��
	bool token = true;			//���ڱ���Ƿ�Ϊ��һ��ѭ��
	int i;

	Stack_F* top;
	Stack_F* p;
	top = (Stack_F*)malloc(sizeof(Stack_F));
	top->S = Copy_F(formula);
	top->V = Copy_V(Varies, formula->num_v);
	top->next = NULL;

	/**************DPLL���**************/
	while ((formula_current->sta != 1) && (top != NULL)) {
		//���ǵ�һ�ν���DPLL�������ɾ����ʽ����ֵ��ϵ����
		if (token == true) {
			token = false;
		}
		else {
			DestoryFormula(formula_current);
			free(current_Varies);
		}
		//ջͷ��ʽ��ջ����Ϊ��ǰ��ʽ��ջͷ��Ԫ��ֵ��ϵ��ջ��Ϊ��ǰ��Ԫ��ֵ��ϵ
		formula_current = top->S;
		current_Varies = top->V;
		p = top;
		top = top->next;
		free(p);

		//�����ڵ��Ӿ�ʱ���õ��Ӿ䴫��������ʽ
		while (HaveUnitClause(formula_current)) {
			//ѡ��һ�����Ӿ䣬����¼����
			Literal L;
			Statement* p_s;	//���ڱ�����ʽ
			p_s = formula_current->root;
			// �ҵ����Ӿ�
			while (p_s->num_lit != 1) {
				p_s = p_s->next;
			}
			L = *(p_s->elem);
			//��¼�˵��Ӿ��������ֵı�Ԫʹ���Ӿ�Ϊ��
			if (L.pos == 1)
				current_Varies[L.num] = 1;
			else if (L.pos == 0)
				current_Varies[L.num] = 0;
			//ɾ�����а���L���Ӿ�
			RemoveClause(L, formula_current);

			//��S1�е�ÿ���Ӿ䣬������������� ��L,��Ӹ��Ӿ���ȥ���������
			if (L.pos == 1)
				L.pos = 0;
			else if (L.pos == 0)
				L.pos = 1;
			//�����ʽ��L��¼���ֵĸ�����
			ClearClause(L, formula_current);

			//������ǿռ�����ǰCNF��ʽ����
			if (formula_current->root == NULL) {
				//����ʽ������ʱ�����Ƶ�ǰ��Ԫ��ֵ��ϵ
				formula_current->sta = 1;
				for (i = 1; i <= formula->num_v; i++) { //���ƴ�ʱ����ֵ״̬ 
					Varies[i] = current_Varies[i];
				}
			}
			//������ǿռ�����ǰCNF��ʽ������
			else if (HaveEmptyClause(formula_current)) {
				formula_current->sta = 0;
			}
		}

		//�������ڵ��Ӿ�ʱ���Ҳ�֪����ʽ�Ƿ����㣬��ʹ�÷��Ѳ��Խ�S��ΪS1��S2
		//���ԣ�ѡ��������̵��Ӿ䣬���Ӿ���ѡ����ִ������ı�Ԫ
		if (formula_current->sta == -1) {
			literal = Choose_L(formula_current);
			//����ǰ��ʽ���Ӿ伯���м�����ѡ�������֣����S2
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;

			//�����Ӿ伯�м���ѡ�����ֵĸ����֣����S1
			literal.pos = 0;
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;
		}
	}
	/**************DPLL����**************/

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
