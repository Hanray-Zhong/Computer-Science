#pragma once
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


//一些定量
#define TURE 1
#define FALSE 0
#define CONFUSE -1

//status用于做状态变量TRUE、FALSE等的类型
typedef int status;

/*
int pos; 表示文字状态 1代表正文字 0代表负文字
int num; 表示文字是第几号变元
struct Literal* next; 指向下一个文字
*/
typedef struct Literal
{
	int pos;//表示文字状态 1代表正文字 0代表负文字
	int num;//表示文字是第几号变元
	struct Literal* next;//指向下一个文字
}Literal;
/*
int num_lit;			文字数
struct Literal* elem;	指向子句中的第一个文字
struct Statement* next;	指向下一个子句
*/
typedef struct Statement
{
	int num_lit;//文字数
	struct Literal* elem;//指向子句中的第一个文字
	struct Statement* next;//指向下一个子句
}Statement;
/*
int sta; 标识公式是够可满足，0为不满足，1为满足，-1为待定
int num_st; 表示子句数
int num_v; 变元数
struct Statement* root 指向公式中的第一个子句
*/
typedef struct Formula
{
	int sta;//标识公式是够可满足，0为不满足，1为满足，-1为待定
	int num_st;//表示子句数
	int num_v;//变元数
	struct Statement* root;//指向公式中的第一个子句
}Formula;
/*
int* V; 储存已确定信息的变元
struct Formula* S; 表示栈中存储的公式
struct Stack_F* next; 用于指向下一个节点
*/
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


//原函数
void SAT(long, long);
void CNF_Reader(FILE*, Formula*);
status Solver(Formula*, int*);
bool Check(int* Varies_res, Formula* formula);
Statement* SearchStatement(int k, Formula* formula);
Literal* SearchLiteral(int k, Statement* statement);

status HaveUnitClause(Formula*);
void RemoveClause(Literal, Formula*);
void ClearClause(Literal, Formula*);
status HaveEmptyClause(Formula*);
Formula* AddClause(Literal, Formula*);
void DestoryFormula(Formula*);
Literal Choose_L(Formula*);
Formula* Copy_F(Formula*);
int* Copy_V(int*, int);

void Sudoku(long time_start, long time_end);
void CreateFinalSud(int(*)[9]);
int CreateSudoku(int(*)[9]);
int* TransfSud(int(*)[9], Formula*, hole*);
void ShowSudResult(int *, hole*, int(*)[9]);
void CnfToFile(Formula*);



#endif // HEAD_H_INCLUDED
