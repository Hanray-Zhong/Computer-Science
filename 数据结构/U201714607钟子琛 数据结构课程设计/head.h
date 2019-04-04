#pragma once
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


//һЩ����
#define TURE 1
#define FALSE 0
#define CONFUSE -1

//status������״̬����TRUE��FALSE�ȵ�����
typedef int status;

/*
int pos; ��ʾ����״̬ 1���������� 0��������
int num; ��ʾ�����ǵڼ��ű�Ԫ
struct Literal* next; ָ����һ������
*/
typedef struct Literal
{
	int pos;//��ʾ����״̬ 1���������� 0��������
	int num;//��ʾ�����ǵڼ��ű�Ԫ
	struct Literal* next;//ָ����һ������
}Literal;
/*
int num_lit;			������
struct Literal* elem;	ָ���Ӿ��еĵ�һ������
struct Statement* next;	ָ����һ���Ӿ�
*/
typedef struct Statement
{
	int num_lit;//������
	struct Literal* elem;//ָ���Ӿ��еĵ�һ������
	struct Statement* next;//ָ����һ���Ӿ�
}Statement;
/*
int sta; ��ʶ��ʽ�ǹ������㣬0Ϊ�����㣬1Ϊ���㣬-1Ϊ����
int num_st; ��ʾ�Ӿ���
int num_v; ��Ԫ��
struct Statement* root ָ��ʽ�еĵ�һ���Ӿ�
*/
typedef struct Formula
{
	int sta;//��ʶ��ʽ�ǹ������㣬0Ϊ�����㣬1Ϊ���㣬-1Ϊ����
	int num_st;//��ʾ�Ӿ���
	int num_v;//��Ԫ��
	struct Statement* root;//ָ��ʽ�еĵ�һ���Ӿ�
}Formula;
/*
int* V; ������ȷ����Ϣ�ı�Ԫ
struct Formula* S; ��ʾջ�д洢�Ĺ�ʽ
struct Stack_F* next; ����ָ����һ���ڵ�
*/
typedef struct Stack_F
{
	int* V;//������ȷ����Ϣ�ı�Ԫ
	struct Formula* S;//��ʾջ�д洢�Ĺ�ʽ
	struct Stack_F* next;//����ָ����һ���ڵ�
}Stack_F;
/*---------------�����������תcnf��ʽ�����ݽṹ-------------*/
//ͨ���ڽӱ�����������е�ÿ���ո񣬿ո��ɿ��ܵ�������ɣ�ÿ�����ܵ����ֶ�Ӧ��һ����Ԫ��
//hole���ڴ���ÿһ���ո�
typedef struct hole
{
	int x;//��ʶ��
	int y;//��ʶ��
	int dig_num;//��ʶ���ܵ�������
	struct digtal* elem;//ָ���һ�����ܵ�����
}hole;

//digtal���ڴ���ÿ���ո��п��ܳ��ֵ�����
typedef struct digtal
{
	int num;//����
	int v_num;//��������Ӧ�ı�Ԫ���
	struct digtal* next;
}digtal;


//ԭ����
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
