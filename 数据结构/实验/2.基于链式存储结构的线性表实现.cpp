#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"

/* DATA DEFINE */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define OVERFLOW -2

/* TYPE DEFINE */
typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 10
#define LISTINCREMENT  10
// 定义节点
typedef struct Lnode {
    ElemType data;
    struct Lnode * next;
}LNode, *LinkList;

status IntiaList(LinkList * L);                             // 初始化一个链表
status DestroyList(LinkList * L);                           // 销毁表
status ClearList(LinkList * L);                             // 清空表
status ListEmpty(LinkList L);                               // 判定空表
int    ListLength(LinkList L);                              // 求表长
status GetElem(LinkList L, int i, ElemType * e);              // 获得元素
status LocateElem(LinkList L, ElemType e, status (*Compare)(ElemType a, ElemType b));                 // 查找元素
status PriorElem(LinkList L, ElemType cur, ElemType * pre_e); // 获得前驱
status NextElem(LinkList L, ElemType cur, ElemType * next_e); // 获得后继
status ListInsert(LinkList * L, int i, ElemType e);           // 插入元素
status ListDelete(LinkList * L, int i, ElemType * e);         // 删除元素
status ListTrabverse(LinkList L, status (*Visit)(ElemType e));                           // 遍历表
status Compare(ElemType a, ElemType b);                     // 比较
status Visit(ElemType e);

extern bool isNULL = true;

int main() {
    LinkList L = NULL;
	int op=1;
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
        switch(op) {
	        case 1:
		        if (IntiaList(&L) == OK) {
		        	printf("Success\n");
				}
		        else 
                    printf("failed\n");
		        getchar();
		        break;
	        case 2:
                if (DestroyList(&L) == OK) {
                	printf("Success\n");
				}
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 3:
		        if (ClearList(&L) == OK) 
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 4:
		        ListEmpty(L);
		        getchar();
		        break;
	        case 5:
		        if (ListLength(L) != ERROR) {
                    printf ("The length is : %d", ListLength(L));
                }
		        getchar();
		        break;
	        case 6:
		        int index;
                ElemType e;
                printf("Please input the index : ");
                scanf("%d", &index);
                getchar();
                if (GetElem(L, index, &e) != ERROR)
                    printf("The element is : %d\n", e);
                else
                    printf("Failed\n");
		        getchar();
		        break;
	        case 7:
                printf("Please input the element : ");
                scanf("%d", &e);
                getchar();
		        if (LocateElem(L, e, Compare) != ERROR)
                    printf("The index is : %d", LocateElem(L, e, Compare));
		        getchar();
		        break;
	        case 8:
                ElemType cue, pre;
                printf("Please input the element : ");
                scanf("%d", &cue);
                getchar();
		        if (PriorElem(L, cue, &pre) == OK)
                    printf("The prior element is : %d\n", pre);
		        getchar();
		        break;
	        case 9:
		        ElemType next;
                printf("Please input the element : ");
                scanf("%d", &cue);
                getchar();
		        if (NextElem(L, cue, &next) == OK)
                    printf("The next element is : %d\n", next);
		        getchar();
		        break;
	        case 10:
                printf("Please input the index : ");
                scanf("%d", &index);
                getchar();
                printf("Please input the element : ");
                scanf("%d", &e);
                getchar();
		        if (ListInsert(&L, index, e) == OK)
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 11:
		        printf("Please input the index : ");
                scanf("%d", &index);
                getchar();
		        if (ListDelete(&L, index, &e) == OK)
                    printf("Success\n");
                else 
                    printf("Failed\n");
		        getchar();
		        break;
	        case 12:
		        ListTrabverse(L, Visit);
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


status IntiaList(LinkList * L) {
    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL)
        exit(OVERFLOW);
    (*L)->data = 0;
    (*L)->next = NULL; 
    isNULL = false;
    return OK;
}

status DestroyList(LinkList * L) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
	LinkList p, q;
    p = *L;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
    isNULL = true;
    return OK;
}

status ClearList(LinkList * L) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    LinkList p, q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

status ListEmpty(LinkList L) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    if (L->next == NULL) {
        printf ("The list is empty.");
        return TRUE;
    }
    else {
        printf ("The list isn't empty.");
        return FALSE;
    }
}

int ListLength(LinkList L) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

status GetElem(LinkList L, int i, ElemType * e) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    int times = 1;              // 计数
    LinkList p = L->next;
    if (i < 1 || i > ListLength(L)) {
        printf ("The index is illegal.");
        return ERROR;
    }
    while (p && times < i) {
        p = p->next;
        times++;
    }
    *e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, status(*Compare)(ElemType, ElemType)) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    int index = 0;
    LinkList p = L->next;
    while (p) {
        index++;
        if (Compare(p->data, e)) {
            return index;
        }
        p = p->next;
    }
    printf ("The element is not in the list.");
    return ERROR;
}

status PriorElem(LinkList L, ElemType cue, ElemType * pre) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    LinkList p = L->next;
    while (p->next != NULL && p->next->data != cue) {
        p = p->next;
    }
    if (p->next == NULL) {
        printf ("The pre element doesn't exist.");
        return ERROR;
    }
    *pre = p->data;
    return OK;
}

status NextElem(LinkList L, ElemType cue, ElemType * next) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    LinkList p = L->next; 
    while (p->next != NULL && p->data != cue) {
        p = p->next;
    }
    if (p->next == NULL) {
        printf ("The next element doesn't exist.");
        return ERROR;
    }
    *next = p->next->data;
    return OK;
}

status ListInsert(LinkList * L, int i, ElemType e) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    int j = 1;
    LinkList p, newLode;
    p = *L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
        printf ("The index is illegal.");
        return ERROR;
    }
    newLode = (LinkList)malloc(sizeof(LNode));
    if (newLode == NULL) {
        exit(OVERFLOW);
    }
    newLode->data = e;
    if (p->next == NULL) {
    	newLode->next = NULL;
	}
	else {
    	newLode->next = p->next;	
	}
    p->next = newLode;
    return OK;
}

status ListDelete(LinkList * L, int i, ElemType * e) {
    if (isNULL) {
        printf ("The list is NULL.");
        return ERROR;
    }
    int j = 1;
    LinkList p, q;
    p = *L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (i > ListLength(*L)) {
        printf ("The index is illegal.");
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    q = NULL;
    return OK;
}

status ListTrabverse(LinkList L, status(*visit)(ElemType e)) {
    if (isNULL) {
        printf ("The List is NULL.");
        return ERROR;
    }
    if (ListLength(L) == 0) {
        printf ("The List is empty.");
        return ERROR;
    }
	LinkList p = L->next;
    while (p != NULL) {
        if (!(*visit)(p->data)) {
            printf ("Failed");
        }
        p = p->next;
    }
    return OK;
}

status Compare(ElemType a, ElemType b) {
    if (a == b) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

status Visit(ElemType e) {
    printf ("%d ", e);
    return OK;
}
