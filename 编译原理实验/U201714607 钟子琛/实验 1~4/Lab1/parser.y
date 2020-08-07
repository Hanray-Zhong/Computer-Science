%error-verbose /*ָʾbison������ϸ�Ĵ�����Ϣ*/
%locations/*��¼�к�*/
%{
    #include "stdio.h"
    #include "math.h"
    #include "string.h"
    #include "define.h"
    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;
    void yyerror(const char* fmt, ...);
    void display(struct node *,int);
%}

/*Bison��Ĭ�Ͻ����е�����ֵ������Ϊint���ͣ�����ͨ�������YYSTYPE���ı�ֵ�����͡�
����ж��ֵ���ͣ�����Ҫͨ����Bison������ʹ��%union�оٳ����е����͡�*/
%union {
    int type_int;
    float type_float;
    char type_char;
    char type_id[32];
    struct node *ptr;
};
/*%type ������ս��������ֵ����*/
%type <ptr> program ExtDefList ExtDef Specifier ExtDecList FuncDec ArrayDec CompSt VarList VarDec ParamDec Stmt StmList DefList Def DecList Dec Exp Args StructDef StructCall

/*%token �����ս��������ֵ����*/
%token <type_int> INT           //ָ��INT������ֵ��type_int���ɴʷ������õ�����ֵ
%token <type_id> ID RELOP TYPE  //ָ��ID,RELOP������ֵ��type_id���ɴʷ������õ��ı�ʶ���ַ���
%token <type_float> FLOAT       //ָ��ID������ֵ��type_float
%token <type_char> CHAR

/*  ��bison�Ը��ļ�����ʱ��������-d��
    ���ɵ�exp.tab.h�и���Щ���ʽ��б��룬
    ����lex.l�а���parser.tab.hʹ����Щ����������*/
%token LP RP LC RC SEMI COMMA LB RB AP DQ   
%token PLUS MINUS STAR DIV DOT ASSIGNOP AND OR NOT IF ELSE WHILE RETURN ADD_ASSIGNOP MINUS_ASSIGNOP FOR STRUCT BREAK CONTINUE SELFADD SELFDEC STAR_ASSIGNOP DIV_ASSIGNOP

/*�������ȼ��ɵ͵������ζ���*/
%left ADD_ASSIGNOP MINUS_ASSIGNOP
%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right UMINUS NOT SELFADD SELFDEC

/*%nonassoc�ĺ�����û�н����,��һ����%prec���ʹ�ñ�ʾ�ò�����ͬ�������ȼ�*/
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%
/*��Լ���յ㣬��Լ��program����ʼ��ʾ�﷨��,�������*/
program: ExtDefList { display($1,0); }
;

/*ExtDefList���ⲿ�����б����������﷨��*/
/*�����﷨��Ϊ��*/
ExtDefList: {$$=NULL;}
    | ExtDef ExtDefList {$$=mknode(EXT_DEF_LIST,$1,$2,NULL,yylineno);} //ÿһ��EXTDEFLIST�Ľ�㣬���1��������Ӧһ���ⲿ������������
    ;

/*�ⲿ�����������ⲿ����������������*/
ExtDef: Specifier ExtDecList SEMI {$$=mknode(EXT_VAR_DEF,$1,$2,NULL,yylineno);} //�ý���Ӧһ���ⲿ��������
    | Specifier ArrayDec SEMI {$$=mknode(ARRAY_DEF,$1,$2,NULL,yylineno);}
    | Specifier FuncDec CompSt {$$=mknode(FUNC_DEF,$1,$2,$3,yylineno);} //�ý���Ӧһ���������壬����+��������+�������
    | error SEMI {$$=NULL; }
    | StructDef;
    ;
/*��ʾһ�����ͣ�ֻ��int��float��char*/
Specifier: TYPE {$$=mknode(TYPE,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);$$->type=(!strcmp($1,"int")?INT:(!strcmp($1,"float")?FLOAT:CHAR));}
    ;
/*���������б���һ������������ɣ��������֮���ö��Ÿ���*/
ExtDecList: VarDec {$$=$1;} /*ÿһ��EXT_DECLIST�Ľ�㣬���һ��������Ӧһ��������(ID���͵Ľ��),�ڶ���������Ӧʣ�µ��ⲿ������*/
    | VarDec COMMA ExtDecList {$$=mknode(EXT_DEC_LIST,$1,$3,NULL,yylineno);}
    ;
/*�������ƣ���һ��ID���*/
VarDec: ID {$$=mknode(ID,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);} //ID��㣬��ʶ�����Ŵ���Ž���type_id
    ;
/*������+��������*/
FuncDec: ID LP VarList RP {$$=mknode(FUNC_DEC,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//�����������$$->type_id
    |ID LP RP {$$=mknode(FUNC_DEC,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//�����������$$->type_id
    ;
ArrayDec: ID LB Exp RB {$$=mknode(ARRAY_DEC,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//�����������$$->type_id
    |ID LB RB {$$=mknode(ARRAY_DEC,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//�����������$$->type_id
    |ID LB Exp RB LB Exp RB{$$=mknode(ARRAY_DEC,$3,$6,NULL,yylineno);strcpy($$->type_id,$1);}
    |ID LB Exp RB LB Exp RB LB Exp RB{$$=mknode(ARRAY_DEC,$3,$6,$9,yylineno);strcpy($$->type_id,$1);}
    ;
/*���������б���һ�����������������ɣ��ö��Ÿ���*/
VarList: ParamDec {$$=mknode(PARAM_LIST,$1,NULL,NULL,yylineno);}
    | ParamDec COMMA VarList {$$=mknode(PARAM_LIST,$1,$3,NULL,yylineno);}
    ;
/*�������壬�̶���һ�����ͺ�һ���������*/
ParamDec: Specifier VarDec {$$=mknode(PARAM_DEC,$1,$2,NULL,yylineno);}
    | StructCall;
    ;
/*������䣬���ҷֱ��ô��������������м��ж����б������б�*/
CompSt: LC DefList StmList RC {$$=mknode(COMP_STM,$2,$3,NULL,yylineno);}
    ;
/*����б���0���������stmt���*/
StmList: {$$=NULL; }
    | Stmt StmList {$$=mknode(STM_LIST,$1,$2,NULL,yylineno);}
    ;
/*��䣬����Ϊ���ʽ��������䣬return��䣬if��䣬if-else��䣬while���*/
Stmt: Exp SEMI {$$=mknode(EXP_STMT,$1,NULL,NULL,yylineno);}
    | CompSt {$$=$1;} //���������ֱ����Ϊ����㣬���������µĽ��
    | RETURN Exp SEMI {$$=mknode(RETURN,$2,NULL,NULL,yylineno);}
    | IF LP Exp RP Stmt %prec LOWER_THEN_ELSE {$$=mknode(IF_THEN,$3,$5,NULL,yylineno);}
    | IF LP Exp RP Stmt ELSE Stmt {$$=mknode(IF_THEN_ELSE,$3,$5,$7,yylineno);}
    | WHILE LP Exp RP Stmt {$$=mknode(WHILE,$3,$5,NULL,yylineno);}
    | FOR LP Exp RP Stmt {$$=mknode(FOR,$3,$5,NULL,yylineno);}
    | BREAK SEMI{$$=mknode(BREAKST,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"break");}
    | CONTINUE SEMI{$$=mknode(CONTINUEST,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"continue");}
    ;
/*�����б���0����������������*/
DefList: {$$=NULL;}
    | Def DefList {$$=mknode(DEF_LIST,$1,$2,NULL,yylineno);}
    ;
/*����һ�����������䣬�ɷֺŸ���*/
Def: Specifier DecList SEMI {$$=mknode(VAR_DEF,$1,$2,NULL,yylineno);}
    | Specifier ArrayDec SEMI {$$=mknode(ARRAY_DEF,$1,$2,NULL,yylineno);}
    ;
/*����б���һ�����������ɣ��ɶ��Ÿ��������ն���һ�����ʽ*/
DecList: Dec {$$=mknode(DEC_LIST,$1,NULL,NULL,yylineno);}
    | Dec COMMA DecList {$$=mknode(DEC_LIST,$1,$3,NULL,yylineno);}
    ;
/*��䣬һ���������ƻ���һ����ֵ��䣨�������Ƶ���һ�����ʽ��*/
Dec: VarDec {$$=$1;}
    | VarDec ASSIGNOP Exp {$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}
    ;
/*���ʽ*/
Exp: Exp ASSIGNOP Exp{$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}//$$���type_id����δ�ã����ô�������
    | Exp AND Exp {$$=mknode(AND,$1,$3,NULL,yylineno);strcpy($$->type_id,"AND");}
    | Exp OR Exp {$$=mknode(OR,$1,$3,NULL,yylineno);strcpy($$->type_id,"OR");}
    | Exp RELOP Exp {$$=mknode(RELOP,$1,$3,NULL,yylineno);strcpy($$->type_id,$2);} //�ʷ�������ϵ�����������ֵ������$2��
    | Exp PLUS Exp {$$=mknode(PLUS,$1,$3,NULL,yylineno);strcpy($$->type_id,"PLUS");}
    | Exp MINUS Exp {$$=mknode(MINUS,$1,$3,NULL,yylineno);strcpy($$->type_id,"MINUS");}
    | Exp STAR Exp {$$=mknode(STAR,$1,$3,NULL,yylineno);strcpy($$->type_id,"STAR");}
    | Exp DIV Exp {$$=mknode(DIV,$1,$3,NULL,yylineno);strcpy($$->type_id,"DIV");}
    | Exp ADD_ASSIGNOP Exp  {$$=mknode(ADD_ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ADD_ASSIGNOP");}
    | Exp MINUS_ASSIGNOP Exp  {$$=mknode(MINUS_ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"MINUS_ASSIGNOP");}
    | LP Exp RP {$$=$2;}/*�����������ţ���ֱ�Ӻ������ţ�Exp��ֵ��Ϊ���������Exp*/
    | MINUS Exp %prec UMINUS {$$=mknode(UMINUS,$2,NULL,NULL,yylineno);strcpy($$->type_id,"UMINUS");}
    | NOT Exp {$$=mknode(NOT,$2,NULL,NULL,yylineno);strcpy($$->type_id,"NOT");}
    | SELFADD Exp  {$$=mknode(SELFADD_L,$2,NULL,NULL,yylineno);strcpy($$->type_id,"SELFADD");}
    | SELFDEC Exp  {$$=mknode(SELFDEC_L,$2,NULL,NULL,yylineno);strcpy($$->type_id,"SELFDEC");}
    | Exp SELFADD  {$$=mknode(SELFADD_R,$1,NULL,NULL,yylineno);strcpy($$->type_id,"SELFADD");}
    | Exp SELFDEC  {$$=mknode(SELFDEC_R,$1,NULL,NULL,yylineno);strcpy($$->type_id,"SELFDEC");}
    | ID LP Args RP {$$=mknode(FUNC_CALL,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}/*���������������Ų��֣�ֻ��Ҫ��������������ݴ��뼴��*/
    | ID LP RP {$$=mknode(FUNC_CALL,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}/*���������������Ų���û�в���*/
    | ID {$$=mknode(ID,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}
    | INT {$$=mknode(INT,NULL,NULL,NULL,yylineno);$$->type_int=$1;$$->type=INT;}
    | FLOAT {$$=mknode(FLOAT,NULL,NULL,NULL,yylineno);$$->type_float=$1;$$->type=FLOAT;}
    | CHAR {$$=mknode(CHAR,NULL,NULL,NULL,yylineno);$$->type_char=$1;$$->type=CHAR;}
    | ID LB Exp COMMA Exp RB{$$=mknode(ARRAY_DEC,$3,$5,NULL,yylineno),strcpy($$->type_id,$1)}
    | ID LB Exp RB LB Exp RB{$$=mknode(ARRAY_DEC,$3,$6,NULL,yylineno),strcpy($$->type_id,$1)}
    ;


/*�ö��Ÿ����Ĳ���*/
Args: Exp COMMA Args {$$=mknode(ARGS,$1,$3,NULL,yylineno);}
    | Exp {$$=mknode(ARGS,$1,NULL,NULL,yylineno);}
    ;

StructDef: STRUCT ID LC ExtDef RC VarDec SEMI {$$ = mknode(STRUCTdef,$6,NULL,NULL,yylineno);strcpy($$->type_id,$2);}
         | STRUCT ID LC ExtDef RC SEMI{$$ = mknode(STRUCTdef,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$2);};



StructCall: STRUCT ID VarDec SEMI{$$ = mknode(STRUCTcall,$3,NULL,NULL,yylineno);strcpy($$->type_id,$2);};



%%
#include<stdarg.h>

int vdef;
int level;
int vkind;
int forv;
int paranum;
int loopTag;
struct symbol* temp;
struct symboltable table;
struct symbol_scope_begin sco;
struct realArg{
    int kind;
    char name[33];
};
struct realArg REALARGS[10];
struct realArg* tempReal;
int realArgnum;
int paras;



int main(int argc, char *argv[])
{
    yyin=fopen(argv[1],"r");
    if (!yyin)
        return 0;
    yylineno=1;
    yyparse();
    return 0;
}

void yyerror(const char* fmt,...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}