#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INFEASTABLE -1 
#define OVERFLOW -2 
#define MAX_VERTEX_NUM 20 
#define MAX_NAME 3 /* �����ַ�������󳤶�+1 */ 

// typedef enum { DG, DN, AG, AN }GraphKind; /* {����ͼ,������,����ͼ,������} */
typedef int status;
typedef int VertexDataType;
typedef struct VertexType {
	char value;
	VertexDataType key;
}VertexType;
typedef int InfoType;

typedef struct ArcNode {
	int adjvex; /* �û���ָ��Ķ����λ�� */
	struct ArcNode *nextarc; /* ָ����һ������ָ�� */
}ArcNode; /* ���� */

typedef struct VNode{
	VertexType data; /* ������Ϣ */
	ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
}VNode, AdjList[MAX_VERTEX_NUM]; /* ͷ��� */

typedef struct {
	AdjList vertices;
	int vexnum, arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
}ALGraph;// ����ͼ

status CreateGraph(ALGraph *G);
status DestroyGraph(ALGraph *G);
status LocateVex(ALGraph G, VertexDataType u);
char   GetVex(ALGraph G, VertexDataType v);
status PutVex(ALGraph *G, VertexDataType v, char c);
status FirstAdjVex(ALGraph G, VertexDataType v);
status NextAdjVex(ALGraph G, VertexDataType v, VertexDataType w);
status InsertVex(ALGraph *G, VertexDataType v);
status DeleteVex(ALGraph *G, VertexDataType v);
status InsertArc(ALGraph *G, VertexDataType v, VertexDataType w);
status DeleteArc(ALGraph *G, VertexDataType v, VertexDataType w);
status DFSTraverse(ALGraph G, void(*visit)(int));
status BFSTraverse(ALGraph G, void(*visit)(int));
VertexDataType* GetVexKey(ALGraph G, int v);
void(*visitFunc)(int v);
bool visited[MAX_VERTEX_NUM];
void DFS(ALGraph G, int v);
void Visit(int i);

int main() {
	int op = 1;
	char c;
	VertexDataType e, v, w;
	ALGraph G;
	while (op) {
		system("cls");
		printf("\n\n");
		printf("-----------------------------\n");
		printf(" 1. CreateGraph     8. InsertVex\n");
		printf(" 2. DestroyGraph    9. DeleteVex\n");
		printf(" 3. LocateVex       10.InsertArc\n");
		printf(" 4. GetVex          11.DeleteArc\n");
		printf(" 5. PutVex          12.DFSTraverse\n");
		printf(" 6. FirstAdjVex     13.BFSTraverse\n");
		printf(" 7. NextAdjVex      0. Exit\n");
		printf("-------------------------------------------------\n");
		printf(" ��ѡ����Ĳ���[0~11]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (CreateGraph(&G) == OK)
				printf("ͼ�����ɹ� \n");
			else
				printf("ͼ����ʧ�� \n");
			break;
		case 2:
			if (DestroyGraph(&G) == OK)
				printf("ͼ���ٳɹ� \n");
			else
				printf("ͼ����ʧ�� \n");
			break;
		case 3:
			printf("������Ҫ���ҵĶ���e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (LocateVex(G, e) == INFEASTABLE)
				printf("�����ڴ˶��� \n");
			else
				printf("�ö�����ͼ�����е����Ϊ%d \n", LocateVex(G, e));
			break;
		case 5:
			printf("������Ҫ���ҵĶ���e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (LocateVex(G, e) == INFEASTABLE)
				printf("�����ڴ˶��� \n");
			else {
				printf("������Ҫ�����ֵc: ");
				fflush(stdin);
				scanf("%c", &c);
				PutVex(&G, e, c);
				printf("�ɹ���");
			}
			break;
		case 4:
			printf("������Ҫ���ҵĶ���e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (LocateVex(G, e) == INFEASTABLE)
				printf("�����ڴ˶��� \n");
			else {
				printf("�õ��ֵΪ��%c", GetVex(G, e));
			}
			break;
		case 6:
			printf("������Ҫ���ҵĶ���e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (FirstAdjVex(G, e) == INFEASTABLE)
				printf("vû���ڽӶ��� \n");
			else if (FirstAdjVex(G, e) == -2)
				printf("�����ڴ˶��� \n");
			else
				printf("v�ĵ�һ���ڽӶ�������Ϊ%d \n", FirstAdjVex(G, e));
			break;
		case 7:
			printf("������Ҫ���ҵĶ���v������ԵĶ���w: ");
			fflush(stdin);
			scanf("%d", &v);
			scanf("%d", &w);
			if (NextAdjVex(G, v, w) == INFEASTABLE)
				printf("w��v�����һ���ڽӶ��� \n");
			else if (NextAdjVex(G, v, w) == -2)
				printf("����v��w������ \n");
			else if (NextAdjVex(G, v, w) == -3)
				printf("w����v���ڽӶ��� \n");
			else
				printf("v�����w����һ���ڽӶ�������Ϊ%d \n", NextAdjVex(G, v, w));
			break;
		case 8:
			printf("������Ҫ��ӵĶ���v: ");
			fflush(stdin);
			scanf("%d", &v);
			if (InsertVex(&G, v) == OK)
				printf("��ӳɹ� \n");
			else
				printf("���ʧ�� \n");
			break;
		case 9:
			printf("������Ҫɾ���Ķ���v: ");
			fflush(stdin);
			scanf("%d", &v);
			if (DeleteVex(&G, v) == ERROR)
				printf("�����ڴ˶��� \n");
			else
				printf("ɾ���ɹ� \n");
			break;
		case 10:
			printf("������Ҫ��ӻ��Ķ���v�Ͷ���w: ");
			fflush(stdin);
			scanf("%d", &v);
			scanf("%d", &w);
			if (InsertArc(&G, v, w) == ERROR)
				printf("����v��w������ \n");
			else
				printf("��ӳɹ� \n");
			break;
		case 11:
			printf("������Ҫɾ�����Ķ���v�Ͷ���w: ");
			fflush(stdin);
			scanf("%d", &v);
			scanf("%d", &w);
			if (DeleteArc(&G, v, w) == ERROR)
				printf("����v��w������ \n");
			else
				printf("��ɾ���ɹ����Ѳ����� \n");
			break;
		case 12:
			DFSTraverse(G, Visit);
			break;
		case 13:
			BFSTraverse(G, Visit);
			break;
		case 0:
			break;
		}//end of switch
		system("pause");
	}
	return 0;
}

void Visit(int i) {
	printf("%d ", i);
}

status CreateGraph(ALGraph *G) { /* �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼG */
	int i, j, k;
	int w; /* Ȩֵ */
	VertexDataType va, vb;
	ArcNode *p;
	printf("������ͼ�Ķ�����: ");
	fflush(stdin);
	scanf("%d", &(*G).vexnum);
	printf("������ͼ�ı���: ");
	fflush(stdin);
	scanf("%d",&(*G).arcnum);
	printf("������%d�������ֵ:\n", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; ++i) /* ���춥������ */ {
		fflush(stdin);
		scanf("%d", &(*G).vertices[i].data.key);
		(*G).vertices[i].firstarc = NULL;
	}
	printf("��˳������ÿ���ߵĻ�β�ͻ�ͷ(�Կո���Ϊ���):\n");
	for (k = 0; k < (*G).arcnum; ++k) /* ����������� */ {
		printf("��%d���ߣ�",k + 1);
		fflush(stdin);
		scanf("%d%d", &va, &vb);
		while (LocateVex(*G, va) == -1 || LocateVex(*G, vb) == -1) {
			printf("�Ҳ�����Ӧ�Ľڵ㡣���������룺");
			fflush(stdin);
			scanf("%d%d", &va, &vb);
		}
		i = LocateVex(*G, va); /* ��β */
		j = LocateVex(*G, vb); /* ��ͷ */
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = (*G).vertices[i].firstarc; /* ���ڱ�ͷ */
		(*G).vertices[i].firstarc = p;
	}
	return OK;
}

status DestroyGraph(ALGraph *G) { /* ��ʼ����: ͼG���ڡ��������: ����ͼG */
	ArcNode *p, *q;
	(*G).vexnum = 0;
	(*G).arcnum = 0;
	int i;
	for (i = 0; i < (*G).vexnum; ++i) {
		p = (*G).vertices[i].firstarc;
		while (p) {
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	return OK;
}

status LocateVex(ALGraph G, VertexDataType u) { /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
/* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vertices[i].data.key)
			return i;
	return -1;
}

char GetVex(ALGraph G, VertexDataType v) {
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (v == G.vertices[i].data.key)
			return G.vertices[i].data.value;
	return -1;
}

status PutVex(ALGraph *G, VertexDataType v, char c) {
	int i;
	for (i = 0; i < (*G).vexnum; ++i)
		if (v == (*G).vertices[i].data.key) {
			(*G).vertices[i].data.value = c;
			return OK;
		}
	return ERROR;
}

status FirstAdjVex(ALGraph G, VertexDataType v) { /* ��ʼ����: ͼG����,v��G��ĳ������ */
/* �������: ����v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ���,�򷵻�-1 */
	ArcNode *p;
	int v1;
	v1 = LocateVex(G, v); /* v1Ϊ����v��ͼG�е���� */
	if (v1 == -1)
		return -2;
	else {
		p = G.vertices[v1].firstarc;
		if (p)
			return p->adjvex;
		else
			return -1;
	}
}

status NextAdjVex(ALGraph G, VertexDataType v, VertexDataType w) { /* ��ʼ����: ͼG����,v��G��ĳ������,w��v���ڽӶ��� */
/* �������: ����v��(�����w��)��һ���ڽӶ������š� */
/* ��w��v�����һ���ڽӵ�,�򷵻�-1 */
	ArcNode *p;
	int v1, w1;
	v1 = LocateVex(G, v); /* v1Ϊ����v��ͼG�е���� */
	w1 = LocateVex(G, w); /* w1Ϊ����w��ͼG�е���� */
	if (v1 == -1 || w1 == -1)
		return -2;
	p = G.vertices[v1].firstarc;
	while (p&&p->adjvex != w1) /* ָ��p��������ָ���㲻��w */
		p = p->nextarc;
	if (!p)
		return -3;
	else if (!p->nextarc) /* û�ҵ�w��w�����һ���ڽӵ� */
		return -1;
	else /* p->adjvex==w */
		return p->nextarc->adjvex; /* ����v��(�����w��)��һ���ڽӶ������� */
}

status InsertVex(ALGraph *G, VertexDataType v) { /* ��ʼ����: ͼG����,v��ͼ�ж�������ͬ���� */
/* �������: ��ͼG�������¶���v(�������붥����صĻ�,����InsertArc()
ȥ��) */
	(*G).vertices[(*G).vexnum].data.key = v; /* �����¶������� */
	(*G).vertices[(*G).vexnum].firstarc = NULL;
	(*G).vexnum++; /* ͼG�Ķ�������1 */
	return OK;
}

status DeleteVex(ALGraph *G, VertexDataType v) { /* ��ʼ����: ͼG����,v��G��ĳ������ */
/* �������: ɾ��G�ж���v������صĻ� */
	ArcNode *p, qq;
	ArcNode *q = &qq;
	int i, j;
	j = LocateVex(*G, v); /* j�Ƕ���v����� */
	if (j < 0) /* v����ͼG�Ķ��� */
		return ERROR;
	p = (*G).vertices[j].firstarc; /* ɾ����vΪ���ȵĻ���� */
	while (p) {
		q = p;
		p = p->nextarc;
		free(q);
		(*G).arcnum--; /* ���������1 */
	}
	(*G).vexnum--; /* ��������1 */
	for (i = j; i < (*G).vexnum; i++) /* ����v����Ķ���ǰ�� */
		(*G).vertices[i] = (*G).vertices[i + 1];
	for (i = 0; i < (*G).vexnum; i++) /* ɾ����vΪ��ȵĻ�����ұ�Ҫʱ�޸ı���Ķ���λ��ֵ */ {
		p = (*G).vertices[i].firstarc; /* ָ���1������� */
		while (p) /* �л� */ {
			if (p->adjvex == j) {
				if (p == (*G).vertices[i].firstarc) /* ��ɾ����ǵ�1����� */ {
					(*G).vertices[i].firstarc = p->nextarc;
					free(p);
					p = (*G).vertices[i].firstarc;
					(*G).arcnum--; /* ���������1 */
				}
				else {
					q->nextarc = p->nextarc;
					free(p);
					p = q->nextarc;
					(*G).arcnum--; /* ���������1 */
				}
			}
			else {
				if (p->adjvex > j)
					p->adjvex--; /* �޸ı���Ķ���λ��ֵ(���) */
				q = p;
				p = p->nextarc;
			}
		}
	}
	return OK;
}

status InsertArc(ALGraph *G, VertexDataType v, VertexDataType w) { /* ��ʼ����: ͼG����,v��w��G���������� */
/* �������: ��G������<v,w>,��G�������,������Գƻ�<w,v> */
	ArcNode *p;
	int w1, i, j;
	i = LocateVex(*G, v); /* ��β��ߵ���� */
	j = LocateVex(*G, w); /* ��ͷ��ߵ���� */
	if (i < 0 || j < 0)
		return ERROR;
	(*G).arcnum++; /* ͼG�Ļ���ߵ���Ŀ��1 */
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = (*G).vertices[i].firstarc; /* ���ڱ�ͷ */
	(*G).vertices[i].firstarc = p;
	return OK;
}

status DeleteArc(ALGraph *G, VertexDataType v, VertexDataType w) { /* ��ʼ����: ͼG����,v��w��G���������� */
/* �������: ��G��ɾ����<v,w>,��G�������,��ɾ���Գƻ�<w,v> */
	int i, j;
	ArcNode *p, qq;
	ArcNode *q = &qq;
	i = LocateVex(*G, v); /* i�Ƕ���v(��β)����� */
	j = LocateVex(*G, w); /* j�Ƕ���w(��ͷ)����� */
	if (i < 0 || j < 0 || i == j)
		return ERROR;
	p = (*G).vertices[i].firstarc; /* pָ�򶥵�v�ĵ�һ������ */
	while (p&&p->adjvex != j) /* p��������ָ֮�����Ǵ�ɾ����<v,w> */ { /* pָ����һ���� */
		q = p;
		p = p->nextarc;
	}
	if (p&&p->adjvex == j) /* �ҵ���<v,w> */ {
		if (p == (*G).vertices[i].firstarc) /* p��ָ�ǵ�1���� */
			(*G).vertices[i].firstarc = p->nextarc; /* ָ����һ���� */
		else
			q->nextarc = p->nextarc; /* ָ����һ���� */
		free(p); /* �ͷŴ˽�� */
		(*G).arcnum--; /* ���������1 */
	}
	return OK;
}

VertexDataType* GetVexKey(ALGraph G, int v) { /* ��ʼ����: ͼG����,v��G��ĳ���������š��������: ����v��ֵ */
	if (v >= G.vexnum || v < 0)
		exit(ERROR);
	return &G.vertices[v].data.key;
}

void DFS(ALGraph G, int v) { /* �ӵ�v����������ݹ��������ȱ���ͼG���㷨7.5 */
	VertexDataType v1, w1;
	v1 = *GetVexKey(G, v);
	visited[v] = TRUE; /* ���÷��ʱ�־ΪTRUE(�ѷ���) */
	visitFunc(G.vertices[v].data.key); /* ���ʵ�v������ */
	int w;
	for (w = FirstAdjVex(G, v1); w >= 0; w = NextAdjVex(G, v1, w1 = *GetVexKey(G, w)))
		if (!visited[w])
			DFS(G, w); /* ��v����δ���ʵ��ڽӵ�w�ݹ����DFS */
}

status DFSTraverse(ALGraph G, void(*visit)(int)) { /* ��ͼG��������ȱ������㷨7.4 */
	visitFunc = visit; /* ʹ��ȫ�ֱ���VisitFunc,ʹDFS�����躯��ָ����� */
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = FALSE; /* ���ʱ�־�����ʼ�� */
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v])
			DFS(G, v); /* ����δ���ʵĶ������DFS */
	printf("\n");
	return OK;
}

typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front, rear; /* ��ͷ����βָ�� */
}LinkQueue;

status InitQueue(LinkQueue *Q) { /* ����һ���ն���Q */
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}

status DestroyQueue(LinkQueue *Q)
{ /* ���ٶ���Q(���ۿշ����) */
	while ((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return OK;
}

status ClearQueue(LinkQueue *Q) { /* ��Q��Ϊ�ն��� */
	QueuePtr p, q;
	(*Q).rear = (*Q).front;
	p = (*Q).front->next;
	(*Q).front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

status QueueEmpty(LinkQueue Q) { /* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q) { /* ����еĳ��� */
	QueuePtr p;
	p = Q.front;
	int i = 0;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

status GetHead_Q(LinkQueue Q, QElemType *e) /* ������bo2-6.c���� */ { /* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

status EnQueue(LinkQueue *Q, QElemType e)
{ /* ����Ԫ��eΪQ���µĶ�βԪ�� */
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) /* �洢����ʧ�� */
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

status DeQueue(LinkQueue *Q, QElemType *e)
{ /* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
	QueuePtr p;
	if ((*Q).front == (*Q).rear)
		return ERROR;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return OK;
}

status QueueTraverse(LinkQueue Q, void(*vi)(QElemType))
{ /* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()��һ��viʧ��,�����ʧ�� */
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

status BFSTraverse(ALGraph G, void(*visit)(int)) {/*��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited���㷨7.6 */
	VertexDataType u1, w1;
	LinkQueue Q;
	int v, u, w;
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = FALSE; /* �ó�ֵ */
	InitQueue(&Q); /* �ÿյĸ�������Q */
	for (v = 0; v < G.vexnum; v++) /* �������ͨͼ,ֻv=0�ͱ���ȫͼ */
		if (!visited[v]) /* v��δ���� */ {
			visited[v] = TRUE;
			visit(G.vertices[v].data.key);
			EnQueue(&Q, v); /* v����� */
			while (!QueueEmpty(Q)) /* ���в��� */ {
				DeQueue(&Q, &u); /* ��ͷԪ�س��Ӳ���Ϊu */
				u1 = *GetVexKey(G, u);
				for (w = FirstAdjVex(G, u1); w >= 0; w = NextAdjVex(G, u1, w1 = *GetVexKey(G, w)))
					if (!visited[w]) /* wΪu����δ���ʵ��ڽӶ��� */ {
						visited[w] = TRUE;
						visit(G.vertices[w].data.key);
						EnQueue(&Q, w); /* w��� */
					}
			}
		}
	printf("\n");
	return OK;
}
