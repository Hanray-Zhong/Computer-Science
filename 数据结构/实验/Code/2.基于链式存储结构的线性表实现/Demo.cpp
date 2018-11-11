#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

/* DATA DEFINE */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

/* TYPE DEFINE */
typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

// 创建单个的储存空间
typedef struct LNode {
    ElemType data;
    struct Lnode * next;
}LNode, *LinkList;

// 头节点
typedef struct {
    char Node_name[20];
    LinkList TopLnode;
}Top;

// 创建链表
typedef struct {
    Top * elem;
    int length;
    int listSize;
}SqList;

/*---------------基本方法----------------*/
status IntiaList(SqList & L);                                       // 初始化链表
status IntiaList(LinkList & L);                                     // 初始化链表
status DestroyList(LinkList & L);                                   // 销毁表
status ClearList(LinkList & L);                                     // 清空表
status ListEmpty(LinkList L);                                       // 判定空表
int    ListLength(LinkList L);                                      // 求表长
status GetElem(LinkList L, int i, ElemType & e);                    // 获得元素
status LocateElem(LinkList L, ElemType e, status (*Compare)(ElemType a, ElemType b));         // 查找元素
status PriorElem(LinkList L, ElemType cur, ElemType * pre_e);       // 获得前驱
status NextElem(LinkList L, ElemType cur, ElemType * next_e);       // 获得后继
status ListInsert(LinkList * L, int i, ElemType e);                 // 插入元素
status ListDelete(LinkList * L, int i, ElemType * e);               // 删除元素
status ListTrabverse(SqList L);                                     // 遍历表
status Compare(ElemType a, ElemType b);

/*---------------存储链式表----------------*/
status SaveList(SqList L);
status ReadList(SqList * L);



int main() {
    SqList L;  int op=1;
    while(op){
	    system("cls");	printf("\n\n");
	    printf("      Menu for Linear Table On Sequence Structure \n");
	    printf("-------------------------------------------------\n");
	    printf("    	  1. IntiaList       7. LocateElem\n");
	    printf("    	  2. DestroyList     8. PriorElem\n");
	    printf("    	  3. ClearList       9. NextElem \n");
	    printf("    	  4. ListEmpty       10. ListInsert\n");
	    printf("    	  5. ListLength      11. ListDelete\n");
	    printf("    	  6. GetElem         12. ListTrabverse\n");
	    printf("    	  0. Exit\n");
	    printf("-------------------------------------------------\n");
	    printf("    Please chose : [0~12]:");
	    scanf("%d",&op);
        getchar();
        switch(op){
	        case 1:
		        if (IntiaList(L) == OK) 
                    printf("Success\n");
		        else 
                    printf("failed\n");
		        getchar();
		        break;
	        case 2:
                if (DestroyList(&L) == OK)
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 3:
		        if (ClearList(L) == OK) 
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 4:
		        if (ListEmpty(L) == TRUE)
                    printf("The list is empty\n");
                else
                    printf("The list isn't empty\n");     
		        getchar();
		        break;
	        case 5:
		        printf("The list length is : %d\n", ListLength(L));     
		        getchar();
		        break;
	        case 6:
		        int index;
                ElemType e;
                printf("Please input the index : ");
                scanf("%d", &index);
                getchar();
                if (GetElem(L, index, e) != ERROR)
                    printf("The element is : %d\n", e);
                else
                    printf("Failed\n");
		        getchar();
		        break;
	        case 7:
                printf("Please input the element : ");
                scanf("%d", &e);
                getchar();
		        if (LocateElem(L, e) == ERROR)
                    printf("There is not the element\n");
                else 
                    printf("The index is : %d", LocateElem(L, e));
		        getchar();
		        break;
	        case 8:
                ElemType cue, pre;
                printf("Please input the element : ");
                scanf("%d", &cue);
                getchar();
		        if (PriorElem(L, cue, &pre) == OK)
                    printf("The prior element is : %d\n", pre);
                else
                    printf("There is not the element\n");
		        getchar();
		        break;
	        case 9:
		        ElemType next;
                printf("Please input the element : ");
                scanf("%d", &cue);
                getchar();
		        if (NextElem(L, cue, &next) == OK)
                    printf("The next element is : %d\n", next);
                else
                    printf("There is not the element\n");
		        getchar();
		        break;
	        case 10:
                printf("Please input the index : ");
                scanf("%d", &index);
                getchar();
                printf("Please input the element : ");
                scanf("%d", &e);
                getchar();
		        if (ListInsert(L, index, e) == OK)
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 11:
		        printf("Please input the index : ");
                scanf("%d", &index);
                getchar();
		        if (ListDelete(L, index, &e) == OK)
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 12:
		        if(!ListTrabverse(L)) 
                    printf("The list is empty!\n");
		        getchar();
		        break;
	        case 0:
                break;
	    }
    }
    printf("Thank you for using!\n");
    getchar();
    return 0;
}

