#include "define.h"

struct node* mknode(int kind, struct node* first, struct node* second, struct node* third, int pos) {
    struct node* T = (struct node*)malloc(sizeof(struct node));
    T->kind = kind;
    T->ptr[0] = first;  //若有第一棵子树，指向第一棵子树
    T->ptr[1] = second; //若有第二棵子树，指向第二棵子树
    T->ptr[2] = third;  //若有第三棵子树，指向第三棵子树
    T->pos = pos;       //记录行号
    return T;
}

void display(PEXP T, int indent)
{
    if (T) {
        switch (T->kind)
        {
        case EXT_DEF_LIST:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case EXT_VAR_DEF:
            printf("%*c%s\n", indent, ' ', "External variables define:");
            display(T->ptr[0], indent + 3);
            printf("%*c%s\n", indent + 3, ' ', "Variable name: ");
            display(T->ptr[1], indent + 3);
            break;
        case FUNC_DEF:
            printf("%*c%s\n", indent, ' ', "Function define: ");
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            display(T->ptr[2], indent + 3);
            break;
        case ARRAY_DEF:
            printf("%*c%s\n", indent, ' ', "Array define: ");
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case FUNC_DEC:
            printf("%*c%s%s\n", indent, ' ', "Function name: ", T->type_id);
            printf("%*c%s\n", indent, ' ', "Function args: ");
            display(T->ptr[0], indent + 3);
            break;
        case ARRAY_DEC:
            printf("%*c%s%s\n", indent, ' ', "Array name: ", T->type_id);
            printf("%*c%s\n", indent, ' ', "Size of array: ");
            display(T->ptr[0], indent + 3);
            if (T->ptr[1]) display(T->ptr[1], indent + 3);
            if (T->ptr[2]) display(T->ptr[2], indent + 3);
            break;
        case EXT_DEC_LIST:
            display(T->ptr[0], indent + 3);
            if (T->ptr[1]->ptr[0] == NULL)
                display(T->ptr[1], indent + 3);
            else
                display(T->ptr[1], indent);
            break;
        case PARAM_LIST:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case PARAM_DEC:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case VAR_DEF:
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case DEC_LIST:
            printf("%*c%s\n", indent, ' ', "Variable name: ");
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent);
            break;
        case DEF_LIST:
            printf("%*c%s\n", indent + 3, ' ', "LOCAL VAR_NAME: ");
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent);
            break;
        case COMP_STM:
            printf("%*c%s\n", indent + 3, ' ', "nested statement variable define: ");
            display(T->ptr[0], indent + 3);
            printf("%*c%s\n", indent + 3, ' ', "nested statement: ");
            display(T->ptr[1], indent + 3);
            break;
        case STM_LIST:
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent);
            break;
        case EXP_STMT:
            printf("%*c%s\n", indent, ' ', "experssion: ");
            display(T->ptr[0], indent + 3);
            break;
        case IF_THEN:
            printf("%*c%s\n", indent, ' ', "(if-else): ");
            printf("%*c%s\n", indent, ' ', "condition: ");
            display(T->ptr[0], indent + 3);
            printf("%*c%s\n", indent, ' ', "IF: ");
            display(T->ptr[1], indent + 3);
            break;
        case IF_THEN_ELSE:
            printf("%*c%s\n", indent, ' ', "if-else-if:");
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case WHILE:
            printf("%*c%s\n", indent, ' ', "(while): ");
            printf("%*c%s\n", indent + 3, ' ', "condition: ");
            display(T->ptr[0], indent + 3);
            printf("%*c%s\n", indent + 3, ' ', "while body: ");
            display(T->ptr[1], indent + 3);
            break;
        case FOR:
            printf("%*c%s\n", indent, ' ', "（for) : ");
            printf("%*c%s\n", indent + 3, ' ', "condition: ");
            display(T->ptr[0], indent + 3);
            printf("%*c%s\n", indent + 3, ' ', "for body: ");
            display(T->ptr[1], indent + 3);
            break;
        case FUNC_CALL:
            printf("%*c%s\n", indent, ' ', "function call: ");
            printf("%*c%s%s\n", indent + 3, ' ', "function name: ", T->type_id);
            printf("%*c%s\n", indent + 3, ' ', "actuall arg: ");
            display(T->ptr[0], indent + 3);
            break;
        case ARGS:
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case ID:
            printf("%*cID: %s\n", indent, ' ', T->type_id);//控制新的一行输出的空格数，indent代替%*c中*
            break;
        case INT:
            printf("%*cINT: %d\n", indent, ' ', T->type_int);
            break;
        case FLOAT:
            printf("%*cFLOAT: %f\n", indent, ' ', T->type_float);
            break;
        case CHAR:
            printf("%*cCHAR: %c\n", indent, ' ', T->type_char);
        case ARRAY:
            printf("%*cArray name: %s\n", indent, ' ', T->type_id);
            break;
        case TYPE:
            if (T->type == INT)
                printf("%*c%s\n", indent, ' ', "TYPE: int");
            else if (T->type == FLOAT)
                printf("%*c%s\n", indent, ' ', "TYPE: float");
            else if (T->type == CHAR)
                printf("%*c%s\n", indent, ' ', "TYPE: char");
            else if (T->type == ARRAY)
                printf("%*c%s\n", indent, ' ', "TYPE: char array");
            break;
        case STRUCTdef:
            printf("%*cStruct name: %c\n", indent, ' ', T->type_id);
            if (T->ptr[0]) display(T->ptr[0], indent + 3);
            break;
        case STRUCTcall:
            printf("%*cStruct type name: %c\n", indent, ' ', T->type_id);
            if (T->ptr[0]) display(T->ptr[0], indent + 3);
            break;

        case ASSIGNOP:
        case OR:
        case SELFADD_L:
        case SELFDEC_L:
        case SELFADD_R:
        case SELFDEC_R:
        case AND:
        case RELOP:
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case ADD_ASSIGNOP:
        case MINUS_ASSIGNOP:
            printf("%*c%s\n", indent, ' ', T->type_id);
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            if (T->ptr[2]) display(T->ptr[2], indent + 3);
            break;
        case RETURN:
            printf("%*c%s\n", indent, ' ', "Return Statements: ");
            display(T->ptr[0], indent + 3);
            break;
        }
    }
}