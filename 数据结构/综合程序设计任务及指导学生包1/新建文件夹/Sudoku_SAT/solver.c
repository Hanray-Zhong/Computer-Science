#include "head.h"
/*
******************************
sovler()�������ṩcnf��ʽ��ǰ�����жϹ�ʽ�Ŀ������ԡ�
����Ϊ��ʽ��ָ��ʹ洢��Ԫ��ֵ״̬��ָ��
����������򷵻�TURE������������򷵻�FALSE������ж�ʧ���򷵻�CONFUSE
******************************
*/
status solver(Formula* S,int* Varies)
{
    Formula* S_mid;//������ʱ�������ɵĹ�ʽ
    Formula* S_current;//���ڱ�ʾ��ǰ��ʽ
    Literal v;//���ڼ�¼���Ѳ���ѡ��������
    int* V;//���ڱ�ʾ��ǰ��Ԫ��ֵ״��
    int token;//���ڱ���Ƿ�Ϊ��һ��ѭ��,1��ʾ��
    token=1;
    int i;

    //����ջ���ڷǵݹ����
    Stack_F* top;//ջ��
    Stack_F* p;//������ջ�ͳ�ջ
    top=(Stack_F*)malloc(sizeof(Stack_F));
    //����ʽ�ͱ�Ԫ�ĳ�ʼ״̬��ջ
    top->S=copy_S(S);
    top->V=copy_V(Varies,S->num_v);
    top->next=NULL;
    //���ó�ʼ��ǰ��ʽ
    S_current=S;
    while((S_current->sta!=1)&&(top!=NULL))
    {
        //�ж��Ƿ��ǵ�һ��ѭ��������ǣ�����Ϊ����;������ǣ������ɾ����ʽ����ֵ��ϵ����
        if(token==1)
        {
            token=0;
        }
        else
        {
            destoryFormula(S_current);
            free(V);
        }
        //ջͷ��ʽ��ջ����Ϊ��ǰ��ʽ��ջͷ��Ԫ��ֵ��ϵ��ջ��Ϊ��ǰ��Ԫ��ֵ��ϵ
        S_current=top->S;
        V=top->V;
        p=top;
        top=top->next;
        free(p);
        //�����ڵ��Ӿ�ʱ���õ��Ӿ䴫��������ʽ

        while(judgeClause(S_current))
        {
            //ѡ��һ�����Ӿ䣬����¼����
            Literal lit;//���ڼ�¼����
            Statement* p_s;//���ڱ�����ʽ
            p_s=S_current->root;
            while(p_s->num_lit!=1)
                p_s=p_s->next;
            lit=*(p_s->elem);//ȡ���Ӿ������
            //��¼�˵��Ӿ��������ֵı�Ԫʹ���Ӿ�Ϊ��
            if(lit.pos==1)
                V[lit.num]=1;
            else
                V[lit.num]=0;
            //������к���lit��¼�����ֵ��Ӿ�
            removeClause(lit,S_current);
            if(lit.pos==1)//��lit��Ϊ�为����
                lit.pos=0;
            else
                lit.pos=1;
            //�����ʽ��lit��¼���ֵĸ�����
            clearClause(lit,S_current);
            if(S_current->root==NULL)
            {
                //����ʽ������ʱ�����Ƶ�ǰ��Ԫ��ֵ��ϵ
                S_current->sta=1;
                for(i=1; i<=S->num_v; i++) //���ƴ�ʱ����ֵ״̬
                {
                    Varies[i]=V[i];
                }
            }
            else if(existEmptyClause(S_current))
            {
                S_current->sta=0;
            }
        }
        //�������ڵ��Ӿ�ʱ���������Ա�ʶΪ-1��ʹ�÷��Ѳ���ѡ���ض���Ԫ���������µĹ�ʽ
        if(S_current->sta==-1)
        {
            v=choose_v(S_current);
            //�����Ӿ伯���м����ɷ��Ѳ���ѡ����������ɵĵ��Ӿ�
            S_mid=addClause(v,S_current);
            p=(Stack_F*)malloc(sizeof(Stack_F));//�����ɵĹ�ʽ��ջ
            p->S=S_mid;
            p->V=copy_V(V,S->num_v);
            p->next=top;
            top=p;
            //�����Ӿ伯�м������ɷ��Ѳ���ѡ�����ֵĸ�������ɵĵ��Ӿ�
            v.pos=0;
            S_mid=addClause(v,S_current);
            p=(Stack_F*)malloc(sizeof(Stack_F));//�����ɵĹ�ʽ��ջ
            p->S=S_mid;
            p->V=copy_V(V,S->num_v);
            p->next=top;
            top=p;
        }
    }
    //����ʽ������ʱ
    if(S_current->sta==1)
    {
        return TURE;
    }
    //����ʽ�������Ƿ���FALSE
    else if(S_current->sta==0)
    {
        return FALSE;
    }
    //����ʽ��ȷ��������ʱ����CONFUSE
    else
    {
        return CONFUSE;
    }
}
