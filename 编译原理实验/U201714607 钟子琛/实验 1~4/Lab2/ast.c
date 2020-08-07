#include "define.h"

struct node *mknode(int nodeKind, struct node *first, struct node *second, struct node *third, int pos)
{
    struct node *T = (struct node *)malloc(sizeof(struct node));
    T->nodeKind = nodeKind;
    if(first)first->parent=T;
    if(second)second->parent=T;
    if(third)third->parent=T;
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
        switch (T->nodeKind)
        {
        case EXT_DEF_LIST:
            strcpy(T->scope,"Global");
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case EXT_DEF_VAR:
            strcpy(T->scope,T->parent->scope);

            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case EXT_DEF_FUNC:
            
            strcpy(T->scope,T->ptr[1]->type_id);
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            display(T->ptr[2], indent + 3);
            break;
        case EXT_VARDEC_LIST:
            strcpy(T->scope,"Global");
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case TYPE:
            strcpy(T->scope,T->parent->scope);
            break;
        case ID:
            strcpy(T->scope,T->parent->scope);
            break;
        case ARRAY:
            strcpy(T->scope,T->parent->scope);
            break;
        case ARRAY_CALL:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent+3);
            break;
        case FUNC_DEC:
            strcpy(T->scope,T->type_id);
            if (T->ptr[0])
            {
                display(T->ptr[0], indent + 3);
            }
            break;
        case FUNC_PARAM_LIST:
            strcpy(T->scope,"Para of ");
            strcat(T->scope,T->parent->scope);
            display(T->ptr[0], indent); 
            display(T->ptr[1], indent);
            break;
        case FUNC_PARAM_DEC:
            strcpy(T->scope,T->parent->scope);
           
            break;
        case COMP_STM:
            strcpy(T->scope,T->parent->scope);
           
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case COMPSTM_LIST:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case COMPSTM_EXP:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent);
            break;
        case RETURN:
            strcpy(T->scope,T->parent->scope);
           
            display(T->ptr[0], indent + 3);
            break;
        case IF_THEN:
            strcpy(T->scope,"IF of ");
            strcat(T->scope,T->parent->scope);
          
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case IF_THEN_ELSE:
            strcpy(T->scope,"IF_ELSE of ");
            strcat(T->scope,T->parent->scope);
         
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent+3);
            display(T->ptr[2], indent+3);
            break;
        case WHILE:
            strcpy(T->scope,"WHILE of ");
            strcat(T->scope,T->parent->scope);
           
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case FOR:
            strcpy(T->scope,"FOR of ");
            strcat(T->scope,T->parent->scope);
          
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case FOR_CONDITION:
            strcpy(T->scope,T->parent->scope);
         
            display(T->ptr[0], indent + 3); 
            display(T->ptr[1], indent + 3); 
            display(T->ptr[2], indent + 3); 
            break;
        case EXP_FOR3_LIST:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case DEF_LIST:
            strcpy(T->scope,T->parent->scope);
        
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case VAR_DEF:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case VARDEC_LIST:
            strcpy(T->scope,T->parent->scope);
            while (T)
            {
                strcpy(T->scope,T->parent->scope);
                display(T->ptr[0], indent);
                T = T->ptr[1];
            }
            break;
        case ASSIGNOP:
            strcpy(T->scope,T->parent->scope);
           
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case ADD_ASSIGNOP:
            strcpy(T->scope,T->parent->scope);
       
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case MINUS_ASSIGNOP:
            strcpy(T->scope,T->parent->scope);
       
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case STAR_ASSIGNOP:
            strcpy(T->scope,T->parent->scope);
        
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case DIV_ASSIGNOP:
            strcpy(T->scope,T->parent->scope);
          
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case AND:
            strcpy(T->scope,T->parent->scope);
          
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case OR:
            strcpy(T->scope,T->parent->scope);
         
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case RELOP:
            strcpy(T->scope,T->parent->scope);
    
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case PLUS:
            strcpy(T->scope,T->parent->scope);
    
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case MINUS:
            strcpy(T->scope,T->parent->scope);
      
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case STAR:
            strcpy(T->scope,T->parent->scope);
       
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case DIV:
            strcpy(T->scope,T->parent->scope);
       
            display(T->ptr[0], indent+3); 
            display(T->ptr[1], indent+3);
            break;
        case UMINUS:
            strcpy(T->scope,T->parent->scope);
    
            display(T->ptr[0], indent+3); 
            break;
        case NOT:
            strcpy(T->scope,T->parent->scope);
     
            display(T->ptr[0], indent+3); 
            break;
        case SELFADD:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent); 
    
            display(T->ptr[1], indent+6); 
            break;
        case SELFDEC:
            strcpy(T->scope,T->parent->scope);
            display(T->ptr[0], indent); 
      
            display(T->ptr[1], indent+6); 
            break;
        case FUNC_CALL:
            strcpy(T->scope,T->parent->scope);
         
            if (T->ptr[0])
            {
   
                display(T->ptr[0], indent + 6);
            }
            break;
        case INT:
            strcpy(T->scope,T->parent->scope);
        
            break;
        case FLOAT:
            strcpy(T->scope,T->parent->scope);
       
            break;
        case CHAR:
            strcpy(T->scope,T->parent->scope);
    
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