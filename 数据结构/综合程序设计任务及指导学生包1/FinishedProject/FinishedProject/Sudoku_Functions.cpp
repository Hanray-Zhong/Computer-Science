#include "head.h"
/*
*******************************
����������ȫ���
�㷨˼�룺ͨ�������ĳ�ʼ3��3��֣�ͨ���б任�б�����������վָ��
���ո��һ����16�ֿ���
*******************************
*/
void CreateFinalSud(int(*sud)[9]) {
	int i;//ѭ������
	int j;
	int k;
	int a;
	//����������и��������λ��������������3��3���
	k = 1;
	while (k <= 9) { //��1��9����Ϊ3��3��ָ�ֵ
		for (i = 3; i < 6; i++) {
			for (j = 3; j < 6; j++) {
				sud[i][j] = k++;
			}
		}
	}
	//ͨ���б任�õ���ʼ3��3�������3��3λ���е�����
	srand((unsigned)time(NULL));
	k = rand() % 2;//ͨ�������������ȫ�б任������3��3��ֵ�����λ��
	if (k == 1) {
		//��ʼ�����
		for (j = 0; j < 3; j++) {
			sud[3][j] = sud[5][j + 3];
		}
		for (i = 4; i < 6; i++) {
			for (j = 0; j < 3; j++) {
				sud[i][j] = sud[i - 1][j + 3];
			}
		}
		//��ʼ���ұ�
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
		//��ʼ�����
		for (j = 0; j < 3; j++) {
			sud[5][j] = sud[3][j + 3];
		}
		for (i = 3; i < 5; i++) {
			for (j = 0; j < 3; j++) {
				sud[i][j] = sud[i + 1][j + 3];
			}
		}
		//��ʼ���ұ�
		for (j = 6; j < 9; j++) {
			sud[3][j] = sud[5][j - 3];
		}
		for (i = 4; i < 6; i++) {
			for (j = 6; j < 9; j++) {
				sud[i][j] = sud[i - 1][j - 3];
			}
		}
	}
	//ͨ���б任�õ�����3��3���
	for (a = 0; a < 9; a += 3) {
		k = rand() % 2;//ÿ���б任�������ֿ���
		if (k == 1) {
			//��ʼ���ϱ�
			for (i = 0; i < 3; i++) {
				sud[i][a] = sud[i + 3][a + 2];
			}
			for (j = a + 1; j < a + 3; j++) {
				for (i = 0; i < 3; i++) {
					sud[i][j] = sud[i + 3][j - 1];
				}
			}
			//��ʼ���±�
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
			//��ʼ���ϱ�
			for (i = 0; i < 3; i++) {
				sud[i][a + 2] = sud[i + 3][a];
			}
			for (j = a; j < a + 2; j++) {
				for (i = 0; i < 3; i++) {
					sud[i][j] = sud[i + 3][j + 1];
				}
			}
			//��ʼ���±�
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
creatSudProblem���ڲ�����������
�㷨˼�룺ȫ������ڶ����ɣ��������ڶ���
easy  20holes,   normal  40holes,    evil  60holes
*/
int CreateSudProblem(int(*sud)[9]) {
	int level;//���ڱ��������Ѷ�
	int hole_num;//���ڼ�¼�ڶ���Ŀ
	int i;
	int hole_x;//��¼�ڶ�λ��
	int hole_y;

	//�����ڶ���
	printf("------------------------------------\n");
	printf("��������ѡ���Ѷȣ���1~3��\n");
	printf("1��easy\n2��normal\n3��evil\n\n");

	scanf("%d", &level);
	while (level > 3 || level < 1)
		printf("����Ƿ���1~3��\n");
	hole_num = level * 20;

	//�ڶ�,�ѱ���ȥ�Ĳ�����Ϊ0
	srand((unsigned)time(NULL));//�����������������
	for (i = 1; i <= hole_num; i++) {
		hole_x = rand() % 9;//��������������ڶ�λ��
		hole_y = rand() % 9;
		while (sud[hole_x][hole_y] == 0) {
			hole_x = rand() % 9;//��������������ڶ�λ��
			hole_y = rand() % 9;
		}
		sud[hole_x][hole_y] = 0;
	}
	return hole_num;
}

/*
��������cnf��ʽ���뵽�ļ���
����Ϊ������cnf��ʽ�����һ��cnf��ʽ
*/
void CnfToFile(Formula* formula) {
	FILE* fp;
	char filename[100];
	Statement* statement;
	Literal* literal;

	printf("�����뱣���ļ�����\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	char str[] = ".cnf";
	strcpy(filename + strlen(filename), str);//Ϊ�ļ������Ϻ�׺
	if (!fp)
		printf("�ļ���ʧ��!\n");
	else {
		time_t t;//���������ǰʱ��
		struct tm* lt;
		time(&t);
		lt = localtime(&t);
		fprintf(fp, "c      in %d/%d/%d %d:%d:%d\nc\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		//�����Ԫ�����Ӿ�������Ϣ
		fprintf(fp, "p cnf %d %d\n", formula->num_v, formula->num_st);
		//�����Ӿ䲿��
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
����������ת��ΪSAT����
����Ϊ������ֺ�cnf��ʽ��ַ
���Ϊ�����ɵ�cnf��ʽ�ͱ�Ԫ��ֵ��ϵ�����б�Ԫ��ֵ��ϵͨ������ֵ���أ���ʽͨ����ʽָ�뷵��
�㷨˼�룺����ÿ���ո������ҽ���һ�����֡�1~9�е�������ÿ�С�ÿ�к�ÿ�����ڳ����ҽ�����һ�δ����Ӿ䣬ͨ���ڽӱ��¼ÿ���ո��п��ܳ��ֵ�����
�Ż�˼·����9��10�����鱣��ÿ�����ֿ��ܳ��ֵ�λ��
*/
int* TransfSud(int(*sud)[9], Formula*S, hole* holes) {
	int* Varies;//���ڱ�ʾ��Ԫ��ֵ��ϵ������

	int hole_num;//���ڼ�¼�ո���
	hole_num = 0;
	digtal* p_d;	//�������ɿո��п��ܳ��ֵ�����,�������Ӿ������ڱ���
	digtal* p_df;	//����ָ��ո���ܵ����ֵ�βλ�ã��������Ӿ������ڱ���
	Statement* p_s;	//���ڴ����Ӿ�
	Statement* p_sf = NULL;//���ڱ�����ʽ
	Literal* p_l;	//���ڴ�������
	Literal* p_lf = NULL;	//���ڱ����Ӿ�
	//����ѭ������
	int i;
	int j;
	int k;
	//���ڱ�������
	int x;
	int y;

	//���ɿո�����ܵ������ڽӱ�
	for (i = 0; i < 9; i++) {  //��������ҵ�ÿһ���ո�
		for (j = 0; j < 9; j++) {
			if (sud[i][j] == 0) {
				(holes + hole_num)->x = i;
				(holes + hole_num)->y = j;
				hole_num++;//����ո���
			}
		}
	}
	for (i = 0; i < hole_num; i++) { //�ҵ�ÿ���ո��Ӧ�����֣��������Ԫ��� 
		holes[i].elem = NULL;
		p_df = NULL;
		holes[i].dig_num = 0;
		for (j = 1; j <= 9; j++) {   //�������1~9����Щ�����ܳ����ڴ˿ո�
			int find;//��־�����Ƿ��ѳ���
			find = 0;
			for (k = 0; k < 9 && (find == 0); k++) { //�����в��� 
				if (sud[holes[i].x][k] == j)
					find = 1;//��ʾ���ҵ�
			}
			for (k = 0; k < 9 && (find == 0); k++) { //�����в���
				if (sud[k][holes[i].y] == j)
					find = 1;
			}
			x = (holes[i].x) / 3;//���ڼ�¼�ո����ڵĹ�
			y = (holes[i].y) / 3;
			for (int a = 3 * x; (a >= 3 * x) && (a < 3 * (x + 1)) && (find == 0); a++) { //�ڹ��в���
				for (int b = 3 * y; (b >= 3 * y) && (b < 3 * (y + 1)) && (find == 0); b++) {
					if (sud[a][b] == j)
						find = 1;
				}
			}
			if (find == 0) { //û�з��ֵ�ǰ���֣������ֿ��ܳ����ڿո���
				p_d = (digtal*)malloc(sizeof(digtal));
				p_d->num = j;//��¼���ܵ�����
				p_d->v_num = ++(S->num_v);//����������һ����Ԫ��ţ�ͬʱ��Ԫ����һ
				p_d->next = NULL;
				holes[i].dig_num++;//�ո���ܳ��ֵ�������Ŀ��һ
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

	//�ɿո������һ�����֣�����һ������ �����Ӿ�
	for (i = 0; i < hole_num; i++) {
		p_d = holes[i].elem;
		p_df = p_d;
		p_s = (Statement*)malloc(sizeof(Statement));
		p_s->elem = NULL;
		p_s->next = NULL;
		S->num_st++;
		if (i == 0 && (S->root == NULL)) { //�����Ӿ�,��Ϊ��һ���Ӿ�ʱ�����ȿ��ǹ�ʽ�ĸ��Ӿ�ָ��
			S->root = p_s;
		}
		else {
			p_sf->next = p_s;
		}
		p_sf = p_s;
		while (p_d) { //����ÿ���ո�����һ�����ִ����Ӿ�
			p_l = (Literal*)malloc(sizeof(Literal));
			p_l->next = NULL;
			p_sf->num_lit++;//�Ӿ���������һ
			if (p_s->elem == NULL) {
				p_s->elem = p_l;
			}
			else {
				p_lf->next = p_l;
			}
			p_lf = p_l;
			p_lf->pos = 1;//������Ϊ�����Ա�֤��ȡ֮��������һ��Ϊ1
			p_lf->num = p_d->v_num;
			p_d = p_d->next;
		}
		while (p_df) { //����ÿ���ո����һ�����ִ����Ӿ�
			p_d = p_df->next;
			while (p_d) {
				p_s = (Statement*)malloc(sizeof(Statement));//����һ�����Ӿ�
				p_s->next = NULL;
				S->num_st++;
				p_sf->next = p_s;
				p_sf = p_s;
				p_sf->num_lit = 2;//ÿ���Ӿ�ֻ�����������Դ���ֻ��һ������Ϊ��
				p_sf->elem = (Literal*)malloc(sizeof(Literal));
				p_sf->elem->num = p_df->v_num;
				p_sf->elem->pos = 0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
				p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
				p_sf->elem->next->num = p_d->v_num;
				p_sf->elem->next->pos = 0;
				p_sf->elem->next->next = NULL;
				p_d = p_d->next;
			}
			p_df = p_df->next;
		}
	}

	//��ÿ��������ÿ��������һ�Σ����ٳ���һ�� �����Ӿ�
	j = 0;
	for (i = 0; i < 9; i++) { //����ÿһ��
		x = j;//���ڼ�¼ÿһ�еĿ�ʼ�ո�λ��
		for (k = 1; k <= 9; k++) { //����ÿ������
			int v[10];//���ڴ������еĿո���ÿ�����ֿ��ܳ���λ�õı�Ԫ��
			v[0] = 0;//�������ڴ洢�����ڴ��г��ִ���
			int a;//���ڱ���v����
			int b;
			a = 1;
			j = x;
			while ((holes[j].x == i) && j < hole_num) { //�ҵ�ÿ�����ֶ�Ӧ�Ŀո����λ�ñ�����Ӧ��Ԫ��
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
			p_s = (Statement*)malloc(sizeof(Statement));//����һ��������һ�������ٳ���һ�����ɹ�ʽ
			S->num_st++;//�Ӿ�����һ
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
				p_lf->pos = 1;//��ֻ֤���������ٳ���һ�Σ��ʴ��Ӿ������ȫΪ��
				p_lf->num = v[a];
			}
			for (a = 1; a <= v[0]; a++) { //����һ��������һ����������һ�����ɹ�ʽ
				for (b = a + 1; b <= v[0]; b++) {
					p_s = (Statement*)malloc(sizeof(Statement));
					S->num_st++;//�Ӿ�����һ
					p_s->num_lit = 2;
					p_s->next = NULL;
					p_sf->next = p_s;
					p_sf = p_s;
					p_sf->elem = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->num = v[a];
					p_sf->elem->pos = 0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
					p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->next->num = v[b];
					p_sf->elem->next->pos = 0;
					p_sf->elem->next->next = NULL;
				}
			}
		}
	}

	//��ÿ��������ÿ��������һ�Σ����ٳ���һ�� �����Ӿ�
	for (j = 0; j < 9; j++) {
		for (k = 1; k <= 9; k++) { //����ÿ������
			int v[10];//���ڴ������еĿո���ÿ�����ֿ��ܳ���λ�õı�Ԫ��
			v[0] = 0;//�������ڴ洢�����ڴ��г��ִ���
			int a;//���ڱ���v����
			a = 1;
			int b;
			for (i = 0; i < hole_num; i++) { //�ҵ�ÿ�����ֶ�Ӧ�Ŀո����λ�ñ�����Ӧ��Ԫ��
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
			p_s = (Statement*)malloc(sizeof(Statement));//����һ��������һ�������ٳ���һ�����ɹ�ʽ
			S->num_st++;//�Ӿ�����һ
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
				p_lf->pos = 1;//��ֻ֤���������ٳ���һ�Σ��ʴ��Ӿ������ȫΪ��
				p_lf->num = v[a];
			}
			for (a = 1; a <= v[0]; a++) { //����һ��������һ����������һ�����ɹ�ʽ
				for (b = a + 1; b <= v[0]; b++) {
					p_s = (Statement*)malloc(sizeof(Statement));
					S->num_st++;//�Ӿ�����һ
					p_s->num_lit = 2;
					p_s->next = NULL;
					p_sf->next = p_s;
					p_sf = p_s;
					p_sf->elem = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->num = v[a];
					p_sf->elem->pos = 0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
					p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->next->num = v[b];
					p_sf->elem->next->pos = 0;
					p_sf->elem->next->next = NULL;
				}
			}
		}
	}
	//��ÿ��������ÿ���ӹ���������һ�Σ����ٳ���һ�� �����Ӿ�
	int place;//���ڱ�����
	for (place = 0; place < 9; place++) {
		int ub_x;//��ʾ�����Ͻ�
		int ub_y;
		int lb_x;//��ʾ�����½�
		int lb_y;
		lb_x = (place / 3) * 3;
		ub_x = (place / 3 + 1) * 3;
		switch (place) { //ȷ����ǰ����Ӧ�����½�
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
		for (k = 1; k <= 9; k++) //����ÿ������
		{
			int v[10];//���ڴ������еĿո���ÿ�����ֿ��ܳ���λ�õı�Ԫ��
			v[0] = 0;//�������ڴ洢�����ڴ��г��ִ���
			int a;//���ڸ�������
			int b;
			a = 0;
			b = 1;
			for (a = 0; a < hole_num; a++) { //�ҵ�ÿ�����ֶ�Ӧ�Ŀո����λ�ñ�����Ӧ��Ԫ��
				if ((holes[a].x >= lb_x) && (holes[a].x < ub_x) && (holes[a].y >= lb_y) && (holes[a].y < ub_y)) { //���ո��ڵ�ǰ����ʱ
					p_df = holes[a].elem;
					while (p_df) { //�����ո��п��ܳ��ֵ�����
						if (p_df->num == k) { //���ǡΪ��ǰ�������������
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
			p_s = (Statement*)malloc(sizeof(Statement));//����һ��������һ�������ٳ���һ�����ɹ�ʽ
			S->num_st++;//�Ӿ�����һ
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
				p_lf->pos = 1;//��ֻ֤���������ٳ���һ�Σ��ʴ��Ӿ������ȫΪ��
				p_lf->num = v[a];
			}
			for (a = 1; a <= v[0]; a++) { //����һ��������һ����������һ�����ɹ�ʽ
				for (b = a + 1; b <= v[0]; b++) {
					p_s = (Statement*)malloc(sizeof(Statement));
					S->num_st++;//�Ӿ�����һ
					p_s->num_lit = 2;
					p_s->next = NULL;
					p_sf->next = p_s;
					p_sf = p_s;
					p_sf->elem = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->num = v[a];
					p_sf->elem->pos = 0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
					p_sf->elem->next = (Literal*)malloc(sizeof(Literal));
					p_sf->elem->next->num = v[b];
					p_sf->elem->next->pos = 0;
					p_sf->elem->next->next = NULL;
				}
			}
		}
	}

	//�ɱ�Ԫ�����ɱ�Ԫ��ֵ��ϵ����
	Varies = (int*)malloc((S->num_v + 1) * sizeof(int));
	for (i = 1; i < (S->num_v + 1); i++)
		Varies[i] = -1;
	return Varies;
}

/*
��cnf��Ԫ��ֵ��ϵת��Ϊ�����ĽⲢ���
����Ϊһ��cnf��Ԫ��ֵ��ϵ
���Ϊ�����Ľ�
�㷨˼�룺�������Ԫ�أ�����Ԫ��Ϊ0ʱ���ҵ��ո������ж�Ӧ�Ŀո񣬱����鿴�ո����Ǹ����ֶ�Ӧ�ı�ԪΪ�������������
*/
void ShowSudResult(int* Varies, hole* holes, int(*sud)[9]) {
	int i;//���ڱ����������
	int j;
	int k = 0;//���ڱ����ո�����
	digtal* p;

	printf("\n******************************\n\n");
	printf("�����Ľ�Ϊ��\n\n");
	printf("        -------------------\n");
	for (i = 0; i < 9; i++) {
		printf("\t|");
		for (j = 0; j < 9; j++) {
			if (sud[i][j] == 0) { //���˴�Ϊ��ʱ
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