#include "head.h"
/*SAT������⣺ͨ����ȡcnf�ļ�����������ɵ�cnf��ʽ�Ľ�*/
void SAT(long time_start, long time_end) {
	system("cls");
	FILE* fp;
	char filename[100];
	Formula formula;	//�������ɵ�cnf��ʽ
	int SAT;			//cnf�������Ա�ǣ�0Ϊ�����㣬1Ϊ����

	int* Varies = NULL;	//�������б�Ԫ��Ϣ��0Ϊ�٣�1Ϊ�棬-1Ϊ��ȷ��

	//formula��ʼ��
	formula.sta = -1;
	formula.num_st = 0;
	formula.root = NULL;

	/***************CNF�ļ���ȡ***************/
	printf("�����ļ�����\n");
	scanf("%s", filename);
	getchar();
	fp = fopen(filename, "r");
	if (!fp) {
		printf("�ļ���ʧ��\n");
		return;
	}
	printf("�ļ��򿪳ɹ�\n");
	CNF_Reader(fp, &formula);
	fclose(fp);
	/**************CNF�ļ���ȡ���**************/


	/****����SAT_Solver��֤cnf��ʽ�Ŀ�������*****/
	Varies = (int*)malloc((formula.num_v + 1) * sizeof(int));
	int i;
	//��ʼ��Varies
	for (i = 1; i <= formula.num_v; i++) {
		Varies[i] = -1;
	}
	//��ʼ��ʱ
	time_start = clock();
	SAT = Solver(&formula, Varies);
	time_end = clock();//��¼�������ʱ��
	/******************************************/

	if (SAT == 1) {
		if (Check(Varies, &formula) == true) {
			printf("����֤�������ȷ\n");
		}
		else {
			printf("����֤���������\n");
		}
	}

	/*�����֤���*/
	//���ļ�����Ϊ��.res��β
	int str_length;
	str_length = strlen(filename);
	char str[] = ".res";
	strcpy(filename + str_length - 4, str);
	fp = fopen(filename, "w");//��һ��������ͬ����res�ļ�
	if (!fp)
	{
		printf("�ļ���ʧ�ܣ�\n");
	}
	//�����������
	printf("s %d\n", SAT);
	//���ļ���д���������
	char c = 's';
	fprintf(fp, "%c\t", c);
	fprintf(fp, "%d\n", SAT);
	//�ļ�������ʱ�����һ����ֵ�������ļ���д��һ����ֵ
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
	//�����������ʱ��
	long k;
	k = (time_end - time_start);
	c = 't';
	printf("%c %ldms\n", c, k);
	fprintf(fp, "%c\t", c);
	fprintf(fp, "%ld\n", k);
	fclose(fp);	
}

bool Check(int* Varies_res, Formula* formula) {
	//��ÿһ���Ӿ�
	for (int i = 0; i < formula->num_st; i++) {
		//�ҵ��Ӿ��ÿһ������
		for (int j = 0; j < SearchStatement(i, formula)->num_lit; j++) {
			if (SearchLiteral(j, SearchStatement(i, formula))->pos == Varies_res[SearchLiteral(j, SearchStatement(i, formula))->num]) {
				//һ����������ģ�ֱ����һ�����
				break;
			}
			else {
				//�Ѿ����������һ������
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