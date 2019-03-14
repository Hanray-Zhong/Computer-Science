#include "head.h"
/*ͨ���ļ�����cnf��ʽ����֤���������*/
void SAT(long time_start, long time_end) {
	system("cls");
	FILE* fp;
	char filename[100];
	Formula formula;	//�������ɵĹ�ʽ
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
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	printf("�ļ��򿪳ɹ�");
	CNF_Reader(fp, &formula);//����cnf��ʽ
	fclose(fp);
	/**************CNF�ļ���ȡ���**************/


	/****����SAT_Solver��֤cnf��ʽ�Ŀ�������*****/
	Varies = (int*)malloc((formula.num_v + 1) * sizeof(int));
	int i;
	// ��ʼ��Varies
	for (i = 1; i <= formula.num_v; i++) {
		Varies[i] = -1;
	}
	//��ʼ��ʱ
	time_start = clock();
	SAT = Solver(&formula, Varies);
	time_end = clock();//��¼�������ʱ��
	/******************************************/

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
			//����valueֵ�ж��������valueΪ1ʱ���Ϊ������valueΪ0��-1ʱ���Ϊ��
			if (Varies[i]) {
				printf("%d ", i);
				fprintf(fp, "%d ", i);
			}
			else {
				printf("-%d ", i);
				int k = -i;
				fprintf(fp, "%d ", k);
			}
		}
		printf("\n");
		fprintf(fp, "\n");
	}
	//�����������ʱ��
	long k;
	k = time_end - time_start;
	c = 't';
	printf("%c %ld", c, k);
	fprintf(fp, "%c\t", c);
	fprintf(fp, "%ld", k);
	fclose(fp);
}
