#include "define.h"

/*--------���м���������й�------------------*/
//����һ��TAC����Ľ����ɵ�˫��ѭ����������ͷָ��
struct codenode *genIR(int op,struct opn opn1,struct opn opn2,struct opn result){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=op;
    h->opn1=opn1;
    h->opn2=opn2;
    h->result=result;
    h->next=h->prior=h;
    return h;
}

//����һ�������䣬����ͷָ��
struct codenode *genLabel(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=LABEL;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//����GOTO��䣬����ͷָ��
struct codenode *genGoto(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=GOTO;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//�ϲ�����м�����˫��ѭ��������β����
struct codenode *merge(int num,...){
    struct codenode *h1,*h2,*p,*t1,*t2;
    va_list ap;
    va_start(ap,num);
    h1=va_arg(ap,struct codenode *);
    while (--num>0) {
        h2=va_arg(ap,struct codenode *);
        if (h1==NULL) h1=h2;
        else if (h2){
            t1=h1->prior;
            t2=h2->prior;
            t1->next=h2;
            t2->next=h1;
            h1->prior=t2;
            h2->prior=t1;
            }
        }
    va_end(ap);
    return h1;
}
//�����ַ���
char *strcats(char *s1, char *s2)
{
    static char result[10];
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

//�����µı���������Ƕ�ײ��ʹ��
char *createAlias()
{
    static int no = 1;
    char s[10];
    itoa(no++, s, 10);
    return strcats("v", s);
}
char *createLabel() {
    static int no=1;
    char s[10];
    itoa(no++,s,10);
    return strcats("label",s);
}

//����һ����ʱ����������
char *createTemp()
{
    static int no = 1;
    char s[10];
    itoa(no++, s, 10);
    return strcats("tmp", s);
}


//����м����
void prnIR(struct codenode *head){
    char opnstr1[32],opnstr2[32],resultstr[32];
    struct codenode *h=head;
    do {
        if (h->opn1.kind==INT)
             sprintf(opnstr1,"#%d",h->opn1.const_int);
        if (h->opn1.kind==FLOAT)
             sprintf(opnstr1,"#%f",h->opn1.const_float);
        if (h->opn1.kind==ID)
             sprintf(opnstr1,"%s",h->opn1.id);
        if (h->opn2.kind==INT)
             sprintf(opnstr2,"#%d",h->opn2.const_int);
        if (h->opn2.kind==FLOAT)
             sprintf(opnstr2,"#%f",h->opn2.const_float);
        if (h->opn2.kind==ID)
             sprintf(opnstr2,"%s",h->opn2.id);
        sprintf(resultstr,"%s",h->result.id);
        switch (h->op) {
            case ASSIGNOP:  printf("  %s := %s\n",resultstr,opnstr1);
                            break;
            case PLUS:
            case MINUS:
            case STAR:
            case DIV: printf("  %s := %s %c %s\n",resultstr,opnstr1,h->op==PLUS?'+':h->op==MINUS?'-':h->op==STAR?'*':'\\',opnstr2);
                      break;
            case FUNCTION: printf("FUNC %s :\n",h->result.id);
                           break;
            case PARAM:    printf("  PARA %s\n",h->result.id);
                           break;
            case LABEL:    printf("LABEL %s :\n",h->result.id);
                           break;
            case GOTO:     printf("  GOTO %s\n",h->result.id);
                           break;
            case JLE:      printf("  IF %s <= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JLT:      printf("  IF %s < %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JGE:      printf("  IF %s >= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JGT:      printf("  IF %s > %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case EQ:       printf("  IF %s == %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case NEQ:      printf("  IF %s != %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case ARG:      printf("  ARG %s\n",h->result.id);
                           break;
            case CALL:     if (!strcmp(opnstr1,"write"))
                                printf("  CALL  %s\n", opnstr1);
                            else
                                printf("  %s := CALL %s\n",resultstr, opnstr1);
                           break;
            case RETURN:   if (h->result.kind)
                                printf("  RETURN %s\n",resultstr);
                           else
                                printf("  RETURN\n");
                           break;

        }
    h=h->next;
    } while (h!=head);
}
/*---------�м�������ɽ���-------------------*/

//�������ֻ�ռ�������Ϣ�������һ����ʾ
void semantic_error(int line, char *msg1, char *msg2)
{
    printf("��%d��,%s %s\n", line, msg1, msg2);
}

//�������ű�
int searchSymbolTable(char *name)
{
    int i;
    for (i = symbolTable.index - 1; i >= 0; i--)
        if (!strcmp(symbolTable.symbols[i].name, name))
            return i;
    return -1;
}

//����ű�
int fillSymbolTable(char *name, char *alias, int level, int type, char flag,int offset)
{
    //���ȸ���name����ű������ظ����� �ظ����巵��-1
    int i;

    /*���Ų��أ������ⲿ��������ǰ�к������壬
    ���β������ڷ��ű��У���ʱ���ⲿ������ǰ�������β������������*/
    for (i = symbolTable.index - 1; symbolTable.symbols[i].level == level || (level == 0 && i >= 0); i--)
    {
        if (level == 0 && symbolTable.symbols[i].level == 1)
            continue; //�ⲿ�������ββ��رȽ�����
        if (!strcmp(symbolTable.symbols[i].name, name))
            return -1;
    }
    //��д���ű�����
    strcpy(symbolTable.symbols[symbolTable.index].name, name);
    strcpy(symbolTable.symbols[symbolTable.index].alias, alias);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //���ص��Ƿ����ڷ��ű��е�λ����ţ��м��������ʱ�������ȡ�����ű���
}

//��д��ʱ���������ű�������ʱ�����ڷ��ű��е�λ��
int fill_Temp(char *name, int level, int type, char flag,int offset)
{
    strcpy(symbolTable.symbols[symbolTable.index].name, "");
    strcpy(symbolTable.symbols[symbolTable.index].alias, name);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //���ص�����ʱ�����ڷ��ű��е�λ�����
}

int LEV = 0;   //���
int func_size; //1�������Ļ��¼��С

//�����ⲿ���������б�
void ext_var_list(struct node *T)
{
    //rtn��¼�����ڷ��ű��λ�����
    int rtn, num = 1;
    switch (T->nodeKind)
    {
    case EXT_VARDEC_LIST:
        T->ptr[0]->type = T->type; //�������������´��ݱ������
        T->ptr[0]->offset=T->offset;          //�ⲿ������ƫ�������´���
        T->ptr[1]->type = T->type; //�������������´��ݱ������
        T->ptr[1]->offset=T->offset+T->width; //�ⲿ������ƫ�������´���
        T->ptr[1]->width=T->width;
        ext_var_list(T->ptr[0]);
        ext_var_list(T->ptr[1]);
        T->num = T->ptr[1]->num + 1;
        break;
    case ID:
        rtn = fillSymbolTable(T->type_id, createAlias(), LEV, T->type, 'V',T->offset); //���һ��������
        if (rtn == -1)
            semantic_error(T->pos, T->type_id, "�����ظ�����");
        else
        {
            T->place = rtn;
            T->num = 1;
        }
        break;
    case ARRAY:
        ///���鶨�� �Ĺ��ڷ��ű�Ĵ���
        rtn = fillSymbolTable(T->type_id, createAlias(), LEV, T->type, 'A',T->offset); //���һ��������
        if (rtn == -1)
            semantic_error(T->pos, T->type_id, "�������ظ�����");
        else if (T->size <= 0)
        {
            semantic_error(T->pos, T->type_id, "�����С����Ϊ��ֵ��0");
        }
        else
        {
            T->place = rtn;
            T->num = 1;
        }
        break;
    }
}

//�Ժ���ʵ�����βν��������飬T��ʵ���б�
int match_param(int i, struct node *T)
{
    int j, num = symbolTable.symbols[i].paramnum;
    int type1, type2;
    int pos = T->pos;
    //�βθ���Ϊ0
    if (num == 0 && T == NULL)
        return 1;
    for (j = 1; j <= num; j++)
    {
        if (!T)
        {
            semantic_error(pos, "", "�������ò���̫��");
            return 0;
        }
        type1 = symbolTable.symbols[i + j].type; //�β�����
        type2 = T->ptr[0]->type;                 //ʵ������
        if (type1 != type2)
        {
            semantic_error(pos, "", "�������Ͳ�ƥ��");
            return 0;
        }
        T = T->ptr[1];
    }
    if (T)
    { //num���β��Ѿ�ƥ���꣬����ʵ�α��ʽ
        semantic_error(pos, "", "�������ò���̫��");
        return 0;
    }
    return 1;
}

//�Գ����﷨�����ȸ�����,��display�Ŀ��ƽṹ�޸���ɷ��ű�����������
void semantic_Analysis(struct node *T)
{
    int rtn, num, width;
    struct node *T0;
    struct opn opn1, opn2, result;
    if (T)
    {
        switch (T->nodeKind)
        { 
        case EXT_DEF_LIST:
            if (!T->ptr[0])
                break;
            T->ptr[0]->offset=T->offset;
            semantic_Analysis(T->ptr[0]); //�����ⲿ�����б��еĵ�һ��
            T->code=T->ptr[0]->code;
            if (T->ptr[1])
            {
                T->ptr[1]->offset=T->ptr[0]->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]); //���ʸ��ⲿ�����б��е������ⲿ����
                T->code=merge(2,T->code,T->ptr[1]->code);
            }
            break;
        case EXT_DEF_VAR: //�����ⲿ˵��,����һ������(TYPE���)�е������͵��ڶ������ӵ�������
            T->type = T->ptr[1]->type = !strcmp(T->ptr[0]->type_id, "int") ? INT : (!strcmp(T->ptr[0]->type_id, "float") ? FLOAT : CHAR);
            T->ptr[1]->offset=T->offset;        //����ⲿ������ƫ�������´���
            T->ptr[1]->width=T->type==INT?4:8;  //��һ�������Ŀ�����´���
            ext_var_list(T->ptr[1]); //�����ⲿ����˵���еı�ʶ������
            T->width=(T->type==INT?4:8)* T->ptr[1]->num; //��������ⲿ����˵���Ŀ��
            T->code=NULL;             //����ٶ��ⲿ������֧�ֳ�ʼ��
            break;
        case EXT_DEF_FUNC:                                                                                                      //��д����������Ϣ�����ű�
            T->ptr[1]->type = !strcmp(T->ptr[0]->type_id, "int") ? INT : (!strcmp(T->ptr[0]->type_id, "float") ? FLOAT : CHAR); //��ȡ�������������͵����������������Ľ��
            T->width=0;     //�����Ŀ������Ϊ0��������ⲿ�����ĵ�ַ�������Ӱ��
            T->offset=DX;   //���þֲ������ڻ��¼�е�ƫ������ֵ
            semantic_Analysis(T->ptr[1]); //���������Ͳ�����㲿�֣����ﲻ�����üĴ������ݲ���
            T->offset+=T->ptr[1]->width;   //���βε�Ԫ����޸ĺ����ֲ���������ʼƫ����
            T->ptr[2]->offset=T->offset;
            strcpy(T->ptr[2]->Snext,createLabel());  //���������ִ�н������λ������
            T->ptr[2]->break_num = 0;
            semantic_Analysis(T->ptr[2]); //����������
            //������¼��С,����offset���Դ�ŵ��ǻ��¼��С������ƫ��
            symbolTable.symbols[T->ptr[1]->place].offset=T->offset+T->ptr[2]->width;
            T->code=merge(3,genLabel(T->ptr[2]->Snext),T->ptr[1]->code,T->ptr[2]->code);          //������Ĵ�����Ϊ�����Ĵ���
            break;
        case FUNC_DEC:                                                        //���ݷ������ͣ���������д���ű�,������ʱ�Ǻ�������
            rtn = fillSymbolTable(T->type_id, createAlias(), LEV, T->type, 'F',0); //���������������з��䵥Ԫ��ƫ����Ϊ0
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "�������ظ�����");
                break;
            }
            else
                T->place = rtn;
            result.kind = ID;
            strcpy(result.id, T->type_id);
            result.offset = rtn;
            T->code=genIR(FUNCTION,opn1,opn2,result);     //�����м���룺FUNCTION ������
            T->offset=DX;   //������ʽ�����ڻ��¼�е�ƫ������ֵ
            if (T->ptr[0])
            { //�ж��Ƿ��в���
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]); //�����������б�
                T->width=T->ptr[0]->width;
                symbolTable.symbols[rtn].paramnum = T->ptr[0]->num;
                T->code=merge(2,T->code,T->ptr[0]->code);  //���Ӻ������Ͳ�����������
            }
            else
            {
                symbolTable.symbols[rtn].paramnum = 0;
                T->width=0;
            }
            break;
        case FUNC_PARAM_LIST: //��������ʽ�����б�
            T->ptr[0]->offset=T->offset;
            semantic_Analysis(T->ptr[0]);
            if (T->ptr[1])
            {
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]);
                T->num = T->ptr[0]->num + T->ptr[1]->num; //ͳ�Ʋ�������
                T->width=T->ptr[0]->width+T->ptr[1]->width;  //�ۼӲ�����Ԫ���
                T->code=merge(2,T->ptr[0]->code,T->ptr[1]->code);  //���Ӳ�������
            }
            else
            {
                T->num = T->ptr[0]->num;
                T->width=T->ptr[0]->width;
                T->code=T->ptr[0]->code;
            }
            break;
        case FUNC_PARAM_DEC:
            rtn = fillSymbolTable(T->ptr[1]->type_id, createAlias(), 1, T->ptr[0]->type, 'P',T->offset);
            if (rtn == -1)
                semantic_error(T->ptr[1]->pos, T->ptr[1]->type_id, "�������ظ�����");
            else
                T->ptr[1]->place = rtn;
            T->num = 1; //������������ĳ�ʼֵ
            T->width=T->ptr[0]->type==INT?4:8;  //�������
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[rtn].alias);
            result.offset = T->offset;
            T->code=genIR(PARAM,opn1,opn2,result);     
            break;
        case COMP_STM:
            LEV++;
            //���ò�ż�1�����ұ���ò�ֲ������ڷ��ű��е���ʼλ����symbol_scope_TX
            /*printf("\n��\n");
            prn_symbol();    
            //prnIR(T->code);  
            printf("**��**\n");*/      
            symbol_scope_TX.TX[symbol_scope_TX.top++] = symbolTable.index;
            T->width=0;
            T->code=NULL;
            if (T->ptr[0])
            {
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]); //����ò�ľֲ�����DEF_LIST
                T->width+=T->ptr[0]->width;
                T->code=T->ptr[0]->code;
            }
            if (T->ptr[1])
            {
                T->ptr[1]->break_num = T->break_num;
                T->ptr[1]->offset=T->offset+T->width;
                strcpy(T->ptr[1]->Snext,T->Snext);  //S.next�������´���
                semantic_Analysis(T->ptr[1]); //�����������������
                T->width+=T->ptr[1]->width;
                T->code=merge(2,T->code,T->ptr[1]->code);
            }
            /*printf("\n��\n");
            prn_symbol();    
           // prnIR(T->code);  
            printf("**��**\n"); */                                                //c���˳�һ���������ǰ��ʾ�ķ��ű�
            LEV--;                                                         //��������䣬��ż�1
            symbolTable.index = symbol_scope_TX.TX[--symbol_scope_TX.top]; //ɾ�����������еķ���
            break;
        case DEF_LIST:
            T->code=NULL;
            if (T->ptr[0])
            {
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]); //����һ���ֲ���������
                T->code=T->ptr[0]->code;
                T->width=T->ptr[0]->width;
            }
            if (T->ptr[1])
            {
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]); //����ʣ�µľֲ���������
                T->code=merge(2,T->code,T->ptr[1]->code);
                T->width+=T->ptr[1]->width;
            }
            break;
        case VAR_DEF: //����һ���ֲ���������,����һ������(TYPE���)�е������͵��ڶ������ӵ�������
                      //������������ⲿ����EXT_VAR_DEF������һ�ִ�����
            T->code=NULL;
            T->ptr[1]->type = !strcmp(T->ptr[0]->type_id, "int") ? INT : (!strcmp(T->ptr[0]->type_id, "float") ? FLOAT : CHAR); //ȷ���������и���������
            T0 = T->ptr[1];                                                                                                     //T0Ϊ�������б�������ָ�룬��ID��ASSIGNOP�����ڵǼǵ����ű���Ϊ�ֲ�����
            num = 0;
            T0->offset=T->offset;
            T->width=0;
            if(T->ptr[1]->type==CHAR)
                width=1;
            else width=4;
           // width=T->ptr[1]->type==INT?4:FLOAT?4:CHAR?1:8;  //һ���������
            while (T0)
            { //��������VARDEC_LIST���
                num++;
                T0->ptr[0]->type = T0->type; //�����������´���
                if (T0->ptr[1])
                    T0->ptr[1]->type = T0->type; //�����������´���
                T0->ptr[0]->offset=T0->offset;
                if (T0->ptr[1]) T0->ptr[1]->offset=T0->offset+width;
                if (T0->ptr[0]->nodeKind == ID)
                {
                    rtn = fillSymbolTable(T0->ptr[0]->type_id, createAlias(), LEV, T0->ptr[0]->type, 'V',T->offset+T->width); //�˴�ƫ����δ���㣬��ʱΪ0

                    if (rtn == -1)
                        semantic_error(T0->ptr[0]->pos, T0->ptr[0]->type_id, "�����ظ�����");
                    else
                        T0->ptr[0]->place = rtn;
                    T->width+=width;
                }
                else if (T0->ptr[0]->nodeKind == ARRAY)
                { ////?????�������
                    rtn=fillSymbolTable(T0->ptr[0]->type_id,createAlias(),LEV,T0->ptr[0]->type,'V',T->offset+T->width);//�˴�ƫ����δ���㣬��ʱΪ0
                    if (rtn==-1)
                        semantic_error(T0->ptr[0]->pos,T0->ptr[0]->type_id, "�����ظ�����");
                    else T0->ptr[0]->place=rtn;
                    T->width+=width;
                    rtn = fillSymbolTable(T0->ptr[0]->type_id, createAlias(), LEV, T0->ptr[0]->type, 'A',T->offset+T->width); //���һ��������
                    if (rtn == -1)
                        semantic_error(T0->ptr[0]->pos, T0->ptr[0]->type_id, "�������ظ�����");
                    else if (T0->ptr[0]->size <= 0)
                    {
                        semantic_error(T0->ptr[0]->pos, T0->ptr[0]->type_id, "�����С����Ϊ��ֵ��0");
                    }
                    else
                    {
                        T0->ptr[0]->place = rtn;
                    }
                }
                else if (T0->ptr[0]->nodeKind == ASSIGNOP)
                {
                    rtn = fillSymbolTable(T0->ptr[0]->ptr[0]->type_id, createAlias(), LEV, T0->ptr[0]->type, 'V',T->offset+T->width); //�˴�ƫ����δ���㣬��ʱΪ0
                    if (rtn == -1)
                        semantic_error(T0->ptr[0]->ptr[0]->pos, T0->ptr[0]->ptr[0]->type_id, "�����ظ�����");
                    else if (T0->ptr[0]->ptr[0]->nodeKind == ARRAY && T0->ptr[0]->ptr[0]->size <= 0)
                    {
                        semantic_error(T0->ptr[0]->ptr[0]->pos, T0->ptr[0]->ptr[0]->type_id, "�����С����Ϊ��ֵ��0");
                    }
                    else
                    {
                        T0->ptr[0]->place = rtn;
                        T0->ptr[0]->ptr[1]->offset=T->offset+T->width+width;
                        Exp(T0->ptr[0]->ptr[1]);
                        Exp(T0->ptr[0]);
                        opn1.kind = ID;
                        strcpy(opn1.id, symbolTable.symbols[T0->ptr[0]->ptr[1]->place].alias);
                        result.kind = ID;
                        strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
                        T->code=merge(3,T->code,T0->ptr[0]->ptr[1]->code,genIR(ASSIGNOP,opn1,opn2,result));
                    }
                    T->width+=width+T0->ptr[0]->ptr[1]->width;
                }
                T0 = T0->ptr[1];
            }
            break;
        case COMPSTM_LIST:
            if (!T->ptr[0])
            {
                T->code=NULL;
                T->width=0;
                break;
            } //���������
            if (T->ptr[1]) //2������������ӣ������±����Ϊ��һ���������󵽴��λ��
                strcpy(T->ptr[0]->Snext,createLabel());
            else     //������н���һ����䣬S.next�������´���
                strcpy(T->ptr[0]->Snext,T->Snext);
            T->ptr[0]->offset=T->offset;
            T->ptr[0]->break_num = T->break_num;
            semantic_Analysis(T->ptr[0]);

            T->code=T->ptr[0]->code;
            T->width=T->ptr[0]->width;
            if (T->ptr[1])
            { //2�������������,S.next�������´���
                strcpy(T->ptr[1]->Snext,T->Snext);
                T->ptr[1]->offset=T->offset;  //˳��ṹ����Ԫ��ʽ
                T->ptr[1]->offset=T->offset+T->ptr[0]->width; //˳��ṹ˳����䵥Ԫ��ʽ
                T->ptr[1]->break_num = T->break_num;
                semantic_Analysis(T->ptr[1]);

                //�����е�1��Ϊ���ʽ��䣬������䣬�������ʱ����2��ǰ����Ҫ���
                if (T->ptr[0]->nodeKind==RETURN ||T->ptr[0]->nodeKind==EXP_STMT ||T->ptr[0]->nodeKind==COMP_STM)
                        T->code=merge(2,T->code,T->ptr[1]->code);
                    else
                        T->code=merge(3,T->code,genLabel(T->ptr[0]->Snext),T->ptr[1]->code);
                   if (T->ptr[1]->width>T->width) T->width=T->ptr[1]->width; //˳��ṹ����Ԫ��ʽ
                      T->width+=T->ptr[1]->width;//˳��ṹ˳����䵥Ԫ��ʽ
            }
            break;
        case COMPSTM_EXP:
            T->ptr[0]->offset=T->offset;
            T->ptr[0]->break_num = T->break_num;
            semantic_Analysis(T->ptr[0]);
            T->code=T->ptr[0]->code;
            T->width=T->ptr[0]->width;
            break;
        case IF_THEN:
            strcpy(T->ptr[0]->Etrue,createLabel());  //��������������ת��λ��
            strcpy(T->ptr[0]->Efalse,T->Snext);
            T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
            boolExp(T->ptr[0]);
            T->width=T->ptr[0]->width;
            strcpy(T->ptr[1]->Snext,T->Snext);
            T->ptr[1]->break_num = T->break_num;
            semantic_Analysis(T->ptr[1]); //if�Ӿ�
            if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
            T->code=merge(3,T->ptr[0]->code, genLabel(T->ptr[0]->Etrue),T->ptr[1]->code);
            break; //������䶼��û�д���offset��width����
        case IF_THEN_ELSE:
            strcpy(T->ptr[0]->Etrue,createLabel());  //��������������ת��λ��
            strcpy(T->ptr[0]->Efalse,createLabel());
            T->ptr[0]->offset=T->ptr[1]->offset=T->ptr[2]->offset=T->offset;
            boolExp(T->ptr[0]); //������Ҫ��������·���봦��
            T->width=T->ptr[0]->width;
            strcpy(T->ptr[1]->Snext,T->Snext);
            T->ptr[1]->break_num = T->break_num;
            semantic_Analysis(T->ptr[1]); //if�Ӿ�
            if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
            strcpy(T->ptr[2]->Snext,T->Snext);
            T->ptr[2]->break_num = T->break_num;
            semantic_Analysis(T->ptr[2]); //else�Ӿ�
            if (T->width<T->ptr[2]->width) T->width=T->ptr[2]->width;
            T->code=merge(6,T->ptr[0]->code,genLabel(T->ptr[0]->Etrue),T->ptr[1]->code,\
                              genGoto(T->Snext),genLabel(T->ptr[0]->Efalse),T->ptr[2]->code);
            break;
        case WHILE:
            strcpy(T->ptr[0]->Etrue,createLabel());  //�ӽ��̳����Եļ���
            strcpy(T->ptr[0]->Efalse,T->Snext);
            T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
            boolExp(T->ptr[0]); //ѭ��������Ҫ��������·���봦��
            T->width=T->ptr[0]->width;
            strcpy(T->ptr[1]->Snext,createLabel());
            T->ptr[1]->break_num = 1;
            semantic_Analysis(T->ptr[1]); //ѭ����
            if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
            T->code=merge(5,genLabel(T->ptr[1]->Snext),T->ptr[0]->code, \
                genLabel(T->ptr[0]->Etrue),T->ptr[1]->code,genGoto(T->ptr[1]->Snext));
            break;
        case FOR:
            semantic_Analysis(T->ptr[0]); //ѭ������
            T->ptr[1]->break_num = 1;
            semantic_Analysis(T->ptr[1]); //ѭ����
            break;
        case FOR_CONDITION:
            if (T->ptr[0])
            {
                Exp(T->ptr[0]);
            }
            if (T->ptr[1])
            {
                boolExp(T->ptr[1]);
            }
            if (T->ptr[2])
            {
                semantic_Analysis(T->ptr[2]);
            }
            break;
        case EXP_FOR3_LIST:
            Exp(T->ptr[0]);
            semantic_Analysis(T->ptr[1]);
            break;
        case RETURN:
            if (T->ptr[0])
            {
                T->ptr[0]->offset=T->offset;
                Exp(T->ptr[0]);
                num = symbolTable.index;
                do
                {
                    num--;
                } while (symbolTable.symbols[num].flag != 'F');
                if (T->ptr[0]->type != symbolTable.symbols[num].type)
                {
                    semantic_error(T->pos, "����ֵ���ʹ���", "");
                    T->width=0;T->code=NULL;
                    break;
                }
                T->width=T->ptr[0]->width;
                result.kind = ID;
                strcpy(result.id, symbolTable.symbols[T->ptr[0]->place].alias);
                result.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                T->code=merge(2,T->ptr[0]->code,genIR(RETURN,opn1,opn2,result));
            }
            else
            {
                semantic_error(T->pos, "����ֵ���Ͳ�����Ϊ��", "");
                T->width=0;
                result.kind=0;
                T->code=genIR(RETURN,opn1,opn2,result);
            }
            break;
        case ID:
        case ARRAY:
        case INT:
        case FLOAT:
        case CHAR:
        case ASSIGNOP:
        case AND:
        case OR:
        case RELOP:
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case NOT:
        case UMINUS:
        case SELFADD:
        case SELFDEC:
        case ADD_ASSIGNOP:
        case MINUS_ASSIGNOP:
        case STAR_ASSIGNOP:
        case DIV_ASSIGNOP:
        case FUNC_CALL:
        case ARRAY_CALL:
        case ARGS:
        case BREAK:
            Exp(T); //����������ʽ
            break;
        }
    }
}

void Exp(struct node *T)
{
    int rtn, num, width;
    struct node *T0;
    struct opn opn1, opn2, result;
    if (T)
    {
        switch (T->nodeKind)
        {
        case ID: //����ű���÷��ű��е�λ�ã�������type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "����δ����");
            else if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "�Ǻ����������Ͳ�ƥ��");
            else if (symbolTable.symbols[rtn].flag == 'A')
                semantic_error(T->pos, T->type_id, "���������,��ƥ��");
            else
            {
                T->place = rtn; //��㱣������ڷ��ű��е�λ��
                T->code=NULL;       //��ʶ������Ҫ����TAC
                T->type = symbolTable.symbols[rtn].type;
                T->offset=symbolTable.symbols[rtn].offset;
                T->width=0;   //δ��ʹ���µ�Ԫ
            }
            break;
        case ARRAY:
            //����ű���÷��ű��е�λ�ã�������type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "����δ����");
            else if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "�Ǻ���������ƥ��");
            else if (symbolTable.symbols[rtn].flag == 'V')
                semantic_error(T->pos, T->type_id, "�����������");
            else
            {
                T->place = rtn; //��㱣������ڷ��ű��е�λ��
                T->code=NULL;       //��ʶ������Ҫ����TAC
                T->type = symbolTable.symbols[rtn].type;
                T->offset=symbolTable.symbols[rtn].offset;
                T->width=0;   //δ��ʹ���µ�Ԫ
            }
            break;
        case INT:
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset); //Ϊ����������һ����ʱ����
            T->type = INT;
            opn1.kind = INT;
            opn1.const_int = T->type_int;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=genIR(ASSIGNOP,opn1,opn2,result);
            T->width=4;
            break;
        case FLOAT:
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset); //Ϊ���㳣������һ����ʱ����
            T->type = FLOAT;
            opn1.kind = FLOAT;
            opn1.const_float = T->type_float;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=genIR(ASSIGNOP,opn1,opn2,result);
            T->width=4;
            break;
        case CHAR:
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset); //Ϊ�ַ���������һ����ʱ����
            T->type = CHAR;
            opn1.kind = CHAR;
            opn1.const_char = T->type_char;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=genIR(ASSIGNOP,opn1,opn2,result);
            T->width=1;
            break;

        case ASSIGNOP:
            if (T->ptr[0]->nodeKind != ID && T->ptr[0]->nodeKind != ARRAY_CALL && T->ptr[0]->nodeKind != ARRAY)
            {
                semantic_error(T->pos, "", "��ֵ�����Ҫ��ֵ");
            }
            else
            {
                Exp(T->ptr[0]); //������ֵ�����н�Ϊ����
                T->ptr[1]->offset=T->offset;
                Exp(T->ptr[1]);
                if (T->ptr[0]->type != T->ptr[1]->type)
                {
                    semantic_error(T->pos, "", "��ֵ�����ߵı��ʽ���Ͳ�ƥ��");
                }
                T->type = T->ptr[0]->type;
                T->width=T->ptr[1]->width;
                T->code=merge(2,T->ptr[0]->code,T->ptr[1]->code);
                opn1.kind = ID;
                strcpy(opn1.id, symbolTable.symbols[T->ptr[1]->place].alias); //��ֵһ���Ǹ���������ʱ����
                opn1.offset=symbolTable.symbols[T->ptr[1]->place].offset;
                result.kind = ID;
                strcpy(result.id, symbolTable.symbols[T->ptr[0]->place].alias);
                result.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                T->code=merge(2,T->code,genIR(ASSIGNOP,opn1,opn2,result));
            }
            break;
        case AND: //���������ʽ��ʽ���㲼��ֵ��δд�� //��ʵ�о����ﵥָ����û���������
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == INT && T->ptr[1]->type==INT){
                T->type = bool;
            }else if(T->ptr[0]->type == FLOAT && T->ptr[1]->type==FLOAT){
                T->type = bool;
            }else if(T->ptr[0]->type == CHAR && T->ptr[1]->type==CHAR){
                T->type = bool;
            }else{
                semantic_error(T->pos,"", "�߼������&&�������Ͳ�ƥ��");
            }
            T->type = bool;
            break;
        case OR: //���������ʽ��ʽ���㲼��ֵ��δд��//��ʵ�о����ﵥָ����û���������
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == INT || T->ptr[1]->type==INT){
                T->type = bool;
            }else if(T->ptr[0]->type == FLOAT || T->ptr[1]->type==FLOAT){
                T->type = bool;
            }else if(T->ptr[0]->type == CHAR || T->ptr[1]->type == CHAR){
                T->type = bool;
            }else{
                semantic_error(T->pos,"", "�߼������or�������Ͳ�ƥ��");
                break;
            }
            T->type = bool;
            break;
        case RELOP: //���������ʽ��ʽ���㲼��ֵ��δд��//��ʵ�о�����Ĳ���û���������
            T->type = bool;
            T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            break;
        case PLUS: T->ptr[0]->offset=T->offset;
            Exp(T->ptr[0]);
            T->ptr[1]->offset=T->offset+T->ptr[0]->width;
            Exp(T->ptr[1]);
            //�ж�T->ptr[0]��T->ptr[1]�����Ƿ���ȷ�����ܸ�����������ɲ�ͬ��ʽ�Ĵ��룬��T��type��ֵ
            //������������Լ��㣬û�п��Ǵ��������
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
                break;
            }
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset+T->ptr[0]->width+T->ptr[1]->width); //,T->offset+T->ptr[0]->width+T->ptr[1]->width
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=merge(3,T->ptr[0]->code,T->ptr[1]->code,genIR(T->nodeKind,opn1,opn2,result));
            T->width=T->ptr[0]->width+T->ptr[1]->width+(T->type==INT?4:8);
            break;
        case MINUS: T->ptr[0]->offset=T->offset;
            Exp(T->ptr[0]);
            T->ptr[1]->offset=T->offset+T->ptr[0]->width;
            Exp(T->ptr[1]);
            //�ж�T->ptr[0]��T->ptr[1]�����Ƿ���ȷ�����ܸ�����������ɲ�ͬ��ʽ�Ĵ��룬��T��type��ֵ
            //������������Լ��㣬û�п��Ǵ��������
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
                break;
            }
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset+T->ptr[0]->width+T->ptr[1]->width); //,T->offset+T->ptr[0]->width+T->ptr[1]->width
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=merge(3,T->ptr[0]->code,T->ptr[1]->code,genIR(T->nodeKind,opn1,opn2,result));
            T->width=T->ptr[0]->width+T->ptr[1]->width+(T->type==INT?4:8);
            break;
        case STAR: T->ptr[0]->offset=T->offset;
            Exp(T->ptr[0]);
            T->ptr[1]->offset=T->offset+T->ptr[0]->width;
            Exp(T->ptr[1]);
            //�ж�T->ptr[0]��T->ptr[1]�����Ƿ���ȷ�����ܸ�����������ɲ�ͬ��ʽ�Ĵ��룬��T��type��ֵ
            //������������Լ��㣬û�п��Ǵ��������
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
                break;
            }
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset+T->ptr[0]->width+T->ptr[1]->width);
            opn1.kind = ID; //,T->offset+T->ptr[0]->width+T->ptr[1]->width
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=merge(3,T->ptr[0]->code,T->ptr[1]->code,genIR(T->nodeKind,opn1,opn2,result));
            T->width=T->ptr[0]->width+T->ptr[1]->width+(T->type==INT?4:8);
            break;
        case DIV:
            T->ptr[0]->offset=T->offset;
            Exp(T->ptr[0]);
            T->ptr[1]->offset=T->offset+T->ptr[0]->width;
            Exp(T->ptr[1]);
            //�ж�T->ptr[0]��T->ptr[1]�����Ƿ���ȷ�����ܸ�����������ɲ�ͬ��ʽ�Ĵ��룬��T��type��ֵ
            //������������Լ��㣬û�п��Ǵ��������
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
                break;
            }
            T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset+T->ptr[0]->width+T->ptr[1]->width); //,T->offset+T->ptr[0]->width+T->ptr[1]->width
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=merge(3,T->ptr[0]->code,T->ptr[1]->code,genIR(T->nodeKind,opn1,opn2,result));
            T->width=T->ptr[0]->width+T->ptr[1]->width+(T->type==INT?4:8);
            break;
        case NOT: //δд����

            T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
            Exp(T->ptr[0]);
            T->type = bool;
            break;
        case UMINUS: //δд����
            Exp(T->ptr[0]);
            T->type = T->ptr[0]->type;
            break;
        case SELFADD: //δд����
            if (T->ptr[0])
            {
               /* printf("%s\n",T->type_id);
                printf("%s\n",T->ptr[0]->type_id);
                int place=fill_Temp(createTemp(),LEV,T->type,'T',T->offset); //Ϊ����������һ����ʱ����
                //T->type=INT;
                opn1.kind=ID;

                opn2.kind=INT;
                opn2.const_int=1;
                result.kind=ID; 
                strcpy(result.id,symbolTable.symbols[T->ptr[0]->place].alias);
                result.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                T->code=genIR(PLUS,opn1,opn2,result);*/
                Exp(T->ptr[0]);
                T->type = T->ptr[0]->type;
            }
            else if (T->ptr[1])
            {
                //printf("1\n");
                Exp(T->ptr[1]);
                T->type = T->ptr[1]->type;
            }
            break;
        case SELFDEC: //δд����
            if (T->ptr[0])
            {
                Exp(T->ptr[0]);
                T->type = T->ptr[0]->type;
            }
            else if (T->ptr[1])
            {
                Exp(T->ptr[1]);
                T->type = T->ptr[1]->type;
            }
            break;
        case ADD_ASSIGNOP:
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
            }
            break;
        case MINUS_ASSIGNOP:
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
            }
            break;
        case STAR_ASSIGNOP:
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type != CHAR)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type != CHAR && T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
            }
            break;
        case DIV_ASSIGNOP:
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type != CHAR)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type != CHAR && T->ptr[1]->type == FLOAT)
            {
                T->type = FLOAT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+4;
            }
            else if (T->ptr[0]->type == INT && T->ptr[1]->type == INT)
            {
                T->type = INT;
                T->width=T->ptr[0]->width+T->ptr[1]->width+2;
            }
            else
            {
                semantic_error(T->pos, "", "����������������Ͳ�ƥ��");
            }
            break;
        case FUNC_CALL: //����T->type_id��������Ķ��壬���������������ʵ��̲ĵ�read��write��Ҫ��������һ��
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "����δ����");
                break;
            }
            else if (symbolTable.symbols[rtn].flag != 'F')
            {
                semantic_error(T->pos, T->type_id, "����һ������");
                break;
            }
            T->type = symbolTable.symbols[rtn].type;
            width=T->type==INT?4:8;   //��ź�������ֵ�ĵ����ֽ���
            if (T->ptr[0])
            {
                T->ptr[0]->offset=T->offset;
                Exp(T->ptr[0]); //��������ʵ�α��ʽ��ֵ��������
                T->width=T->ptr[0]->width+width; //�ۼ��ϼ���ʵ��ʹ����ʱ�����ĵ�Ԫ��
                T->code=T->ptr[0]->code;
            }
                else{
                    T->width=width;
                    T->code=NULL;
                }
                match_param(rtn, T->ptr[0]); //�������в�����ƥ��
                    //��������б���м����
                T0 = T->ptr[0];
                while (T0)
                {
                    result.kind = ID;
                    strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
                    result.offset=symbolTable.symbols[T0->ptr[0]->place].offset;
                    T->code=merge(2,T->code,genIR(ARG,opn1,opn2,result));
                    T0 = T0->ptr[1];
                }
                T->place = fill_Temp(createTemp(), LEV, T->type, 'T',T->offset+T->width-width); //,T->offset+T->width-width
                opn1.kind = ID;
                strcpy(opn1.id, T->type_id); //���溯����
                opn1.offset = rtn;           //����offset���Ա��溯���������,��Ŀ���������ʱ���ܻ�ȡ��Ӧ��Ϣ
                result.kind = ID;
                strcpy(result.id, symbolTable.symbols[T->place].alias);
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=merge(2,T->code,genIR(CALL,opn1,opn2,result)); //���ɺ��������м����
            /*}
            if (symbolTable.symbols[rtn].paramnum != 0)
            {
                semantic_error(T->pos, T->type_id, "�ú�����Ҫ������");
            }*/
            break;
        case ARRAY_CALL:
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "����δ����");
                break;
            }
            else if (symbolTable.symbols[rtn].flag == 'F')
            {
                semantic_error(T->pos, T->type_id, "�Ǻ����������Ͳ�ƥ��");
                break;
            }
            else if (symbolTable.symbols[rtn].flag == 'V')
            {
                semantic_error(T->pos, T->type_id, "�����������������ƥ��");
                break;
            }
            T->type = symbolTable.symbols[rtn].type;
            width=T->type==INT?4:8;   //��ź�������ֵ�ĵ����ֽ���

            T->ptr[0]->offset=T->offset;
            Exp(T->ptr[0]); //��������ʵ�α��ʽ��ֵ��������
            T0 = T->ptr[0];
            if (T0->type != INT)
            {
                semantic_error(T->pos, T0->type_id, "�����±������");
                break;
            }

            break;
        case BREAK:
            if (T->break_num != 1)
            {
                semantic_error(T->pos, T->type_id, "break������������ط�����");
            }
            break;
        case ARGS: //�˴��������ʵ�α��ʽ����ֵ�Ĵ������У�������ARG��ʵ��ϵ��
            T->ptr[0]->offset=T->offset;
            Exp(T->ptr[0]);
            T->width=T->ptr[0]->width;
            T->code=T->ptr[0]->code;
            if (T->ptr[1])
            {
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                Exp(T->ptr[1]);
                T->width+=T->ptr[1]->width;
                T->code=merge(2,T->code,T->ptr[1]->code);
            }
            break;
        }
    }
}

void boolExp(struct node *T)
{
    struct opn opn1, opn2, result;
    int op;
    int rtn;
    if (T)
    {
        switch (T->nodeKind)
        {
        case INT:
               if (T->type_int!=0)
                    T->code=genGoto(T->Etrue);
               else T->code=genGoto(T->Efalse);
               T->width=0;
            T->type = bool; //bool��ʾ�����ԣ�ֻҪ��int���������壬ֻ��0Ϊ�٣�����Ϊ��
            break;
        case FLOAT:
              if (T->type_float!=0.0)
                    T->code=genGoto(T->Etrue);
               else T->code=genGoto(T->Efalse);
               T->width=0;
            T->type = bool;
            break;
        case CHAR:
            T->type = bool;
            break;
        case ID: //����ű���÷��ű��е�λ�ã�������type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "����δ����");
            }
            else if (symbolTable.symbols[rtn].flag == 'F')
            {
                semantic_error(T->pos, T->type_id, "�Ǻ����������Ͳ�ƥ��");
            }
            else if (symbolTable.symbols[rtn].flag == 'A')
            {
                semantic_error(T->pos, T->type_id, "����������������Ͳ�ƥ��");
            }
            else
            {
                opn1.kind = ID;
                strcpy(opn1.id, symbolTable.symbols[rtn].alias);
                opn1.offset=symbolTable.symbols[rtn].offset;
                opn2.kind = INT;
                opn2.const_int = 0;
                result.kind=ID; 
                strcpy(result.id,T->Etrue);
                T->code=genIR(NEQ,opn1,opn2,result);
                T->code=merge(2,T->code,genGoto(T->Efalse));
            }
               T->width=0;
            T->type = bool;
            break;
        case ARRAY:
            //����ű���÷��ű��е�λ�ã�������type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "����δ����");
            else if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "�Ǻ���������ƥ��");
            else if (symbolTable.symbols[rtn].flag == 'V')
                semantic_error(T->pos, T->type_id, "�����������");
            else
            {
                T->place = rtn; //��㱣������ڷ��ű��е�λ��
                T->code=NULL;       //��ʶ������Ҫ����TAC
                T->type = symbolTable.symbols[rtn].type;
                T->offset=symbolTable.symbols[rtn].offset;
                T->width=0;   //δ��ʹ���µ�Ԫ
            }
            T->type = bool;
            break;

        case RELOP: //�����ϵ������ʽ,2�������������������ʽ����
            T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
            Exp(T->ptr[0]);
            T->width=T->ptr[0]->width;
            Exp(T->ptr[1]);
            if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind=ID; strcpy(result.id,T->Etrue);
            if (strcmp(T->type_id,"<")==0)
                    op=JLT;
            else if (strcmp(T->type_id,"<=")==0)
                    op=JLE;
            else if (strcmp(T->type_id,">")==0)
                    op=JGT;
            else if (strcmp(T->type_id,">=")==0)
                    op=JGE;
            else if (strcmp(T->type_id,"==")==0)
                    op=EQ;
            else if (strcmp(T->type_id,"!=")==0)
                    op=NEQ;
            T->code=genIR(op,opn1,opn2,result);
            T->code=merge(4,T->ptr[0]->code,T->ptr[1]->code,T->code,genGoto(T->Efalse));

            T->type = bool;
            break;
        case AND:
            boolExp(T->ptr[0]);
            T->width=T->ptr[0]->width;
            boolExp(T->ptr[1]);
            T->type = bool;
            break;
        case OR:
            if (T->nodeKind==AND) {
                strcpy(T->ptr[0]->Etrue,createLabel());
                strcpy(T->ptr[0]->Efalse,T->Efalse);
                }
            else {
                strcpy(T->ptr[0]->Etrue,T->Etrue);
                strcpy(T->ptr[0]->Efalse,createLabel());
                }
            strcpy(T->ptr[1]->Etrue,T->Etrue);
            strcpy(T->ptr[1]->Efalse,T->Efalse);
            T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
            boolExp(T->ptr[0]);
            T->width=T->ptr[0]->width;
            boolExp(T->ptr[1]);
            if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
            if (T->nodeKind==AND)
                T->code=merge(3,T->ptr[0]->code,genLabel(T->ptr[0]->Etrue),T->ptr[1]->code);
            else
                T->code=merge(3,T->ptr[0]->code,genLabel(T->ptr[0]->Efalse),T->ptr[1]->code);
            T->type = bool;
            break;
        case NOT:
            strcpy(T->ptr[0]->Etrue,T->Efalse);
            strcpy(T->ptr[0]->Efalse,T->Etrue);
            boolExp(T->ptr[0]);
            T->code=T->ptr[0]->code;
            T->type = bool;
            break;
        }
    }
}

void semantic_Analysis0(struct node *T)
{
    //д��read(),write(x)
    symbolTable.index = 0;
   // fillSymbolTable("read","",0,INT,'F',4);
    //symbolTable.symbols[0].paramnum = 0; //read���βθ���
   // fillSymbolTable("x","",1,INT,'P',12);
    //fillSymbolTable("write","",0,INT,'F',4);
    //symbolTable.symbols[2].paramnum = 1;
    symbol_scope_TX.TX[0] = 0; //�ⲿ�����ڷ��ű��е���ʼ���Ϊ0
    symbol_scope_TX.top = 1;
    T->offset = 0; //�ⲿ��������������ƫ����
    semantic_Analysis(T);
    prnIR(T->code);
    //objectCode(T->code);
}
