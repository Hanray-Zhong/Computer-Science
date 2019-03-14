#include "head.h"
/*
���ṩcnf��ʽ��ǰ�����жϹ�ʽ�Ŀ������ԡ�
*/
status Solver(Formula* formula, int* Varies)
{
	Formula* formula_temp;		//������ʱ�������ɵĹ�ʽ
	Formula* formula_current;	//���ڱ�ʾ��ǰ��ʽ
	Literal literal;					//���ڼ�¼���Ѳ���ѡ��������
	int* current_Varies = 0;					//���ڱ�ʾ��ǰ��Ԫ��ֵ״��
	int token = 1;				//���ڱ���Ƿ�Ϊ��һ��ѭ��,1��ʾ��
	int i;

	Stack_F* top;	//ջ��
	Stack_F* p;		//��ջ�ͳ�ջ
	top = (Stack_F*)malloc(sizeof(Stack_F));
	//����ʽ�ͱ�Ԫ�ĳ�ʼ״̬��ջ
	top->S = Copy_S(formula);
	top->V = Copy_V(Varies, formula->num_v);
	top->next = NULL;

	/**************DPLL���**************/
	//���ó�ʼ��ǰ��ʽ
	formula_current = formula;
	while ((formula_current->sta != 1) && (top != NULL)) {
		//�ж��Ƿ��ǵ�һ��ѭ��������ǣ�����Ϊ����;������ǣ������ɾ����ʽ����ֵ��ϵ����
		if (token == 1) {
			token = 0;
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
		while (JudgeClause(formula_current)) {
			//ѡ��һ�����Ӿ䣬����¼����
			Literal lit;	//���ڼ�¼����
			Statement* p_s;	//���ڱ�����ʽ
			p_s = formula_current->root;
			while (p_s->num_lit != 1)
				p_s = p_s->next;
			lit = *(p_s->elem);//ȡ���Ӿ������
			//��¼�˵��Ӿ��������ֵı�Ԫʹ���Ӿ�Ϊ��
			if (lit.pos == 1)
				current_Varies[lit.num] = 1;
			else
				current_Varies[lit.num] = 0;
			//������к���lit��¼�����ֵ��Ӿ�
			RemoveClause(lit, formula_current);
			if (lit.pos == 1)//��lit��Ϊ�为����
				lit.pos = 0;
			else
				lit.pos = 1;
			//�����ʽ��lit��¼���ֵĸ�����
			ClearClause(lit, formula_current);
			if (formula_current->root == NULL)
			{
				//����ʽ������ʱ�����Ƶ�ǰ��Ԫ��ֵ��ϵ
				formula_current->sta = 1;
				for (i = 1; i <= formula->num_v; i++) //���ƴ�ʱ����ֵ״̬
				{
					Varies[i] = current_Varies[i];
				}
			}
			else if (ExistEmptyClause(formula_current))
			{
				formula_current->sta = 0;
			}
		}
		//�������ڵ��Ӿ�ʱ���������Ա�ʶΪ-1��ʹ�÷��Ѳ���ѡ���ض���Ԫ���������µĹ�ʽ
		if (formula_current->sta == -1)
		{
			literal = Choose_v(formula_current);
			//�����Ӿ伯���м����ɷ��Ѳ���ѡ����������ɵĵ��Ӿ�
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));//�����ɵĹ�ʽ��ջ
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;
			//�����Ӿ伯�м������ɷ��Ѳ���ѡ�����ֵĸ�������ɵĵ��Ӿ�
			literal.pos = 0;
			formula_temp = AddClause(literal, formula_current);
			p = (Stack_F*)malloc(sizeof(Stack_F));//�����ɵĹ�ʽ��ջ
			p->S = formula_temp;
			p->V = Copy_V(current_Varies, formula->num_v);
			p->next = top;
			top = p;
		}
	}
	//����ʽ������ʱ
	if (formula_current->sta == 1)
	{
		return TURE;
	}
	//����ʽ�������Ƿ���FALSE
	else if (formula_current->sta == 0)
	{
		return FALSE;
	}
	//����ʽ��ȷ��������ʱ����CONFUSE
	else
	{
		return CONFUSE;
	}
}
