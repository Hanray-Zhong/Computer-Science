#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//ͨ��clock()���������������ʱ��
#include <time.h>


//һЩ����
#define TURE 1
#define FALSE 0
#define CONFUSE -1

/*--------------����SAT���ֵ����ݽṹ-------------*/
//status������״̬����TRUE��FALSE�ȵ�����
typedef int status;

//���ڼ�¼���֡��Ӿ�͹�ʽ�Ľṹ��
//Literal���ڱ�ʾ��������
typedef struct Literal
{
    int pos;//��ʾ����״̬ 1���������� 0��������
    int num;//��ʾ�����ǵڼ��ű�Ԫ
    struct Literal* next;//ָ����һ������
}Literal;

//Statement���ڱ�ʾ�Ӿ�����
typedef struct Statement
{
    int num_lit;//������
    struct Literal* elem;//ָ���Ӿ��еĵ�һ������
    struct Statement* next;//ָ����һ���Ӿ�
}Statement;

//Formula���ڱ�ʾ��ʽ
typedef struct Formula
{
    int sta;//��ʶ��ʽ�ǹ������㣬0Ϊ�����㣬1Ϊ���㣬-1Ϊ����
    int num_st;//��ʾ�Ӿ���
    int num_v;//��Ԫ��
    struct Statement* root;//ָ��ʽ�еĵ�һ���Ӿ�
}Formula;

//ͨ����������ջ�洢��ʽ
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

//һЩ������ԭ����
/*--------����ģ��SAT&Sudoku-------*/
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
