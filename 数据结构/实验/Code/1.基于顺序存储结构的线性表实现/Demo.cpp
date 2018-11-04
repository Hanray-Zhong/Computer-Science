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
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);   // 获得前驱
status NextElem(SqList L,ElemType cur,ElemType & next_e);   // 获得后继
status ListInsert(SqList & L,int i,ElemType e);             // 插入元素
status ListDelete(SqList & L,int i,ElemType & e);           // 删除元素
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
	    printf("    请选择你的操作[0~12]:");
	    scanf("%d",&op);
        switch(op){
	        case 1:
		        printf("\n----IntiaList功能待实现！\n");
		        if(IntiaList(L)==OK) 
                    printf("线性表创建成功！\n");
		        else 
                    printf("线性表创建失败！\n");
		        getchar();getchar();
		        break;
	        case 2:
		        printf("\n----DestroyList功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 3:
		        printf("\n----ClearList功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 4:
		        printf("\n----ListEmpty功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 5:
		        printf("\n----ListLength功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 6:
		        printf("\n----GetElem功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 7:
		        printf("\n----LocateElem功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 8:
		        printf("\n----PriorElem功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 9:
		        printf("\n----NextElem功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 10:
		        printf("\n----ListInsert功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 11:
		        printf("\n----ListDelete功能待实现！\n");     
		        getchar();getchar();
		        break;
	        case 12:
		        printf("\n----ListTrabverse功能待实现！\n");     
		        if(!ListTrabverse(L)) 
                    printf("线性表是空表！\n");
		        getchar();getchar();
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
    if (i < 0 || i > L.length + 1)
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
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }

    return OK;
}
