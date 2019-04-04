#include "head.h"
/*ͨ��cnf�ļ�����cnf��ʽ*/
void CNF_Reader(FILE* fp, Formula* formula) {
	char buff[1000];//�洢ע��
	//��ע�ʹ浽buff������
	while (fgetc(fp) == 'c') {
		fgets(buff, 1000, fp);
	}
	//ͨ��fscanf��ȡ��Ԫ�����Ӿ���
	int i;
	//��ȡ�� cnf ���ַ���
	for (i = 1; i <= 5; i++) {
		fgetc(fp);
	}
	//��cnf�ļ��и����ı�Ԫ�����Ӿ���д�빫ʽ��
	fscanf(fp, "%d %d", &(formula->num_v), &(formula->num_st));
	//��ȡ���з�
	fgetc(fp);

	/******************�����ļ�������ʽ*******************/
	Statement* statement;//�����Ӿ�
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
		//������һ������
		Literal* literal;
		statement->elem = (Literal*)malloc(sizeof(Literal));
		literal = statement->elem;
		literal->next = NULL;
		int k;
		//���ļ���Ŀǰ��ȡ������д��k
		fscanf(fp, "%d", &k);
		//��ɺ������ֵĶ�ȡ
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
			(statement->num_lit)++;//ÿ��ȡһ�����֣��Ӿ����������һ
			fscanf(fp, "%d", &k);
		}
		fgetc(fp);//��ȡÿ���Ӿ�β�Ļ��з�
	}
}