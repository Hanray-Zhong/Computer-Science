#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//通过clock()函数计算程序运行时间
#include <time.h>


//一些定量
#define TURE 1
#define FALSE 0
#define CONFUSE -1

/*--------------用于SAT部分的数据结构-------------*/
//status用于做状态变量TRUE、FALSE等的类型
typedef int status;

//用于记录文字、子句和公式的结构体
//Literal用于表示文字类型
typedef struct Literal
{
    int pos;//表示文字状态 1代表正文字 0代表负文字
    int num;//表示文字是第几号变元
    struct Literal* next;//指向下一个文字
}Literal;

//Statement用于表示子句类型
typedef struct Statement
{
    int num_lit;//文字数
    struct Literal* elem;//指向子句中的第一个文字
    struct Statement* next;//指向下一个子句
}Statement;

//Formula用于表示公式
typedef struct Formula
{
    int sta;//标识公式是够可满足，0为不满足，1为满足，-1为待定
    int num_st;//表示子句数
    int num_v;//变元数
    struct Statement* root;//指向公式中的第一个子句
}Formula;

//通过单链表构建栈存储公式
typedef struct Stack_F
{
    int* V;//储存已确定信息的变元
    struct Formula* S;//表示栈中存储的公式
    struct Stack_F* next;//用于指向下一个节点
}Stack_F;

/*---------------用于数独格局转cnf范式的数据结构-------------*/
//通过邻接表储存数独格局中的每个空格，空格由可能的数字组成，每个可能的数字对应于一个变元号
//hole用于储存每一个空格
typedef struct hole
{
    int x;//标识行
    int y;//标识列
    int dig_num;//标识可能的数字数
    struct digtal* elem;//指向第一个可能的数字
}hole;

//digtal用于储存每个空格中可能出现的数字
typedef struct digtal
{
    int num;//数字
    int v_num;//数字所对应的变元编号
    struct digtal* next;
}digtal;

//一些函数的原函数
/*--------两大模块SAT&Sudoku-------*/
void SAT(long,long);
void Sudoku(void);
/*--------functions in SAT--------*/
void cnfParser(FILE*,Formula*);
status solver(Formula*,int*);
/*--------functions in solver--------*/
status judgeClause(Formula*);
void removeClause(Literal,Formula*);
void clearClause(Literal,Formula*);
status existEmptyClause(Formula*);
Formula* addClause(Literal,Formula*);
void destoryFormula(Formula*);
Literal choose_v(Formula*);
Formula* copy_S(Formula*);
int* copy_V(int*,int);
/*--------functions in Sudoku--------*/
void createFinalSud(int(*)[9]);
int createSudProblem(int(*)[9]);
int* transfSud(int(*)[9],Formula*,hole*);
void showSudResult(int *,hole*,int(*)[9]);
void cnfToFile(Formula*);
#endif // HEAD_H_INCLUDED
