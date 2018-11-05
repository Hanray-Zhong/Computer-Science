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
typedef struct {
    ElemType * elem;
    int length;
    int listSize;
}SqList;


status IntiaList(SqList & L);   // 初始化表
status DestroyList(SqList * L); // 销毁表
status ClearList(SqList & L);    // 清空表
status ListEmpty(SqList L);     // 判定空表
int    ListLength(SqList L);    // 求表长
status GetElem(SqList L,int i,ElemType & e);    // 获得元素
status LocateElem(SqList L,ElemType e);         // 查找元素
status PriorElem(SqList L,ElemType cur,ElemType * pre_e);   // 获得前驱
status NextElem(SqList L,ElemType cur,ElemType * next_e);   // 获得后继
status ListInsert(SqList & L,int i,ElemType e);             // 插入元素
status ListDelete(SqList & L,int i,ElemType * e);           // 删除元素
status ListTrabverse(SqList L); // 遍历表


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

status IntiaList(SqList & L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList * L) {
    free(L);
    L = NULL;
    return OK;
}

status ClearList(SqList & L) {
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L) {
    if (L.length == 0) {
        return TRUE;
    }
    else {
        return ERROR;
    }
}

int ListLength(SqList L) {
    return L.length;
}

status GetElem(SqList L, int i, ElemType & e) {
    if (i < 1 || i > ListLength(L))
        return ERROR;

    e = L.elem[i - 1];
    return e;
}

int LocateElem(SqList L, ElemType e) {
    int index = 1;
    while (*L.elem != e) {
        index++;
        L.elem ++;
        if (index > L.length) {
            return ERROR;
        }
    }
    return index;
}

status PriorElem(SqList L, ElemType cue, ElemType * pre) {
    int i;
    for (i = 0; i < L.listSize; i++) {
        if (L.elem[i] == cue) {
            *pre = L.elem[i - 1];
            return OK;
        }
    }
    return FALSE;
}

status NextElem(SqList L, ElemType cue, ElemType * next) {
    int i; 
    for (i = 0; i < L.listSize - 1; i++) {
        if (L.elem[i] == cue) {
            *next = L.elem[i + 1];
            return OK;
        }
    }
    return FALSE;
}

status ListInsert(SqList & L, int i, ElemType e) {
    ElemType * newbase, *p, *q;
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listSize) {
        newbase = (ElemType * )realloc(L.elem, (L.listSize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) 
            exit(OVERFLOW);
        L.elem = newbase;
        L.listSize += LISTINCREMENT;
    }

    q = &(L.elem[i - 1]);
    for (p = &(L.elem[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }

    *q = e;
    ++L.length;
    
    return OK;
}

status ListDelete(SqList & L, int i, ElemType *e) {
    ElemType *p, *q;
    if (i < 1 || i > L.length || L.elem)
        return ERROR;
    p = &(L.elem[i + 1]);
    e = p;
    q = &(L.elem[L.length - 1]);
    for (p++; p <= q; p++) {
        *(p - 1) = *p;
    }
    --L.length;

    return OK;
}

status ListTrabverse(SqList L) {
    int i;
    if (ListEmpty(L))
        return ERROR;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    return OK;
}
