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

typedef int status;
typedef int VertexDataType;
typedef struct VertexType {
	char value;
	VertexDataType key;
}VertexType;
typedef int InfoType;

typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

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
	bool isNull = true; 
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
		printf(" 请选择你的操作[0~11]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (!isNull) {
				printf("已经存在了一张图。");
				break;
			}
			if (CreateGraph(&G) == OK) {
				printf("图构建成功 \n");
				isNull = false;
			} 
			else
				printf("图构建失败 \n");
			break;
		case 2:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			if (DestroyGraph(&G) == OK) {
				printf("图销毁成功 \n");
				isNull = true; 
			} 
			else
				printf("图销毁失败 \n");
			break;
		case 3:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要查找的顶点e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (LocateVex(G, e) == INFEASTABLE)
				printf("不存在此顶点 \n");
			else
				printf("该顶点在图或网中的序号为%d \n", LocateVex(G, e));
			break;
		case 4:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要查找的顶点e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (LocateVex(G, e) == INFEASTABLE)
				printf("不存在此顶点 \n");
			else {
				printf("该点的值为：%c", GetVex(G, e));
			}
			break;
		case 5:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要查找的顶点e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (LocateVex(G, e) == INFEASTABLE)
				printf("不存在此顶点 \n");
			else {
				printf("请输入要赋予的值c: ");
				fflush(stdin);
				scanf("%c", &c);
				PutVex(&G, e, c);
				printf("成功！");
			}
			break;
		case 6:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要查找的顶点e: ");
			fflush(stdin);
			scanf("%d", &e);
			if (FirstAdjVex(G, e) == INFEASTABLE)
				printf("v没有邻接顶点 \n");
			else if (FirstAdjVex(G, e) == -2)
				printf("不存在此顶点 \n");
			else
				printf("v的第一个邻接顶点的序号为%d \n", FirstAdjVex(G, e));
			break;
		case 7:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要查找的顶点v和其相对的顶点w: ");
			fflush(stdin);
			scanf("%d", &v);
			scanf("%d", &w);
			if (NextAdjVex(G, v, w) == INFEASTABLE)
				printf("w是v的最后一个邻接顶点 \n");
			else if (NextAdjVex(G, v, w) == -2)
				printf("顶点v或w不存在 \n");
			else if (NextAdjVex(G, v, w) == -3)
				printf("w不是v的邻接顶点 \n");
			else
				printf("v相对于w的下一个邻接顶点的序号为%d \n", NextAdjVex(G, v, w));
			break;
		case 8:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要添加的顶点v: ");
			fflush(stdin);
			scanf("%d", &v);
			if (InsertVex(&G, v) == OK)
				printf("添加成功 \n");
			else
				printf("添加失败 \n");
			break;
		case 9:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要删除的顶点v: ");
			fflush(stdin);
			scanf("%d", &v);
			if (DeleteVex(&G, v) == ERROR)
				printf("不存在此顶点 \n");
			else
				printf("删除成功 \n");
			break;
		case 10:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要添加弧的顶点v和顶点w: ");
			fflush(stdin);
			scanf("%d", &v);
			scanf("%d", &w);
			if (InsertArc(&G, v, w) == ERROR)
				printf("顶点v或w不存在 \n");
			else
				printf("添加成功 \n");
			break;
		case 11:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			printf("请输入要删除弧的顶点v和顶点w: ");
			fflush(stdin);
			scanf("%d", &v);
			scanf("%d", &w);
			if (DeleteArc(&G, v, w) == ERROR)
				printf("顶点v或w不存在 \n");
			else
				printf("弧删除成功或已不存在 \n");
			break;
		case 12:
			if (isNull) {
				printf("不存在图。");
				break;
			}
			DFSTraverse(G, Visit);
			break;
		case 13:
			if (isNull) {
				printf("不存在图。");
				break;
			}
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

status CreateGraph(ALGraph *G) {
	int i, j, k;
	VertexDataType va, vb;
	ArcNode *p;
	printf("请输入图的顶点数: ");
	fflush(stdin);
	scanf("%d", &(*G).vexnum);
	printf("请输入图的边数: ");
	fflush(stdin);
	scanf("%d",&(*G).arcnum);
	printf("请输入%d个顶点的ID:\n", (*G).vexnum);
	for (i = 0; i < (*G).vexnum; ++i) {
		fflush(stdin);
		scanf("%d", &(*G).vertices[i].data.key);
		(*G).vertices[i].firstarc = NULL;
	}
	printf("请顺序输入每条边的弧尾和弧头:\n");
	for (k = 0; k < (*G).arcnum; ++k) {
		printf("第%d条边：",k + 1);
		fflush(stdin);
		scanf("%d%d", &va, &vb);
		while (LocateVex(*G, va) == -1 || LocateVex(*G, vb) == -1) {
			printf("找不到对应的节点。请重新输入：");
			fflush(stdin);
			scanf("%d%d", &va, &vb);
		}
		i = LocateVex(*G, va);
		j = LocateVex(*G, vb);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = (*G).vertices[i].firstarc;
		(*G).vertices[i].firstarc = p;
	}
	return OK;
}

status DestroyGraph(ALGraph *G) {
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

status LocateVex(ALGraph G, VertexDataType u) {
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

status FirstAdjVex(ALGraph G, VertexDataType v) {
	ArcNode *p;
	int v1;
	v1 = LocateVex(G, v);
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

status NextAdjVex(ALGraph G, VertexDataType v, VertexDataType w) {
	ArcNode *p;
	int v1, w1;
	v1 = LocateVex(G, v);
	w1 = LocateVex(G, w);
	if (v1 == -1 || w1 == -1)
		return -2;
	p = G.vertices[v1].firstarc;
	while (p&&p->adjvex != w1)
		p = p->nextarc;
	if (!p)
		return -3;
	else if (!p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}

status InsertVex(ALGraph *G, VertexDataType v) {
	(*G).vertices[(*G).vexnum].data.key = v;
	(*G).vertices[(*G).vexnum].firstarc = NULL;
	(*G).vexnum++;
	return OK;
}

status DeleteVex(ALGraph *G, VertexDataType v) {
	ArcNode *p, qq;
	ArcNode *q = &qq;
	int i, j;
	j = LocateVex(*G, v);
	if (j < 0)
		return ERROR;
	p = (*G).vertices[j].firstarc;
	while (p) {
		q = p;
		p = p->nextarc;
		free(q);
		(*G).arcnum--;
	}
	(*G).vexnum--;
	for (i = j; i < (*G).vexnum; i++)
		(*G).vertices[i] = (*G).vertices[i + 1];
	for (i = 0; i < (*G).vexnum; i++) {
		p = (*G).vertices[i].firstarc;
		while (p) {
			if (p->adjvex == j) {
				if (p == (*G).vertices[i].firstarc) {
					(*G).vertices[i].firstarc = p->nextarc;
					free(p);
					p = (*G).vertices[i].firstarc;
					(*G).arcnum--;
				}
				else {
					q->nextarc = p->nextarc;
					free(p);
					p = q->nextarc;
					(*G).arcnum--;
				}
			}
			else {
				if (p->adjvex > j)
					p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	return OK;
}

status InsertArc(ALGraph *G, VertexDataType v, VertexDataType w) {
	ArcNode *p;
	int w1, i, j;
	i = LocateVex(*G, v);
	j = LocateVex(*G, w);
	if (i < 0 || j < 0)
		return ERROR;
	(*G).arcnum++;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = (*G).vertices[i].firstarc;
	(*G).vertices[i].firstarc = p;
	return OK;
}

status DeleteArc(ALGraph *G, VertexDataType v, VertexDataType w) {
	int i, j;
	ArcNode *p, qq;
	ArcNode *q = &qq;
	i = LocateVex(*G, v);
	j = LocateVex(*G, w);
	if (i < 0 || j < 0 || i == j)
		return ERROR;
	p = (*G).vertices[i].firstarc;
	while (p&&p->adjvex != j) {
		q = p;
		p = p->nextarc;
	}
	if (p&&p->adjvex == j) {
		if (p == (*G).vertices[i].firstarc)
			(*G).vertices[i].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		free(p);
		(*G).arcnum--;
	}
	return OK;
}

VertexDataType* GetVexKey(ALGraph G, int v) {
	if (v >= G.vexnum || v < 0)
		exit(ERROR);
	return &G.vertices[v].data.key;
}

void DFS(ALGraph G, int v) {
	VertexDataType v1, w1;
	v1 = *GetVexKey(G, v);
	visited[v] = TRUE;
	visitFunc(G.vertices[v].data.key);
	int w;
	for (w = FirstAdjVex(G, v1); w >= 0; w = NextAdjVex(G, v1, w1 = *GetVexKey(G, w)))
		if (!visited[w])
			DFS(G, w);
}

status DFSTraverse(ALGraph G, void(*visit)(int)) {
	visitFunc = visit;
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v])
			DFS(G, v);
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
	QueuePtr front, rear;
}LinkQueue;

status InitQueue(LinkQueue *Q) {
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}

status DestroyQueue(LinkQueue *Q)
{
	while ((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return OK;
}

status ClearQueue(LinkQueue *Q) {
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

status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q) {
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

status GetHead_Q(LinkQueue Q, QElemType *e) {
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

status DeQueue(LinkQueue *Q, QElemType *e)
{
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
{
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

status BFSTraverse(ALGraph G, void(*visit)(int)) {
	VertexDataType u1, w1;
	LinkQueue Q;
	int v, u, w;
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = FALSE;
	InitQueue(&Q);
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) {
			visited[v] = TRUE;
			visit(G.vertices[v].data.key);
			EnQueue(&Q, v);
			while (!QueueEmpty(Q)) {
				DeQueue(&Q, &u);
				u1 = *GetVexKey(G, u);
				for (w = FirstAdjVex(G, u1); w >= 0; w = NextAdjVex(G, u1, w1 = *GetVexKey(G, w)))
					if (!visited[w]) {
						visited[w] = TRUE;
						visit(G.vertices[w].data.key);
						EnQueue(&Q, w);
					}
			}
		}
	printf("\n");
	return OK;
}