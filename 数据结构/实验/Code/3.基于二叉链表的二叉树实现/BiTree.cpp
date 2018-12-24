#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int Status;

typedef char TElemType; 

typedef struct ElemType
{
	/*������ŵ����ݵĽṹ����*/
	char tag;
	char number;
	int isInit;
}ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *TNode, *BiTree;

typedef struct Tree {
	char name[20];
	struct BiTNode *HeadNode;
}Tree;

typedef struct {
	struct Tree *elem;
	int length;
	int listsize;
}SqList;


Status InitBiTree(SqList &L, char *treeName);
Status DestroyBiTree(BiTree &T);
Status CreateBiTree(SqList &L, char *treeName, char *treeString);
Status ClearBiTree(BiTree &T);
Status BiTreeEmpty(BiTree T);
int    BiTreeDepth(BiTree T);
BiTree Root(BiTree T);
char   Value(BiTree &T, TElemType e);
Status Assign(BiTree T, char e, char v);
BiTree Parent(BiTree T, char e);
BiTree LeftChild(BiTree T, char e);
BiTree RightChild(BiTree T, char e);
BiTree LeftSibling(BiTree T, char e);
BiTree RightSibling(BiTree T, char e);
Status InsertChild(SqList &L, int j, TElemType e, char LorR, TElemType *y);
Status DeleteChild(SqList &L, int j, TElemType e, int LorR);
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status PostOrderTraverse(BiTree T);
Status PreOrderTraverseSave(BiTree T);

int main(void) {
	int operate = 1;
	SqList L;
	TElemType input[100], y[100], e, v;
	int defaultTree = -1;
	int i, j;
	char t, LorR, treeName[20];
	char filename[30];
	
	/*�����Ա��ʼ��*/
	L.elem = (Tree *)malloc(LIST_INIT_SIZE * sizeof(Tree)); 
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

	while (operate) {
		system("cls");
		printf("------------------------------------------\n");
		printf("1. InitBiTree      11. LeftChild\n");
		printf("2. DestroyBiTree   12. RightChild\n");
		printf("3. CreateBiTree    13. LeftSibling\n");
		printf("4. ClearBiTree     14. RightSibling\n");
		printf("5. BiTreeEmpty     15. InsertChild\n");
		printf("6. BiTreeDepth     16. DeleteChild\n");
		printf("7. Root            17. PreOrderTraverse\n");
		printf("8. Value           18. InOrderTraverse\n");
		printf("9. Assign          19. PostOrderTraverse\n");
		printf("10.Parent          0.  Exit\n\n");
		printf("20.���ĵ�ǰ��������\n\n");
		printf("------------------------------------------\n");
		printf("ѡ����Ĳ���:");
		scanf("%d", &operate);
		switch (operate)
		{
		case 1:
			/*����ն�����*/
			printf("\n���빹��Ŀն��������ƣ�\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++) {
				if (strcmp(L.elem[i - 1].name, treeName) == 0) break;
			}
			if (i <= L.length) {
				printf("�������Ѿ����ڡ�\n\n");
				getchar();
				getchar();
				break;
			}
			if (InitBiTree(L, treeName) == OK)
			{
				printf("�ɹ�����ն�������\n\n");
			}
			else printf("�ն���������ʧ��!\n\n");
			getchar();
			getchar();
			break;
		case 2:
			/*���ٶ�����*/
			printf("\n�������ٵĶ����������ƣ�\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++) {
				if (strcmp(L.elem[i - 1].name, treeName) == 0) break;
			}
			if (i>L.length) {
				printf("�޷��ҵ������ƵĶ�����!\n");
				getchar();
				getchar();
				break;
			}
			if (DestroyBiTree(L.elem[i - 1].HeadNode) == OK) {  
				for (; i<L.length; i++) {  //�ƶ�˳���֮�������Ԫ��
					strcpy(L.elem[i - 1].name, L.elem[i].name);
					L.elem[i - 1].HeadNode = L.elem[i].HeadNode;
				}
				printf("�ɹ������˶�������\n");
				L.length--;    
				defaultTree = L.length - 1 ;
			}
			else printf("�����������ٲ���ʧ�ܣ�\n");   
			getchar();
			getchar();
			break;
		case 3:
			
			//CreateBiTree
			printf("\n���빹��Ķ��������ƣ�\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++)
			{//�����Ա���������ң����������Ƿ����
				if (strcmp(L.elem[i - 1].name, treeName) == 0)break;
			}
			if (i <= L.length)
			{
				printf("\n�������Ѿ�����\n");
		        getchar();
				getchar();
				break;
			}
			printf("\n��������˳�����������������Ԫ��('#' ��ʾ�ý��Ϊ��)��\n");
			getchar();
			i = 0;
			char input[100];
			while ((t = getchar()) != '\n') {
				input[i] = t;
				i++;
			}
			input[i] = '\n';
			i = CreateBiTree(L, treeName, input);
			if (i == OK)
			{
				defaultTree = L.length;
				printf("\n�ɹ������������\n");
			}
			else if (i == INFEASIBLE) printf("\n�ɹ���������������ǣ��������Ϊ�ն�����!\n");
			else if (i == FALSE) printf("\n���������ʧ��\n");
			
			getchar();
			break;
		case 4:
			//��ն�����
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			if (ClearBiTree(L.elem[defaultTree - 1].HeadNode) == OK) printf("\n�ɹ���ն�����!\n");  
			else printf("��ն�����ʧ��!\n");
			getchar();
			getchar();
			break;
		case 5:
			//�ж��������Ƿ�Ϊ��
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			if (BiTreeEmpty(L.elem[defaultTree - 1].HeadNode) == OK) printf("\n��ǰ�������ǿն�������\n");
			else printf("\n��ǰ���������ǿյġ�\n");
			getchar();
			getchar();
			break;
		case 6:
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			if (BiTreeDepth(L.elem[defaultTree - 1].HeadNode->lchild) == 0) printf("\n��ǰ�������ǿն�����!\n");
			else printf("\n��ǰ�����Ķ����������Ϊ:%d\n", BiTreeDepth(L.elem[defaultTree - 1].HeadNode->lchild));
			getchar();
			getchar();
			break;
		case 7:
			//�ҵ�����
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			if (Root(L.elem[defaultTree - 1].HeadNode) == NULL) printf("\n��ǰ�������ǿյ�,û������!\n");  
			else printf("\n��ǰ�������������Ϊ��%c \n", Root(L.elem[defaultTree - 1].HeadNode)->data.tag);
			getchar();
			getchar();
			break;
		case 8:
			//�ҵ�����ĳ����ֵ
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n����������ҵĽ���ǣ�\n");
			getchar(); e = getchar();
			if (Value(L.elem[defaultTree - 1].HeadNode, e) == NULL)
			{
				printf("\n�ö������в�����������Ľ�㣡��\n");
			}else if (Value(L.elem[defaultTree - 1].HeadNode, e) == INFEASIBLE) printf("\n�ý����ֵ!������Assign�����Ըý�㸳ֵ��\n");
			else printf("\n�ڵ�ǰ�������У��˶��������%c��ֵΪ:%c\n",e, Value(L.elem[defaultTree - 1].HeadNode, e));
			getchar();
			getchar();
			break;
		case 9:
			//������ĳ��㸽ֵ
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n������ϣ����ֵ���(char)\n");
			getchar(); e = getchar();
			printf("\n������ϣ������ֵ(char)��\n");
			getchar(); v = getchar();
			if (Assign(L.elem[defaultTree - 1].HeadNode, e, v) == OK) printf("\n����㸳ֵ�ɹ�!\n");
			else printf("\n��������û�д˽�㣬����㸳ֵʧ��!\n");
			getchar();
			getchar();
			break;
		case 10:
			//�ҵ����ĸ����
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n������ı�ǣ�\n");
			getchar();
			e = getchar();
			if (Parent(L.elem[defaultTree - 1].HeadNode, e) == NULL) 
				printf("\n��������Ϊ�����ĸ����򲻴��ڸ���㣬������в����������㡣\n");
			else 
				printf("\n��������ĸ����ı���ǣ�%c \n", Parent(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 11:
			//�ҵ���������
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n������ϣ���ҵ������ӵĽ��ı�ǣ����ַ���\n");
			getchar(); e = getchar();
			if (LeftChild(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n��������û�����ӣ���ö������в����˽�㣡\n");
			else printf("\n������������ӵı��Ϊ��%c \n", LeftChild(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 12:
			//�ҵ������Һ���
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n������ϣ���ҵ����Һ��ӵĽ��ı�ǣ�\n");
			getchar(); e = getchar();
			if (RightChild(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n�����������Һ��ӣ���ö������в����˽�㣡\n");
			else printf("\n����������Һ��ӵı��Ϊ��%c\n", RightChild(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 13:
			//Ѱ�����ֵ�
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n������ϣ���ҵ������ֵܵĽ��ı�ǣ�\n");
			getchar(); e = getchar();
			if (LeftSibling(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n�˽��û�����ֵܣ���ö����������������㣡\n");
			else printf("\n�ý������ֵܵı��Ϊ��%c\n", LeftSibling(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 14:
			//Ѱ�����ֵ�
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n��������ϣ���ҵ������ֵܵĽ��ı�ǣ�\n");
			getchar(); e = getchar();
			if (RightSibling(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n�˽��û�����ֵܣ���������в����������㣡\n");
			else printf("\n������������ֵܵ�ֵΪ��%c\n", RightSibling(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 15:
			//��������
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n��������ϣ�����������Ľ�㣨�ַ���\n");
			getchar(); e = getchar();
			printf("���뵽�ý�����������������0����������������1��\n");
		    getchar(); LorR = getchar();
			printf("\n�밴����������������ĸ����������ݣ�char����'#'��ʾ�˽ڵ㲻���ڣ�\n");
			getchar();
			j = 0;
			while ((t = getchar()) != '\n') {
				input[j] = t;
				j++;
			}
			input[j] = '\n';
			j = InsertChild(L, defaultTree - 1, e, LorR, input);
			if (j == INFEASIBLE) printf("\n��ǰ�������ǿյģ�\n");
			else if (j == OVERFLOW) printf("\n�����������������������������Ч��\n");
			else if (j == OK) printf("\n�ɹ�����������\n");
			else printf("\n����ʧ����,��Ϊ������%s�в����ڽڵ�%c \n", L.elem[defaultTree - 1].name, e);
			getchar();
			break;
		case 16:
			//ɾ������
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n��������ϣ��ɾ���ӽڵ���ַ���ǣ�char��\n");
			getchar();
			e = getchar(); 
			printf("\nɾ���ý������㣬������0��ɾ���ý����ҽ�㣬������1\n"); 
			getchar(); LorR = getchar();
			j = DeleteChild(L, i - 1, e, LorR);
			if (j == OK) printf("\n�ɹ�ɾ����㣡\n");
			else if (j == INFEASIBLE) printf("\n��ɾ���Ķ�����Ϊ�գ�����ִ�У�\n");
			else printf("\nɾ��ʧ��,��ǰ������%s�в����ڵ�%c��\n", L.elem[defaultTree - 1].name, e);
			getchar();
			getchar();
			break;
		case 17:
			//ǰ�����
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n-----------------����Ԫ�� -----------------------\n");
			if (PreOrderTraverse(L.elem[defaultTree - 1].HeadNode->lchild) == FALSE) printf("�˶������ǿ�����");
			printf("\n------------------ ���� ------------------------\n\n");
			getchar();
			getchar();
			break;
		case 18:
			//�������
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n----------------����Ԫ�� -----------------------\n");
			if (InOrderTraverse(L.elem[defaultTree - 1].HeadNode->lchild) == FALSE) printf("\n�˶������ǿ�����");
			printf("\n------------------���� ------------------------\n\n");
			getchar();
			getchar();
			break;
		case 19:
			//�������
			if (defaultTree == -1) {
				printf("��ǰ�޶��������ڣ����ȴ���������!\n");
				printf("\n������������ء�����\n");
				getchar(); getchar();
				break;
			}
			printf("\n-----------------����Ԫ�� -----------------------\n");
			if (PostOrderTraverse(L.elem[defaultTree - 1].HeadNode->lchild) == FALSE) printf("\n�˶������ǿ�����");
			printf("\n------------------ ���� ------------------------\n\n");
			printf("\n");
			getchar();
			getchar();
			break;
		case 20:
			printf("\n��������Ķ����������ƣ�\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++) {
				if (strcmp(L.elem[i - 1].name, treeName) == 0) break;
			}
			if (i>L.length) {
				printf("�޷��ҵ������ƵĶ�����!\n");
				getchar();
				
				getchar();
				break;
			}
			defaultTree = i;
			printf("�ɹ�����ǰ������תΪ:%s\n", treeName);
			getchar();
			getchar();
			break;
		case 0:
			break;
		}
	}
	printf("��лʹ�ñ�ϵͳ��\n");
	return 0;
}


/*case 1: ����һ���µĶ�����*/
Status InitBiTree(SqList &L, char *treeName)
{
	Tree *newbase;
	if (L.length >= LIST_INIT_SIZE)
	{
		newbase = (Tree *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(Tree));
		if (!newbase)exit(OVERFLOW);
		L.listsize += LISTINCREMENT;
		L.elem = newbase;
	}
	strcpy(L.elem[L.length].name, treeName);
	L.elem[L.length].HeadNode = (BiTree)malloc(sizeof(BiTNode));
	L.elem[L.length].HeadNode->data.tag = 0;
	L.elem[L.length].HeadNode->lchild = L.elem[L.length].HeadNode->rchild = NULL;
	L.length++;
	return OK;
}

/*case 2: ���ٶ�����*/
Status DestroyBiTree(BiTree &T)
{
	int peak = 0;
	BiTree temp[100], p, q;
	p = T;
	if (p->lchild == NULL)
	{
		free(T);
		return OK;
	}
	temp[peak] = p->lchild;
	while (peak>-1)
	{
		p = temp[peak--];
		q = p;
		if (p->lchild)temp[++peak] = p->lchild;
		if (p->rchild)temp[++peak] = p->rchild;
		free(q);
	}
	free(T);
	return OK;
}

/*case 3: ����һ��������*/
Status CreateBiTree(SqList &L, char *treeName, char *treeString) {
	BiTree temp[100], curp, q;
	Tree *newbase;
	int i = 1, peak = 0, n = 1;
	if (L.length >= L.listsize) 
	{
		newbase = (Tree *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(Tree));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	strcpy(L.elem[L.length].name, treeName);
	L.elem[L.length].HeadNode = (BiTree)malloc(sizeof(BiTNode));
	L.elem[L.length].HeadNode->data.tag = 0;
	L.elem[L.length].HeadNode->lchild = L.elem[L.length].HeadNode->rchild = NULL;

	if (treeString[0] == '#') 
	{
		//���������ڣ��򷵻ز���ִ��
		L.length++;
		return INFEASIBLE;
	}
	
	curp = (BiTree)malloc(sizeof(BiTNode));
	curp->data.tag = treeString[0];
	curp->lchild = curp->rchild = NULL;

	L.elem[L.length].HeadNode->lchild = curp; //����ǰ����ͷָ���
	temp[peak] = curp;
	while (treeString[i] != '\n') 
	{
		if (treeString[i] != '#') 
		{
			curp = (BiTree)malloc(sizeof(BiTNode));
			curp->data.tag = treeString[i];
			curp->lchild = curp->rchild = NULL;
			while (temp[peak]->rchild != NULL) peak--; //�˻ص��ӽ��δ���Ľ����
			if (peak <= -1) return FALSE;

			q = temp[peak];
			temp[++peak] = curp;
			if (treeString[i - 1] != '#')
				q->lchild = curp;
			else {
				q->rchild = curp;
			}
			n++;
		}
		else 
		{
			while (temp[peak]->rchild != NULL) peak--;
			q = temp[peak];
			if (treeString[i - 1] != '#')
				q->lchild = NULL;
			else 
			{
				q->rchild = NULL;
				peak--;
			}
		}
		i++;  //��һ��
	}
	L.elem[L.length].HeadNode->data.tag = n;
	L.length++;
	return OK;
}

/*case4:��ն�����*/
Status ClearBiTree(BiTree &T) {
	BiTree temp[100], p, q;
	int peak = 0;
	p = T->lchild;
	if (T->lchild == NULL)return FALSE;
	temp[peak] = T->lchild;
	while (peak>-1) 
	{
		p = temp[peak--];
		q = p;
		if (p->rchild) temp[++peak] = p->rchild;
		if (p->lchild) temp[++peak] = p->lchild;
		free(q);
	}
	T->data.tag = 0;
	T->lchild = NULL;
	return OK;
}

/*case5:�ж϶������Ƿ�Ϊ��*/
Status BiTreeEmpty(BiTree T) {
	if (T->data.tag == 0) return OK;
	return FALSE;
}

/*case6���ж϶����������*/
int BiTreeDepth(BiTree T) {
	int i, j;
	if (T == NULL) return 0;
	i = BiTreeDepth(T->lchild);
	j = BiTreeDepth(T->rchild);
	if (i>j) return (i + 1);
	return (j + 1);
}

/*case7: �ҵ����ĸ�*/
BiTree Root(BiTree T) {
	return T->lchild;
}

/*case8: �ҵ�Ԫ�����ڽ��*/
char Value(BiTree &T, TElemType e) {
	int peak = 0;
	BiTree stack[100], p;
	stack[peak] = T->lchild;
	while (peak>-1) 
	{
		p = stack[peak--];
		if (p->data.tag == e)
		{
			if (p->data.isInit == 1)
			{
				return p->data.number;
			}
			else
			{
				return INFEASIBLE;
			}
		}
		if (p->rchild) stack[++peak] = p->rchild;
		if (p->lchild) stack[++peak] = p->lchild;
	}
	return NULL;
}

/*case9:���������еĽ�㸳ֵ*/
Status Assign(BiTree T, char e, char v) {
	int peak = 0;
	BiTree temp[100], p;
	temp[peak] = T->lchild;
	while (peak>-1)
	{
		p = temp[peak--];
		if (p->data.tag == e)break;
		if (p->rchild)temp[++peak] = p->rchild;
		if (p->lchild)temp[++peak] = p->lchild;
	}
	if (p->data.tag != e)return FALSE;
	p->data.number = v;
	p->data.isInit = 1;
	return OK;
}

/*case10:�ҵ�������ֵ�ĸ����*/
BiTree Parent(BiTree T, char e)
{
	int peak = 0;
	BiTree temp[100], p;
	temp[peak] = T->lchild;
	while (peak > -1)
	{
		p = temp[peak--];
		if (p->rchild)
		{
			if (p->rchild->data.tag == e) {
				peak++;
				break;
			}
			temp[++peak] = p->rchild;
		}
		if (p->lchild)
		{
			if (p->lchild->data.tag == e) {
				peak++;
				break;
			}
			temp[++peak] = p->lchild;
		}
	}
	if (peak <= -1)
		return NULL;
	return p;
}

/*case11:�ҵ�����*/
BiTree LeftChild(BiTree T, char e)
{
	int peak = 0;
	BiTree temp[100], p;
	temp[peak] = T->lchild;
	while (peak > -1)
	{
		p = temp[peak--];
		if (p->data.tag == e) return p->lchild;
		if (p->rchild)temp[++peak] = p->rchild;
		if (p->lchild)temp[++peak] = p->lchild;
	}
	if (peak <= -1)return NULL;

}

/*case12:�ҵ��Һ���*/
BiTree RightChild(BiTree T, char e)
{
	int peak = 0;
	BiTree temp[100], p;
	temp[peak] = T->lchild;
	while (peak > -1)
	{
		p = temp[peak--];
		if (p->data.tag == e) return p->rchild;
		if (p->rchild)temp[++peak] = p->rchild;
		if (p->lchild)temp[++peak] = p->lchild;
	}
	if (peak <= -1)return NULL;

}

/*case13:�ҵ����ֵ�*/
BiTree LeftSibling(BiTree T, char e)
{
	int peak = 0;
	BiTree temp[100], p;
	temp[peak] = T->lchild;
	if (T->lchild->data.tag == e)return NULL;
	while (peak > -1)
	{
		p = temp[peak]--;

		if (p->rchild)
		{
			if (p->rchild->data.tag == e)
			{
				if (p->lchild)
				{
					return p->lchild;
				}
				else {
					return NULL;
				}
			}
			temp[++peak] = p->rchild;
		}
		if (p->lchild)
		{
			if (p->lchild->data.tag == e) return NULL;
			temp[++peak] = p->lchild;
		}
	}
	if (peak <= -1)return NULL;
}

/*case14:�ҵ����ֵ�*/
BiTree RightSibling(BiTree T, char e)
{
	int peak = 0;
	BiTree temp[100], p;
	temp[peak] = T->lchild;
	if (T->lchild->data.tag == e)return NULL;
	while (peak > -1)
	{
		p = temp[peak]--;

		if (p->rchild)
		{
			if (p->rchild->data.tag == e) return NULL;
			temp[++peak] = p->rchild;
		}
		if (p->lchild)
		{
			if (p->lchild->data.tag == e)
			{
				if (p->rchild)
				{
					return p->rchild;
				}
				else 
				{
					return NULL;
				}
			}
			temp[++peak] = p->lchild;
		}
	}
	if (peak <= -1)return NULL;
}

/*case 15:��������*/
Status InsertChild(SqList &L, int j, TElemType e, char LorR, char* x) 
{
	int i, n, peak;
	TNode stack[100], p, q, CT, T;
	i = 1, n = 0, peak = -1;
	stack[++peak] = L.elem[j].HeadNode->lchild;
	if (L.elem[j].HeadNode->data.tag == 0) return INFEASIBLE;
	while (peak>-1) 
	{
		p = stack[peak--];
		if (p->data.tag == e) break;
		if (p->rchild) stack[++peak] = p->rchild;
		if (p->lchild) stack[++peak] = p->lchild;
	}
	if (p->data.tag != e) return FALSE;
	T = p;
	if (x[0] == '#') return OVERFLOW;
	p = (BiTree)malloc(sizeof(BiTNode));
	n++;
	p->data.tag = x[0];
	p->lchild = p->rchild = NULL;
	CT = p;
	peak = -1;
	stack[++peak] = p;
	while (x[i] != '\n') 
	{
		if (x[i] != '#') 
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			p->data.tag = x[i];
			p->lchild = p->rchild = NULL;
			while (stack[peak]->rchild != NULL) peak--;
			if (peak <= -1) return FALSE;
			q = stack[peak];
			stack[++peak] = p;
			if (x[i - 1] != '#')
				q->lchild = p;
			else 
			{
				q->rchild = p;
			}
			n++;
		}
		else 
		{
			while (stack[peak]->rchild != NULL) peak--;
			q = stack[peak];
			if (x[i - 1] != '#')
				q->lchild = NULL;
			else 
			{
				q->rchild = NULL;
				peak--;
			}
		}
		i++;
	}
	if (CT->rchild != NULL) return OVERFLOW;  //�����������������Ϊ�գ�����
	if (LorR == '0') 
	{
		q = T->lchild;
		CT->rchild = q;
		T->lchild = CT;
	}
	else 
	{
		q = T->rchild;
		CT->rchild = q;
		T->rchild = CT;
	}
	L.elem[j].HeadNode->data.tag = L.elem[j].HeadNode->data.tag + n;
	return OK;
	
}


/*case 16:ɾ������*/
Status DeleteChild(SqList &L, int j, TElemType e, int LorR) 
{
	int peak = -1, i = 0;
	TNode stack[100], p, q;
	stack[++peak] = L.elem[j].HeadNode->lchild;
	if (L.elem[j].HeadNode->data.tag == 0) return INFEASIBLE;
	while (peak>-1) 
	{
		p = stack[peak--];
		if (p->data.tag == e) break;
		if (p->rchild) stack[++peak] = p->rchild;
		if (p->lchild) stack[++peak] = p->lchild;
	}
	if (p->data.tag != e) return FALSE;
	peak = -1;
	if (LorR == '0') 
	{
		stack[++peak] = p->lchild;
		p->lchild = NULL;
	}
	else 
	{
		stack[++peak] = p->rchild;
		p->rchild = NULL;
	}
	while (peak>-1) 
	{
		q = stack[peak--];
		i++;
		if (q->rchild) stack[++peak] = q->rchild;
		if (q->lchild) stack[++peak] = q->lchild;
	}
	L.elem[j].HeadNode->data.tag = L.elem[j].HeadNode->data.tag - i;
	return OK;
}

/*case 17:ǰ�����*/
Status PreOrderTraverse(BiTree T) 
{
	if (T != NULL) 
	{
		if (T->data.tag)printf("%c ", T->data.tag);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		return OK;
	}
	return FALSE;
}

/*case 18:�������*/
Status InOrderTraverse(BiTree T) 
{
	if (T != NULL) {
		InOrderTraverse(T->lchild);
		printf("%c ", T->data.tag);
		InOrderTraverse(T->rchild);
		return OK;
	}
	return FALSE;
}

/*case 19:�������*/
Status PostOrderTraverse(BiTree T) 
{
	if (T != NULL) 
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c ", T->data.tag);
		return OK;
	}
	return FALSE;
}
