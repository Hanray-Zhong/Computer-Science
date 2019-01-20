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
	/*树结点存放的数据的结构类型*/
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
	
	/*将线性表初始化*/
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
		printf("20.更改当前操作的树\n\n");
		printf("------------------------------------------\n");
		printf("选择你的操作:");
		scanf("%d", &operate);
		switch (operate)
		{
		case 1:
			/*构造空二叉树*/
			printf("\n输入构造的空二叉树名称：\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++) {
				if (strcmp(L.elem[i - 1].name, treeName) == 0) break;
			}
			if (i <= L.length) {
				printf("此名称已经存在。\n\n");
				getchar();
				getchar();
				break;
			}
			if (InitBiTree(L, treeName) == OK)
			{
				printf("成功构造空二叉树！\n\n");
			}
			else printf("空二叉树构造失败!\n\n");
			getchar();
			getchar();
			break;
		case 2:
			/*销毁二叉树*/
			printf("\n输入销毁的二叉树的名称：\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++) {
				if (strcmp(L.elem[i - 1].name, treeName) == 0) break;
			}
			if (i>L.length) {
				printf("无法找到该名称的二叉树!\n");
				getchar();
				getchar();
				break;
			}
			if (DestroyBiTree(L.elem[i - 1].HeadNode) == OK) {  
				for (; i<L.length; i++) {  //移动顺序表之后的数据元素
					strcpy(L.elem[i - 1].name, L.elem[i].name);
					L.elem[i - 1].HeadNode = L.elem[i].HeadNode;
				}
				printf("成功销毁了二叉树！\n");
				L.length--;    
				defaultTree = L.length - 1 ;
			}
			else printf("二叉树的销毁操作失败！\n");   
			getchar();
			getchar();
			break;
		case 3:
			
			//CreateBiTree
			printf("\n输入构造的二叉树名称：\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++)
			{//在线性表中逐个查找，看二叉树是否存在
				if (strcmp(L.elem[i - 1].name, treeName) == 0)break;
			}
			if (i <= L.length)
			{
				printf("\n此名称已经存在\n");
		        getchar();
				getchar();
				break;
			}
			printf("\n按照先序顺序，依次输入各个结点的元素('#' 表示该结点为空)：\n");
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
				printf("\n成功构造二叉树！\n");
			}
			else if (i == INFEASIBLE) printf("\n成功构造二叉树，但是，所构造的为空二叉树!\n");
			else if (i == FALSE) printf("\n构造二叉树失败\n");
			
			getchar();
			break;
		case 4:
			//清空二叉树
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			if (ClearBiTree(L.elem[defaultTree - 1].HeadNode) == OK) printf("\n成功清空二叉树!\n");  
			else printf("清空二叉树失败!\n");
			getchar();
			getchar();
			break;
		case 5:
			//判定二叉树是否为空
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			if (BiTreeEmpty(L.elem[defaultTree - 1].HeadNode) == OK) printf("\n当前二叉树是空二叉树。\n");
			else printf("\n当前二叉树不是空的。\n");
			getchar();
			getchar();
			break;
		case 6:
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			if (BiTreeDepth(L.elem[defaultTree - 1].HeadNode->lchild) == 0) printf("\n当前二叉树是空二叉树!\n");
			else printf("\n当前操作的二叉树的深度为:%d\n", BiTreeDepth(L.elem[defaultTree - 1].HeadNode->lchild));
			getchar();
			getchar();
			break;
		case 7:
			//找到树根
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			if (Root(L.elem[defaultTree - 1].HeadNode) == NULL) printf("\n当前二叉树是空的,没有树根!\n");  
			else printf("\n当前二叉树根结点标记为：%c \n", Root(L.elem[defaultTree - 1].HeadNode)->data.tag);
			getchar();
			getchar();
			break;
		case 8:
			//找到树中某结点的值
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n输入你想查找的结点标记：\n");
			getchar(); e = getchar();
			if (Value(L.elem[defaultTree - 1].HeadNode, e) == NULL)
			{
				printf("\n该二叉树中不存在所输入的结点！！\n");
			}else if (Value(L.elem[defaultTree - 1].HeadNode, e) == INFEASIBLE) printf("\n该结点无值!请先用Assign函数对该结点赋值。\n");
			else printf("\n在当前二叉树中，此二叉树结点%c的值为:%c\n",e, Value(L.elem[defaultTree - 1].HeadNode, e));
			getchar();
			getchar();
			break;
		case 9:
			//给树中某结点附值
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n输入你希望赋值结点(char)\n");
			getchar(); e = getchar();
			printf("\n输入你希望附的值(char)：\n");
			getchar(); v = getchar();
			if (Assign(L.elem[defaultTree - 1].HeadNode, e, v) == OK) printf("\n给结点赋值成功!\n");
			else printf("\n二叉树中没有此结点，给结点赋值失败!\n");
			getchar();
			getchar();
			break;
		case 10:
			//找到树的父结点
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n输入结点的标记：\n");
			getchar();
			e = getchar();
			if (Parent(L.elem[defaultTree - 1].HeadNode, e) == NULL) 
				printf("\n所输入结点为此树的根，或不存在父结点，或此树中不含所输入结点。\n");
			else 
				printf("\n所输入结点的父结点的标记是：%c \n", Parent(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 11:
			//找到树的左孩子
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n输入你希望找到其左孩子的结点的标记：（字符）\n");
			getchar(); e = getchar();
			if (LeftChild(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n所输入结点没有左孩子，或该二叉树中不含此结点！\n");
			else printf("\n所输入结点的左孩子的标记为：%c \n", LeftChild(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 12:
			//找到树的右孩子
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n输入你希望找到其右孩子的结点的标记：\n");
			getchar(); e = getchar();
			if (RightChild(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n所输入结点无右孩子，或该二叉树中不含此结点！\n");
			else printf("\n所输入结点的右孩子的标记为：%c\n", RightChild(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 13:
			//寻找左兄弟
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n输入你希望找到其左兄弟的结点的标记：\n");
			getchar(); e = getchar();
			if (LeftSibling(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n此结点没有左兄弟，或该二叉树不含所输入结点！\n");
			else printf("\n该结点的左兄弟的标记为：%c\n", LeftSibling(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 14:
			//寻找右兄弟
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n请输入你希望找到其右兄弟的结点的标记：\n");
			getchar(); e = getchar();
			if (RightSibling(L.elem[defaultTree - 1].HeadNode, e) == NULL) printf("\n此结点没有右兄弟，或二叉树中不含所输入结点！\n");
			else printf("\n所输入结点的右兄弟的值为：%c\n", RightSibling(L.elem[defaultTree - 1].HeadNode, e)->data.tag);
			getchar();
			getchar();
			break;
		case 15:
			//插入子树
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n请输入你希望插入子树的结点（字符）\n");
			getchar(); e = getchar();
			printf("插入到该结点的左子树，请输入0；右子树，请输入1。\n");
		    getchar(); LorR = getchar();
			printf("\n请按照先序输入插入树的各个结点的数据（char），'#'表示此节点不存在！\n");
			getchar();
			j = 0;
			while ((t = getchar()) != '\n') {
				input[j] = t;
				j++;
			}
			input[j] = '\n';
			j = InsertChild(L, defaultTree - 1, e, LorR, input);
			if (j == INFEASIBLE) printf("\n当前二叉树是空的！\n");
			else if (j == OVERFLOW) printf("\n所输入的子树不符合条件，插入无效！\n");
			else if (j == OK) printf("\n成功插入子树！\n");
			else printf("\n插入失败了,因为二叉树%s中不存在节点%c \n", L.elem[defaultTree - 1].name, e);
			getchar();
			break;
		case 16:
			//删除子树
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n请输入你希望删除子节点的字符标记（char）\n");
			getchar();
			e = getchar(); 
			printf("\n删除该结点的左结点，请输入0；删除该结点的右结点，请输入1\n"); 
			getchar(); LorR = getchar();
			j = DeleteChild(L, i - 1, e, LorR);
			if (j == OK) printf("\n成功删除结点！\n");
			else if (j == INFEASIBLE) printf("\n所删除的二叉树为空，不可执行！\n");
			else printf("\n删除失败,当前二叉树%s中不含节点%c！\n", L.elem[defaultTree - 1].name, e);
			getchar();
			getchar();
			break;
		case 17:
			//前序遍历
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n-----------------所有元素 -----------------------\n");
			if (PreOrderTraverse(L.elem[defaultTree - 1].HeadNode->lchild) == FALSE) printf("此二叉树是空树！");
			printf("\n------------------ 结束 ------------------------\n\n");
			getchar();
			getchar();
			break;
		case 18:
			//中序遍历
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n----------------所有元素 -----------------------\n");
			if (InOrderTraverse(L.elem[defaultTree - 1].HeadNode->lchild) == FALSE) printf("\n此二叉树是空树！");
			printf("\n------------------结束 ------------------------\n\n");
			getchar();
			getchar();
			break;
		case 19:
			//后序遍历
			if (defaultTree == -1) {
				printf("当前无二叉树存在，请先创建二叉树!\n");
				printf("\n（按任意键返回……）\n");
				getchar(); getchar();
				break;
			}
			printf("\n-----------------所有元素 -----------------------\n");
			if (PostOrderTraverse(L.elem[defaultTree - 1].HeadNode->lchild) == FALSE) printf("\n此二叉树是空树！");
			printf("\n------------------ 结束 ------------------------\n\n");
			printf("\n");
			getchar();
			getchar();
			break;
		case 20:
			printf("\n输入更换的二叉树的名称：\n");
			scanf("%s", treeName);
			for (i = 1; i <= L.length; i++) {
				if (strcmp(L.elem[i - 1].name, treeName) == 0) break;
			}
			if (i>L.length) {
				printf("无法找到该名称的二叉树!\n");
				getchar();
				
				getchar();
				break;
			}
			defaultTree = i;
			printf("成功将当前操作树转为:%s\n", treeName);
			getchar();
			getchar();
			break;
		case 0:
			break;
		}
	}
	printf("感谢使用本系统！\n");
	return 0;
}


/*case 1: 构建一个新的二叉树*/
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

/*case 2: 销毁二叉树*/
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

/*case 3: 创建一个二叉树*/
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
		//树根不存在，则返回不可执行
		L.length++;
		return INFEASIBLE;
	}
	
	curp = (BiTree)malloc(sizeof(BiTNode));
	curp->data.tag = treeString[0];
	curp->lchild = curp->rchild = NULL;

	L.elem[L.length].HeadNode->lchild = curp; //将当前树的头指向根
	temp[peak] = curp;
	while (treeString[i] != '\n') 
	{
		if (treeString[i] != '#') 
		{
			curp = (BiTree)malloc(sizeof(BiTNode));
			curp->data.tag = treeString[i];
			curp->lchild = curp->rchild = NULL;
			while (temp[peak]->rchild != NULL) peak--; //退回到子结点未满的结点上
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
		i++;  //下一个
	}
	L.elem[L.length].HeadNode->data.tag = n;
	L.length++;
	return OK;
}

/*case4:清空二叉树*/
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

/*case5:判断二叉树是否为空*/
Status BiTreeEmpty(BiTree T) {
	if (T->data.tag == 0) return OK;
	return FALSE;
}

/*case6：判断二叉树的深度*/
int BiTreeDepth(BiTree T) {
	int i, j;
	if (T == NULL) return 0;
	i = BiTreeDepth(T->lchild);
	j = BiTreeDepth(T->rchild);
	if (i>j) return (i + 1);
	return (j + 1);
}

/*case7: 找到树的根*/
BiTree Root(BiTree T) {
	return T->lchild;
}

/*case8: 找到元素所在结点*/
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

/*case9:给二叉树中的结点赋值*/
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

/*case10:找到所输入值的父结点*/
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

/*case11:找到左孩子*/
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

/*case12:找到右孩子*/
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

/*case13:找到左兄弟*/
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

/*case14:找到右兄弟*/
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

/*case 15:插入子树*/
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
	if (CT->rchild != NULL) return OVERFLOW;  //构造的子树右子树不为空，报错
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


/*case 16:删除子树*/
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

/*case 17:前序遍历*/
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

/*case 18:中序遍历*/
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

/*case 19:后序遍历*/
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
