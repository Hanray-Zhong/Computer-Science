#include "define.h"

struct node *mknode(int nodeKind, struct node *first, struct node *second, struct node *third, int pos)
{
    struct node *T = (struct node *)malloc(sizeof(struct node));
    T->nodeKind = nodeKind;
    T->ptr[0] = first;
    T->ptr[1] = second;
    T->ptr[2] = third;
    T->pos = pos;
    return T;
}

void display(struct node *T, int indent)
{
    if (T)
    {
        printf("%*c%d\n",indent,' ',T->offset );
        switch (T->nodeKind)
        {
        case EXT_DEF_LIST:
            printf("%*cExtDefList: \n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case EXT_DEF_VAR:
            printf("%*cExtDef_Var: \n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case EXT_DEF_FUNC:
            printf("%*cExtDef_Func£º\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            display(T->ptr[2], indent + 3);
            break;
        case EXT_VARDEC_LIST:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case TYPE:
            printf("%*c%s\n", indent, ' ', T->type_id);
            break;
        case ID:
            printf("%*c%s\n", indent, ' ', T->type_id);
            break;
        case ARRAY:
            printf("%*c%s[] %d\n", indent, ' ', T->type_id,T->size);
            break;
        case ARRAY_CALL:
            printf("%*c%s[]\n", indent, ' ', T->type_id);
            display(T->ptr[0], indent+3);
            break;
        case FUNC_DEC:
            printf("%*cFunc_name£º%s\n", indent, ' ', T->type_id);
            if (T->ptr[0])
            {
                printf("%*cFunc_params£º\n", indent, ' ');
                display(T->ptr[0], indent + 3);
            }
            break;
        case FUNC_PARAM_LIST:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case FUNC_PARAM_DEC:
            printf("%*c%s %s\n", indent, ' ', T->ptr[0]->type_id, T->ptr[1]->type_id);
            break;
        case COMP_STM:
            printf("%*cComSt: \n",indent,' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case COMPSTM_LIST:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case COMPSTM_EXP:
            display(T->ptr[0], indent);
            break;
        case RETURN:
            printf("%*cstmt_return£º\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case IF_THEN:
            printf("%*cstmt_IF£º\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case IF_THEN_ELSE:
            printf("%*cstmt_IF£º\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent+3); 
            display(T->ptr[2], indent+3); 
            break;
        case WHILE:
            printf("%*cstmt_while:\n", indent, ' ');
            display(T->ptr[0], indent + 3); 
            display(T->ptr[1], indent + 3); 
            break;
        case FOR:
            printf("%*cstmt_for:\n", indent, ' ');
            display(T->ptr[0], indent + 3); 
            display(T->ptr[1], indent + 3); 
            break;
        case FOR_CONDITION:
            printf("%*cstmt_for_condition:\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            display(T->ptr[2], indent + 3);
            break;
        case EXP_FOR3_LIST:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case DEF_LIST:
            printf("%*cdef_list: \n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case VAR_DEF:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case VARDEC_LIST:
            while (T)
            {
                display(T->ptr[0], indent);
                T = T->ptr[1];
            }
            break;
        case ASSIGNOP:
            printf("%*c=\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case ADD_ASSIGNOP:
            printf("%*c+=\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case MINUS_ASSIGNOP:
            printf("%*c-=\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case STAR_ASSIGNOP:
            printf("%*c*=\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case DIV_ASSIGNOP:
            printf("%*c/=\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case AND:
            printf("%*c&&\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case OR:
            printf("%*c||\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case RELOP:
            printf("%*c%s\n", indent, ' ',T->type_id);
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case PLUS:
            printf("%*c+\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case MINUS:
            printf("%*c-\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case STAR:
            printf("%*c*\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case DIV:
            printf("%*c/\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case UMINUS:
            printf("%*c-\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            break;
        case NOT:
            printf("%*c!\n", indent, ' ');
            display(T->ptr[0], indent+3); 
            break;
        case SELFADD:
            display(T->ptr[0], indent); 
            printf("%*c++\n", indent+3, ' ');
            display(T->ptr[1], indent+6); 
            break;
        case SELFDEC:
            display(T->ptr[0], indent); 
            printf("%*c--\n", indent+3, ' ');
            display(T->ptr[1], indent+6); 
            break;
        case FUNC_CALL:
            printf("%*cfunc_call:\n", indent, ' ');
            printf("%*cfunc_name£º%s\n", indent + 3, ' ', T->type_id);
            if (T->ptr[0])
            {
                printf("%*cfunc_args:\n", indent + 3 );
                display(T->ptr[0], indent + 6);
            }
            break;
        case INT:
            printf("%*c%d\n", indent, ' ', T->type_int);
            break;
        case FLOAT:
            printf("%*c%f\n", indent, ' ', T->type_float);
            break;
        case CHAR:
            printf("%*c'%c'\n", indent, ' ', T->type_char);
            break;
        case ARGS:
            while (T)
            {                 
                display(T->ptr[0],indent);
                T = T->ptr[1];
            }
            break;
       
        }
        

    }
}