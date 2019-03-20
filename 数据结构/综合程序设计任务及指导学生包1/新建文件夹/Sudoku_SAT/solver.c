#include "head.h"
/*
******************************
sovler()用于在提供cnf范式的前提下判断公式的可满足性。
输入为公式的指针和存储变元真值状态的指针
如果可满足则返回TURE，如果不满足则返回FALSE，如果判断失败则返回CONFUSE
******************************
*/
status solver(Formula* S,int* Varies)
{
    Formula* S_mid;//用于临时储存生成的公式
    Formula* S_current;//用于表示当前公式
    Literal v;//用于记录分裂策略选出的文字
    int* V;//用于表示当前变元真值状况
    int token;//用于标记是否为第一次循环,1表示是
    token=1;
    int i;

    //创建栈用于非递归过程
    Stack_F* top;//栈顶
    Stack_F* p;//辅助入栈和出栈
    top=(Stack_F*)malloc(sizeof(Stack_F));
    //将公式和变元的初始状态入栈
    top->S=copy_S(S);
    top->V=copy_V(Varies,S->num_v);
    top->next=NULL;
    //设置初始当前公式
    S_current=S;
    while((S_current->sta!=1)&&(top!=NULL))
    {
        //判断是否是第一次循环，如果是，则标记为不是;如果不是，则进行删除公式和真值关系操作
        if(token==1)
        {
            token=0;
        }
        else
        {
            destoryFormula(S_current);
            free(V);
        }
        //栈头公式出栈并作为当前公式，栈头变元真值关系出栈作为当前变元真值关系
        S_current=top->S;
        V=top->V;
        p=top;
        top=top->next;
        free(p);
        //当存在单子句时，用单子句传播规则处理公式

        while(judgeClause(S_current))
        {
            //选择一个单子句，并记录文字
            Literal lit;//用于记录文字
            Statement* p_s;//用于遍历公式
            p_s=S_current->root;
            while(p_s->num_lit!=1)
                p_s=p_s->next;
            lit=*(p_s->elem);//取单子句的文字
            //记录此单子句所含文字的变元使单子句为真
            if(lit.pos==1)
                V[lit.num]=1;
            else
                V[lit.num]=0;
            //清除所有含有lit记录的文字的子句
            removeClause(lit,S_current);
            if(lit.pos==1)//将lit变为其负文字
                lit.pos=0;
            else
                lit.pos=1;
            //清除公式中lit记录文字的负文字
            clearClause(lit,S_current);
            if(S_current->root==NULL)
            {
                //当公式可满足时，复制当前变元真值关系
                S_current->sta=1;
                for(i=1; i<=S->num_v; i++) //复制此时的真值状态
                {
                    Varies[i]=V[i];
                }
            }
            else if(existEmptyClause(S_current))
            {
                S_current->sta=0;
            }
        }
        //当不存在单子句时，若满足性标识为-1则使用分裂策略选择特定变元生成两个新的公式
        if(S_current->sta==-1)
        {
            v=choose_v(S_current);
            //先向子句集合中加入由分裂策略选出的文字组成的单子句
            S_mid=addClause(v,S_current);
            p=(Stack_F*)malloc(sizeof(Stack_F));//将生成的公式入栈
            p->S=S_mid;
            p->V=copy_V(V,S->num_v);
            p->next=top;
            top=p;
            //在向子句集中加入由由分裂策略选出文字的负文字组成的单子句
            v.pos=0;
            S_mid=addClause(v,S_current);
            p=(Stack_F*)malloc(sizeof(Stack_F));//将生成的公式入栈
            p->S=S_mid;
            p->V=copy_V(V,S->num_v);
            p->next=top;
            top=p;
        }
    }
    //当公式可满足时
    if(S_current->sta==1)
    {
        return TURE;
    }
    //当公式不满足是返回FALSE
    else if(S_current->sta==0)
    {
        return FALSE;
    }
    //当公式不确定满足性时返回CONFUSE
    else
    {
        return CONFUSE;
    }
}
