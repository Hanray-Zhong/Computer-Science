%error-verbose /*指示bison生成详细的错误消息*/
%locations/*记录行号*/
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

/*Bison中默认将所有的语义值都定义为int类型，可以通过定义宏YYSTYPE来改变值的类型。
如果有多个值类型，则需要通过在Bison声明中使用%union列举出所有的类型。*/
%union {
    int type_int;
    float type_float;
    char type_char;
    char type_id[32];
    struct node *ptr;
};
/*%type 定义非终结符的语义值类型*/
%type <ptr> program ExtDefList ExtDef Specifier ExtDecList FuncDec ArrayDec CompSt VarList VarDec ParamDec Stmt StmList DefList Def DecList Dec Exp Args StructDef StructCall

/*%token 定义终结符的语义值类型*/
%token <type_int> INT           //指定INT的语义值是type_int，由词法分析得到的数值
%token <type_id> ID RELOP TYPE  //指定ID,RELOP的语义值是type_id，由词法分析得到的标识符字符串
%token <type_float> FLOAT       //指定ID的语义值是type_float
%token <type_char> CHAR

/*  用bison对该文件编译时，带参数-d，
    生成的exp.tab.h中给这些单词进行编码，
    可在lex.l中包含parser.tab.h使用这些单词种类码*/
%token LP RP LC RC SEMI COMMA LB RB AP DQ   
%token PLUS MINUS STAR DIV DOT ASSIGNOP AND OR NOT IF ELSE WHILE RETURN ADD_ASSIGNOP MINUS_ASSIGNOP FOR STRUCT BREAK CONTINUE SELFADD SELFDEC STAR_ASSIGNOP DIV_ASSIGNOP

/*根据优先级由低到高依次定义*/
%left ADD_ASSIGNOP MINUS_ASSIGNOP
%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right UMINUS NOT SELFADD SELFDEC

/*%nonassoc的含义是没有结合性,它一般与%prec结合使用表示该操作有同样的优先级*/
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%
/*归约的终点，归约到program，开始显示语法树,语义分析*/
program: ExtDefList { display($1,0); }
;

/*ExtDefList：外部定义列表，即是整个语法树*/
/*整个语法树为空*/
ExtDefList: {$$=NULL;}
    | ExtDef ExtDefList {$$=mknode(EXT_DEF_LIST,$1,$2,NULL,yylineno);} //每一个EXTDEFLIST的结点，其第1棵子树对应一个外部变量声明或函数
    ;

/*外部声明，声明外部变量或者声明函数*/
ExtDef: Specifier ExtDecList SEMI {$$=mknode(EXT_VAR_DEF,$1,$2,NULL,yylineno);} //该结点对应一个外部变量声明
    | Specifier ArrayDec SEMI {$$=mknode(ARRAY_DEF,$1,$2,NULL,yylineno);}
    | Specifier FuncDec CompSt {$$=mknode(FUNC_DEF,$1,$2,$3,yylineno);} //该结点对应一个函数定义，类型+函数声明+复合语句
    | error SEMI {$$=NULL; }
    | StructDef;
    ;
/*表示一个类型，只有int、float和char*/
Specifier: TYPE {$$=mknode(TYPE,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);$$->type=(!strcmp($1,"int")?INT:(!strcmp($1,"float")?FLOAT:CHAR));}
    ;
/*变量名称列表，由一个或多个变量组成，多个变量之间用逗号隔开*/
ExtDecList: VarDec {$$=$1;} /*每一个EXT_DECLIST的结点，其第一棵子树对应一个变量名(ID类型的结点),第二棵子树对应剩下的外部变量名*/
    | VarDec COMMA ExtDecList {$$=mknode(EXT_DEC_LIST,$1,$3,NULL,yylineno);}
    ;
/*变量名称，由一个ID组成*/
VarDec: ID {$$=mknode(ID,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);} //ID结点，标识符符号串存放结点的type_id
    ;
/*函数名+参数定义*/
FuncDec: ID LP VarList RP {$$=mknode(FUNC_DEC,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id
    |ID LP RP {$$=mknode(FUNC_DEC,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id
    ;
ArrayDec: ID LB Exp RB {$$=mknode(ARRAY_DEC,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id
    |ID LB RB {$$=mknode(ARRAY_DEC,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id
    |ID LB Exp RB LB Exp RB{$$=mknode(ARRAY_DEC,$3,$6,NULL,yylineno);strcpy($$->type_id,$1);}
    |ID LB Exp RB LB Exp RB LB Exp RB{$$=mknode(ARRAY_DEC,$3,$6,$9,yylineno);strcpy($$->type_id,$1);}
    ;
/*参数定义列表，有一个到多个参数定义组成，用逗号隔开*/
VarList: ParamDec {$$=mknode(PARAM_LIST,$1,NULL,NULL,yylineno);}
    | ParamDec COMMA VarList {$$=mknode(PARAM_LIST,$1,$3,NULL,yylineno);}
    ;
/*参数定义，固定有一个类型和一个变量组成*/
ParamDec: Specifier VarDec {$$=mknode(PARAM_DEC,$1,$2,NULL,yylineno);}
    | StructCall;
    ;
/*复合语句，左右分别用大括号括起来，中间有定义列表和语句列表*/
CompSt: LC DefList StmList RC {$$=mknode(COMP_STM,$2,$3,NULL,yylineno);}
    ;
/*语句列表，由0个或多个语句stmt组成*/
StmList: {$$=NULL; }
    | Stmt StmList {$$=mknode(STM_LIST,$1,$2,NULL,yylineno);}
    ;
/*语句，可能为表达式，复合语句，return语句，if语句，if-else语句，while语句*/
Stmt: Exp SEMI {$$=mknode(EXP_STMT,$1,NULL,NULL,yylineno);}
    | CompSt {$$=$1;} //复合语句结点直接最为语句结点，不再生成新的结点
    | RETURN Exp SEMI {$$=mknode(RETURN,$2,NULL,NULL,yylineno);}
    | IF LP Exp RP Stmt %prec LOWER_THEN_ELSE {$$=mknode(IF_THEN,$3,$5,NULL,yylineno);}
    | IF LP Exp RP Stmt ELSE Stmt {$$=mknode(IF_THEN_ELSE,$3,$5,$7,yylineno);}
    | WHILE LP Exp RP Stmt {$$=mknode(WHILE,$3,$5,NULL,yylineno);}
    | FOR LP Exp RP Stmt {$$=mknode(FOR,$3,$5,NULL,yylineno);}
    | BREAK SEMI{$$=mknode(BREAKST,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"break");}
    | CONTINUE SEMI{$$=mknode(CONTINUEST,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"continue");}
    ;
/*定义列表，由0个或多个定义语句组成*/
DefList: {$$=NULL;}
    | Def DefList {$$=mknode(DEF_LIST,$1,$2,NULL,yylineno);}
    ;
/*定义一个或多个语句语句，由分号隔开*/
Def: Specifier DecList SEMI {$$=mknode(VAR_DEF,$1,$2,NULL,yylineno);}
    | Specifier ArrayDec SEMI {$$=mknode(ARRAY_DEF,$1,$2,NULL,yylineno);}
    ;
/*语句列表，由一个或多个语句组成，由逗号隔开，最终都成一个表达式*/
DecList: Dec {$$=mknode(DEC_LIST,$1,NULL,NULL,yylineno);}
    | Dec COMMA DecList {$$=mknode(DEC_LIST,$1,$3,NULL,yylineno);}
    ;
/*语句，一个变量名称或者一个赋值语句（变量名称等于一个表达式）*/
Dec: VarDec {$$=$1;}
    | VarDec ASSIGNOP Exp {$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}
    ;
/*表达式*/
Exp: Exp ASSIGNOP Exp{$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}//$$结点type_id空置未用，正好存放运算符
    | Exp AND Exp {$$=mknode(AND,$1,$3,NULL,yylineno);strcpy($$->type_id,"AND");}
    | Exp OR Exp {$$=mknode(OR,$1,$3,NULL,yylineno);strcpy($$->type_id,"OR");}
    | Exp RELOP Exp {$$=mknode(RELOP,$1,$3,NULL,yylineno);strcpy($$->type_id,$2);} //词法分析关系运算符号自身值保存在$2中
    | Exp PLUS Exp {$$=mknode(PLUS,$1,$3,NULL,yylineno);strcpy($$->type_id,"PLUS");}
    | Exp MINUS Exp {$$=mknode(MINUS,$1,$3,NULL,yylineno);strcpy($$->type_id,"MINUS");}
    | Exp STAR Exp {$$=mknode(STAR,$1,$3,NULL,yylineno);strcpy($$->type_id,"STAR");}
    | Exp DIV Exp {$$=mknode(DIV,$1,$3,NULL,yylineno);strcpy($$->type_id,"DIV");}
    | Exp ADD_ASSIGNOP Exp  {$$=mknode(ADD_ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ADD_ASSIGNOP");}
    | Exp MINUS_ASSIGNOP Exp  {$$=mknode(MINUS_ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"MINUS_ASSIGNOP");}
    | LP Exp RP {$$=$2;}/*遇到左右括号，可直接忽略括号，Exp的值就为括号里面的Exp*/
    | MINUS Exp %prec UMINUS {$$=mknode(UMINUS,$2,NULL,NULL,yylineno);strcpy($$->type_id,"UMINUS");}
    | NOT Exp {$$=mknode(NOT,$2,NULL,NULL,yylineno);strcpy($$->type_id,"NOT");}
    | SELFADD Exp  {$$=mknode(SELFADD_L,$2,NULL,NULL,yylineno);strcpy($$->type_id,"SELFADD");}
    | SELFDEC Exp  {$$=mknode(SELFDEC_L,$2,NULL,NULL,yylineno);strcpy($$->type_id,"SELFDEC");}
    | Exp SELFADD  {$$=mknode(SELFADD_R,$1,NULL,NULL,yylineno);strcpy($$->type_id,"SELFADD");}
    | Exp SELFDEC  {$$=mknode(SELFDEC_R,$1,NULL,NULL,yylineno);strcpy($$->type_id,"SELFDEC");}
    | ID LP Args RP {$$=mknode(FUNC_CALL,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}/*函数定义后面的括号部分，只需要把括号里面的内容传入即可*/
    | ID LP RP {$$=mknode(FUNC_CALL,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}/*函数定义后面的括号部分没有参数*/
    | ID {$$=mknode(ID,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}
    | INT {$$=mknode(INT,NULL,NULL,NULL,yylineno);$$->type_int=$1;$$->type=INT;}
    | FLOAT {$$=mknode(FLOAT,NULL,NULL,NULL,yylineno);$$->type_float=$1;$$->type=FLOAT;}
    | CHAR {$$=mknode(CHAR,NULL,NULL,NULL,yylineno);$$->type_char=$1;$$->type=CHAR;}
    | ID LB Exp COMMA Exp RB{$$=mknode(ARRAY_DEC,$3,$5,NULL,yylineno),strcpy($$->type_id,$1)}
    | ID LB Exp RB LB Exp RB{$$=mknode(ARRAY_DEC,$3,$6,NULL,yylineno),strcpy($$->type_id,$1)}
    ;


/*用逗号隔开的参数*/
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