#include "head.h"

/*------------solver����Ҫ�ĺ���--------------*/
/*������ǰ�Ĺ�ʽ*/
Formula* Copy_F(Formula* formula) {
	Formula* S1;                                                                                                                                         
	S1 = (Formula*)malloc(sizeof(Formula));
	//���Ƶ�ǰ��ʽ�е�������Ϣ
	S1->sta = formula->sta;
	S1->num_st = formula->num_st;
	S1->num_v = formula->num_v;
	S1->root = (Statement*)malloc(sizeof(Statement));
	S1->root->next = NULL;
	//���ƹ�ʽ����
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

/*������ǰ��Ԫ��ֵ��ϵ*/
int* Copy_V(int* V, int num_v) {
	int* V1;//������
	int i;
	V1 = (int*)malloc((num_v + 1) * sizeof(int));
	for (i = 1; i <= num_v; i++) {
		V1[i] = V[i];
	}
	return V1;
}

/*�жϵ�ǰ��ʽ�Ƿ��е��Ӿ�*/
status HaveUnitClause(Formula* formula) {
	int token = 0;//���ڱ�ʶ��ʽ�Ƿ��е��Ӿ䣬�������־Ϊ1����û�����־Ϊ0
	Statement* p_s;
	p_s = formula->root;
	//������ʽ���鹫ʽ���Ƿ��е��Ӿ�
	while ((token != 1) && (p_s != NULL)) {
		if (p_s->num_lit == 1)
			token = 1;
		p_s = p_s->next;
	}
	//����־Ϊ1��ʱ�򷵻��е��Ӿ䣬��Ϊ1ʱ�����޵��Ӿ�
	if (token == 1) {
		return TURE;
	}
	else {
		return FALSE;
	}
}

/*ȥ������ָ�����ֵ��Ӿ�*/
void RemoveClause(Literal lit, Formula* formula) {
	int token = 0;			//���ڱ�ǵ�ǰ�Ӿ��Ƿ����ض�����,1������
	int token_root = 0;		//���ڱ�Ǹ��ڵ��Ƿ񱻼���,1��ʾ�Ѽ���
	Statement* p_s = NULL;	//���ڱ�����ʽ
	Statement* p_sf = NULL;	//����ɾ���Ӿ�
	Literal* p_l = NULL;	//���ڱ����Ӿ�
	Literal* p_lf = NULL;	//����ɾ������
	//���������Ӿ䣬���������ض����ֵ��Ӿ���ɾ��֮
	//���жϸ��Ӿ��Ƿ����ض�����
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
			(formula->num_st)--;//�Ӿ�����һ
		}
		else {
			token_root = 1;
		}
		token = 0;
	}
	if (formula->root) {
		//����ʣ�๫ʽ
		p_sf = formula->root;
		p_s = p_sf->next;
		while (p_s != NULL) {
			p_l = p_s->elem;
			while ((token != 1) && (p_l != NULL)) {
				if ((p_l->pos == lit.pos) && (p_l->num == lit.num))
					token = 1;
				p_l = p_l->next;
			}
			//ɾ�������ض����ֵ��Ӿ�
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
				(formula->num_st)--;//�Ӿ�����һ
			}
			else {
				p_s = p_s->next;
				p_sf = p_sf->next;
			}
			token = 0;//���ñ��
		}
	}
}

/*����Ӿ��е��ض�����*/
void ClearClause(Literal lit, Formula* formula) {
	Statement* p_s = NULL;	//���ڱ�����ʽ
	Literal* p_l = NULL;	//���ڱ����Ӿ�
	Literal* p_lf = NULL;	//����ɾ������
	int token = 0;			//���ڱ�Ǹ������Ƿ񱻼���,1��ʾ�Ѽ���
	p_s = formula->root;
	while (p_s != NULL) {
		while ((token != 1) && (p_s->elem != NULL)) { //�ȼ��������
			p_l = p_s->elem;
			if ((p_l->pos == lit.pos) && (p_l->num == lit.num)) { //������Ϊ�ض�����
				p_s->elem = p_s->elem->next;
				free(p_l);//ɾ��������
				p_l = NULL;
				(p_s->num_lit)--;//�Ӿ���������һ
			}
			else {
				token = 1;//�������Ѽ���
			}
		}
		if (p_s->elem) {
			p_lf = p_s->elem;
			p_l = p_lf->next;
			while (p_l != NULL) { //������������
				if ((p_l->pos == lit.pos) && (p_l->num == lit.num)) { //������Ϊ�ض�����
					p_l = p_l->next;
					free(p_lf->next);//ɾ��������
					(p_s->num_lit)--;//�Ӿ���������һ
					p_lf->next = p_l;
				}
				else {
					p_l = p_l->next;
					p_lf = p_lf->next;
				}
			}
		}
		p_s = p_s->next;
		token = 0;//��һ�������δ����
	}
}

/*�жϵ�ǰ��ʽ�Ƿ��п��Ӿ䣬���򷵻�TRUE*/
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
�ڹ�ʽ��ѡ��һ���ض��������ֲ�����
������ʽѡ��������̵��Ӿ䣬���Ӿ���ѡ����ִ������ı�Ԫ��������������
*/
Literal Choose_L(Formula* formula) {
	Literal lit;		//���ڷ���ѡ���Ԫ��������
	Statement* shortest;//����ָ����̵��Ӿ�
	Literal* p_l;		//���ڱ�������Ӿ�
	Statement* p;		//���ڱ�����ʽ
	int v[2];			//���ڱ�����ִ������ı�Ԫ�����ִ���
	int i;
	//������ʽ�ҳ���̵��Ӿ�
	p = formula->root;
	shortest = p;
	while (p != NULL) {
		if ((p->num_lit) < (shortest->num_lit))
			shortest = p;
		p = p->next;
	}
	//������Ӿ����ҳ����ִ������ı�Ԫ
	int** num_v;//�����Ԫ���������Ŀ�Ķ�ά����
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
��һ�����������ּ���һ����ʽ��
����һ�����ֺ�һ����ʽ
����һ���µĹ�ʽ(�ù�ʽ�����⿪�ٴ���ռ�)
*/
Formula* AddClause(Literal lit, Formula* formula) {
	Formula* S1;			//���ڷ������ɵĹ�ʽ
	Statement* p_s;			//��������һ�����Ӿ�
	Statement* p;			//���ڱ�����ʽ
	S1 = Copy_F(formula);	//������ʽ
	//������������һ�����Ӿ�
	p_s = (Statement*)malloc(sizeof(Statement));
	p_s->elem = (Literal*)malloc(sizeof(Literal));
	p_s->elem->num = lit.num;
	p_s->elem->pos = lit.pos;
	p_s->elem->next = NULL;
	p_s->num_lit = 1;
	p_s->next = NULL;
	//�����Ӿ����빫ʽ��
	p = S1->root;
	while (p->next != NULL)
		p = p->next;
	p->next = p_s;
	S1->num_st++;//�Ӿ�����һ
	return S1;
}

/*
��������ָ����ָ��Ĺ�ʽ��ռ�õ��ڴ�����
*/
void DestoryFormula(Formula* formula) {
	Statement* p_s;	//���ڱ�����ʽ
	Statement* p_sf;//����ɾ���Ӿ�
	Literal* p_l;	//���ڱ����Ӿ�
	Literal* p_lf;	//����ɾ������
	//ɾ����ʽ����¼���Ӿ�λ��
	p_s = formula->root;
	free(formula);
	//���ѭ������ɾ���Ӿ䣬�ڲ�ѭ������ɾ������
	while (p_s != NULL) {
		p_sf = p_s;
		p_s = p_s->next;
		p_l = p_sf->elem;//��¼������λ�ã�ɾ���Ӿ�
		free(p_sf);
		while (p_l != NULL) {
			p_lf = p_l;
			p_l = p_l->next;
			free(p_lf);
		}
	}
}