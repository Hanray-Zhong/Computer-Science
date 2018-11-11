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

#define LIST_INIT_SIZE 1
#define LISTINCREMENT  10
typedef struct {
    ElemType * elem;
    int length;
    int listSize;
}SqList;


status IntiaList(SqList & L);                               // 初始化表
status DestroyList(SqList * L);                             // 销毁表
status ClearList(SqList & L);                               // 清空表
status ListEmpty(SqList L);                                 // 判定空表
int    ListLength(SqList L);                                // 求表长
status GetElem(SqList L,int i,ElemType & e);                // 获得元素
status LocateElem(SqList L,ElemType e, status (*Compare)(ElemType a, ElemType b));                   // 查找元素
status PriorElem(SqList L,ElemType cur,ElemType * pre_e);   // 获得前驱
status NextElem(SqList L,ElemType cur,ElemType * next_e);   // 获得后继
status ListInsert(SqList & L,int i,ElemType e);             // 插入元素
status ListDelete(SqList & L,int i,ElemType * e);           // 删除元素
status ListTrabverse(SqList L);                             // 遍历表
status Compare(ElemType a, ElemType b);                     // 比较

extern bool isNull = TRUE;

int main() {
    SqList L;  
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
		        if (IntiaList(L) == OK) {
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
		        if (LocateElem(L, e, Compare) == ERROR)
                    printf("There is not the element\n");
                else 
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
                else
                    printf("Failed!\n");
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
                    printf("Failed!\n");
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
		        ListTrabverse(L);
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
	isNull = FALSE;
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList * L) {
	L->length = 0;
	isNull = TRUE;
	free(L->elem);
    L = NULL;
    return OK;
}

status ClearList(SqList & L) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    if (L.length == 0) {
        return TRUE;
    }
    else {
        return ERROR;
    }
}

int ListLength(SqList L) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    return L.length;
}

status GetElem(SqList L, int i, ElemType & e) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    if (i < 1 || i > ListLength(L))
        return ERROR;

    e = L.elem[i - 1];
    return e;
}

int LocateElem(SqList L, ElemType e, status(*Compare)(ElemType, ElemType)) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    int index = 1;
    for (index; index <= L.length; index++) {
        if ((*Compare)(L.elem[index - 1], e)) {
            return index;
        }
    }
    return ERROR;
}

status PriorElem(SqList L, ElemType cue, ElemType * pre) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    int i;
    for (i = 0; i < L.listSize; i++) {
        if (L.elem[i] == cue) {
            if (i == 0) {
        		printf("This is the head element!\n");
        		return ERROR;
			}
			*pre = L.elem[i - 1];
            return OK;
        }
    }
    return FALSE;
}

status NextElem(SqList L, ElemType cue, ElemType * next) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    int i; 
    for (i = 0; i < L.listSize - 1; i++) {
        if (L.elem[i] == cue) {
        	if (i == L.length - 1) {
        		printf("This is the rear element!\n");
        		return ERROR;
			}
            *next = L.elem[i + 1];
            return OK;
        }
    }
    printf("There is not the element!\n");
    return FALSE;
}

status ListInsert(SqList & L, int i, ElemType e) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    ElemType * newbase, *p, *q;
    if (i < 1 || i > L.length + 1 || &L == NULL)
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
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    ElemType *p, *q;
    if (i < 1 || i > L.length)
        return ERROR;
    p = &(L.elem[i - 1]);
    e = p;
    q = &(L.elem[L.length - 1]);
    for (p++; p <= q; p++) {
        *(p - 1) = *p;
    }
    --L.length;

    return OK;
}

status ListTrabverse(SqList L) {
	if (isNull) {
		printf("The list is NULL.");
		return ERROR;	
	}
    int i;
    if (ListEmpty(L)) {
    	printf("The list is empty!\n");
        return ERROR;
    }
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
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
