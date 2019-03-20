#include "head.h"

/*--------------SAT�е�һ��ģ��------------------*/

/*cnfParser()����ͨ��cnf�ļ�����cnf��ʽ*/
void cnfParser(FILE* fp,Formula* S)
{
    //ͨ��fgetc��fgets����ע��
    char buff[1000];
    while(fgetc(fp)=='c')
        fgets(buff,1000,fp);
    //ͨ��fscanf��ȡ��Ԫ�����Ӿ���
    int i;
    for(i=0; i<=4; i++)
        fgetc(fp);//��ȡ�� cnf ���ַ���
    fscanf(fp,"%d %d",&(S->num_v),&(S->num_st));
    fgetc(fp);


    //�����ļ�������ʽ
    Statement* p_s;//���ڴ����Ӿ�
    S->root=(Statement*)malloc(sizeof(Statement));
    p_s=S->root;
    p_s->next=NULL;
    p_s->num_lit=0;//��������ֵΪ0
    for(i=1; i<=S->num_st; i++) //���ѭ�������Ӿ��������Ӿ�ڵ㣬�ڲ�ѭ������0�Ĵ������ֽڵ�
    {
        if(S->root->num_lit!=0)
        {
            p_s->next=(Statement*)malloc(sizeof(Statement));
            p_s=p_s->next;
            p_s->next=NULL;
            p_s->num_lit=0;//��������ֵΪ0
        }
        Literal* p_l;//���ڴ�������
        p_s->elem=(Literal*)malloc(sizeof(Literal));
        p_l=p_s->elem;
        p_l->next=NULL;
        int k;
        fscanf(fp,"%d",&k);
        while(k!=0)//�Ӿ���0��β
        {
            if(p_s->num_lit!=0)
            {
                p_l->next=(Literal*)malloc(sizeof(Literal));
                p_l=p_l->next;
                p_l->next=NULL;
            }
            if(k>0)//����ȡ��������ʱ���������ֵ�posΪ��
            {
                p_l->pos=1;
                p_l->num=k;
            }
            else//����ȡ�ø�����ʱ���������ֵ�posΪ��
            {
                p_l->pos=0;
                p_l->num=(-k);
            }
            (p_s->num_lit)++;//ÿ��ȡһ�����֣��Ӿ����������һ
            fscanf(fp,"%d",&k);
        }
        fgetc(fp);//��ȡÿ���Ӿ�β�Ļ��з�
    }
}



/*------------solver����Ҫ�ĺ���--------------*/

/*copy_S���ڿ�����ǰ�Ĺ�ʽ*/
Formula* copy_S(Formula* S)
{
    Formula* S1;//������
    S1=(Formula*)malloc(sizeof(Formula));
    //���Ƶ�ǰ��ʽ�е�������Ϣ
    S1->sta=S->sta;
    S1->num_st=S->num_st;
    S1->num_v=S->num_v;
    S1->root=(Statement*)malloc(sizeof(Statement));
    S1->root->next=NULL;
    //���ƹ�ʽ����
    Statement* p_s1;//���ڸ����Ӿ�
    Statement* p_s;
    p_s1=S1->root;
    p_s=S->root;
    while(p_s!=NULL)
    {
        p_s1->num_lit=p_s->num_lit;
        p_s1->elem=(Literal*)malloc(sizeof(Literal));
        p_s1->elem->next=NULL;
        Literal* p_l1;//���ڸ�������
        Literal* p_l;
        p_l1=p_s1->elem;
        p_l=p_s->elem;
        while(p_l!=NULL)
        {

            p_l1->num=p_l->num;
            p_l1->pos=p_l->pos;
            if(p_l->next!=NULL)
            {
                p_l1->next=(Literal*)malloc(sizeof(Literal));
                p_l1=p_l1->next;
            }
            p_l1->next=NULL;
            p_l=p_l->next;
        }
        if(p_s->next!=NULL)
        {
            p_s1->next=(Statement*)malloc(sizeof(Statement));
            p_s1=p_s1->next;
        }
        p_s1->next=NULL;
        p_s=p_s->next;
    }
    return S1;
}

/*copy_V���ڿ�����ǰ��Ԫ��ֵ��ϵ*/
int* copy_V(int* V,int num_v)
{
    int* V1;//������
    int i;
    V1=(int*)malloc((num_v+1)*sizeof(int));
    for(i=1; i<=num_v; i++) //���ݱ�Ԫ�����θ���ÿ����Ԫ��ֵ
    {
        V1[i]=V[i];
    }
    return V1;
}

/*judgeClause()�����жϵ�ǰ��ʽ�Ƿ��е��Ӿ䣬�����򷵻�TURE�����û���򷵻�FALSE*/
status judgeClause(Formula* S)
{
    int token;//���ڱ�ʶ��ʽ�Ƿ��е��Ӿ䣬�������־Ϊ1����û�����־Ϊ0
    token=0;
    Statement* p_s;//���ڱ���������ʽ
    p_s=S->root;
    //������ʽ���鹫ʽ���Ƿ��е��Ӿ�
    while((token!=1)&&(p_s!=NULL))
    {
        if(p_s->num_lit==1)
            token=1;
        p_s=p_s->next;
    }
    //����־Ϊ1��ʱ�򷵻��е��Ӿ䣬��Ϊ1ʱ�����޵��Ӿ�
    if(token==1)
    {
        return TURE;
    }
    else
    {
        return FALSE;
    }
}

/*removeClause()����ȥ������ָ�����ֵ��Ӿ�*/
void removeClause(Literal lit,Formula* S)
{
    int token;//���ڱ�ǵ�ǰ�Ӿ��Ƿ����ض�����,1������
    token=0;
    int token_root;//���ڱ�Ǹ��ڵ��Ƿ񱻼���,1��ʾ�Ѽ���
    token_root=0;
    Statement* p_s;//���ڱ�����ʽ
    p_s=NULL;
    Statement* p_sf;//����ɾ���Ӿ�
    p_sf=NULL;
    Literal* p_l;//���ڱ����Ӿ�
    p_l=NULL;
    Literal* p_lf;//����ɾ������
    p_lf=NULL;
    //���������Ӿ䣬���������ض����ֵ��Ӿ���ɾ��֮
    //���жϸ��Ӿ��Ƿ����ض�����
    while((token_root!=1)&&S->root!=NULL)
    {
        p_l=S->root->elem;
        while((token!=1)&&(p_l!=NULL))//���������Ӿ�
        {
            if((p_l->pos==lit.pos)&&(p_l->num==lit.num))
                token=1;
            p_l=p_l->next;
        }
        if(token==1)
        {
            p_sf=S->root;
            S->root=S->root->next;
            //����Ӿ�ռ�õĿռ�
            p_l=p_sf->elem;
            free(p_sf);
            p_sf=NULL;
            while(p_l!=NULL)
            {
                p_lf=p_l->next;
                free(p_l);
                p_l=p_lf;
            }
            (S->num_st)--;//�Ӿ�����һ
        }
        else
            token_root=1;
        token=0;
    }
    if(S->root)
    {
        //����ʣ�๫ʽ
        p_sf=S->root;
        p_s=p_sf->next;
        while(p_s!=NULL)
        {
            p_l=p_s->elem;
            while((token!=1)&&(p_l!=NULL))//���������Ӿ�
            {
                if((p_l->pos==lit.pos)&&(p_l->num==lit.num))
                    token=1;
                p_l=p_l->next;
            }
            //ɾ�������ض����ֵ��Ӿ�
            if(token==1)
            {
                p_s=p_s->next;
                //����Ӿ�ռ�õĿռ�
                p_l=p_sf->next->elem;
                free(p_sf->next);
                while(p_l!=NULL)
                {
                    p_lf=p_l->next;
                    free(p_l);
                    p_l=p_lf;
                }
                p_sf->next=p_s;
                (S->num_st)--;//�Ӿ�����һ
            }
            else
            {
                p_s=p_s->next;
                p_sf=p_sf->next;
            }
            token=0;//���ñ��
        }
    }
}

/*clearClause()��������Ӿ��е��ض�����*/
void clearClause(Literal lit,Formula* S)
{
    Statement* p_s;//���ڱ�����ʽ
    p_s=NULL;
    Literal* p_l;//���ڱ����Ӿ�
    p_l=NULL;
    Literal* p_lf;//����ɾ������
    p_lf=NULL;
    int token;//���ڱ�Ǹ������Ƿ񱻼���,1��ʾ�Ѽ���
    token=0;
    //������ʽ
    p_s=S->root;
    while(p_s!=NULL)
    {
        while((token!=1)&&(p_s->elem!=NULL))//�ȼ��������
        {
            p_l=p_s->elem;
            if((p_l->pos==lit.pos)&&(p_l->num==lit.num))//������Ϊ�ض�����
            {
                p_s->elem=p_s->elem->next;
                free(p_l);//ɾ��������
                p_l=NULL;
                (p_s->num_lit)--;//�Ӿ���������һ
            }
            else
            {
                token=1;//�������Ѽ���
            }
        }
        if(p_s->elem)
        {
            p_lf=p_s->elem;
            p_l=p_lf->next;
            while(p_l!=NULL)//������������
            {
                if((p_l->pos==lit.pos)&&(p_l->num==lit.num))//������Ϊ�ض�����
                {
                    p_l=p_l->next;
                    free(p_lf->next);//ɾ��������
                    (p_s->num_lit)--;//�Ӿ���������һ
                    p_lf->next=p_l;
                }
                else
                {
                    p_l=p_l->next;
                    p_lf=p_lf->next;
                }
            }
        }
        p_s=p_s->next;
        token=0;//��һ�������δ����
    }
}

/*existEmptyClause()�����жϵ�ǰ��ʽ�Ƿ��п��Ӿ䣬���򷵻�TRUE*/
status existEmptyClause(Formula* S)
{
    int token;//���ڱ���Ƿ���ڿ��Ӿ�,1Ϊ����
    token=0;
    Statement* p;//���ڱ�����ʽ
    p=S->root;
    while((token!=1)&&(p!=NULL))
    {
        if(p->num_lit==0)//�ж��Ӿ��Ƿ�Ϊ��
        {
            token=1;
        }
        p=p->next;
    }
    if(token==1)//���Ӿ�Ϊ��ʱ������TRUE
        return TURE;
    else
        return FALSE;
}

/*
*****************************
choose_v()�����ڹ�ʽ��ѡ��һ���ض������ֲ�����
ps�����ڷ��Ѳ���
����Ϊһ����ʽ���������һ���ض�����
˼·��������ʽѡ��������̵��Ӿ䣬���Ӿ���ѡ����ִ������ı�Ԫ��������������
*****************************
*/
Literal choose_v(Formula* S)
{
    Literal lit;//���ڷ���ѡ���Ԫ��������
    Statement* shortest;//����ָ����̵��Ӿ�
    Literal* p_l;//���ڱ�������Ӿ�
    Statement* p;//���ڱ�����ʽ
    int v[2];//���ڱ�����ִ������ı�Ԫ�����ִ���
    int i;
    //������ʽ�ҳ���̵��Ӿ�
    p=S->root;
    shortest=p;
    while(p!=NULL)
    {
        if((p->num_lit)<(shortest->num_lit))
            shortest=p;
        p=p->next;
    }
    //������Ӿ����ҳ����ִ������ı�Ԫ
    int** num_v;//����һ�������Ԫ���������Ŀ�Ķ�ά����
    num_v=(int**)malloc((shortest->num_lit)*sizeof(int*));
    for(i=0; i<shortest->num_lit; i++)
    {
        num_v[i]=(int*)malloc(2*sizeof(int));
        num_v[i][0]=0;
        num_v[i][1]=0;
    }
    p_l=shortest->elem;
    i=0;
    while(p_l!=NULL)//�������Ԫ��Ŀ
    {
        for(i=0; (num_v[i][0]!=p_l->num)&&(num_v[i][0]!=0)&&(i<shortest->num_lit); i++); //�������ڣ���������ǰ��Ԫ�����ޱ�Ԫ������ʼ���ӱ�Ԫ��
        if(num_v[i][0]==p_l->num)//��Ϊ���������б�Ԫʱ����Ԫ����һ
            num_v[i][1]++;
        else if(num_v[i][0]==0)//�������в����ڸñ�Ԫʱ�������Ԫ����Ԫ��Ϊһ
        {
            num_v[i][0]=p_l->num;
            num_v[i][1]=1;
        }
        p_l=p_l->next;
    }
    v[0]=num_v[0][0];
    v[1]=num_v[0][1];
    for(i=0; i<shortest->num_lit; i++) //�ҳ�������Ŀ���ı�Ԫ
    {
        if(num_v[i][1]>v[1])
        {
            v[0]=num_v[i][0];
            v[1]=num_v[i][1];
        }
    }
    //�ѳ��ִ������ı�Ԫ��Ϊ������
    lit.pos=1;
    lit.num=v[0];
    return lit;
}

/*
*******************************
addClause�������ڽ�һ�����������ּ���һ����ʽ��
����һ�����ֺ�һ����ʽ
����һ���µĹ�ʽ(�ù�ʽ�����⿪�ٴ���ռ�)
*******************************
*/
Formula* addClause(Literal lit,Formula* S)
{
    Formula* S1;//���ڷ������ɵĹ�ʽ
    Statement* p_s;//��������һ�����Ӿ�
    Statement* p;//���ڱ�����ʽ
    S1=copy_S(S);//������ʽS
    //������������һ�����Ӿ�
    p_s=(Statement*)malloc(sizeof(Statement));
    p_s->elem=(Literal*)malloc(sizeof(Literal));
    p_s->elem->num=lit.num;
    p_s->elem->pos=lit.pos;
    p_s->elem->next=NULL;
    p_s->num_lit=1;
    p_s->next=NULL;
    //�����Ӿ����빫ʽ��
    p=S1->root;
    while(p->next!=NULL)
        p=p->next;
    p->next=p_s;
    S1->num_st++;//�Ӿ�����һ
    return S1;
}

/*
********************************
destoryFormula()������������ָ����ָ��Ĺ�ʽ��ռ�õ��ڴ�����
���룺��ʽ��ָ�룬�޷���ֵ
********************************
*/
void destoryFormula(Formula* S)
{
    Statement* p_s;//���ڱ�����ʽ
    Statement* p_sf;//����ɾ���Ӿ�
    Literal* p_l;//���ڱ����Ӿ�
    Literal* p_lf;//����ɾ������
    //ɾ����ʽ����¼���Ӿ�λ��
    p_s=S->root;
    free(S);
    //���ѭ������ɾ���Ӿ䣬�ڲ�ѭ������ɾ������
    while(p_s!=NULL)
    {
        p_sf=p_s;
        p_s=p_s->next;
        p_l=p_sf->elem;//��¼������λ�ã�ɾ���Ӿ�
        free(p_sf);
        while(p_l!=NULL)
        {
            p_lf=p_l;
            p_l=p_l->next;
            free(p_lf);
        }
    }
}


/*---------------------Sudokuģ���еĺ���---------------------*/

/*
*******************************
creatFinalSud()��������������ȫ���
����Ϊ����������飬ͨ��ָ��ֱ�ӷ������ɽ��
�㷨˼�룺ͨ�������ĳ�ʼ3��3��֣�ͨ���б任�б�����������վָ��
ps:���ո��һ����16�ֿ���

�Ż�˼·�������ȫ�������һ��������
*******************************
*/
void createFinalSud(int(*sud)[9])
{
    int i;//ѭ������
    int j;
    int k;
    int a;
    //����������и��������λ��������������3��3���
    k=1;
    while(k<=9)//��1��9����Ϊ3��3��ָ�ֵ
    {
        for(i=3; i<6; i++)
        {
            for(j=3; j<6; j++)
            {
                sud[i][j]=k++;
            }
        }
    }
    //ͨ���б任�õ���ʼ3��3�������3��3λ���е�����
    srand((unsigned)time(NULL));
    k=rand()%2;//ͨ�������������ȫ�б任������3��3��ֵ�����λ��
    if(k==1)
    {
        //��ʼ�����
        for(j=0; j<3; j++)
        {
            sud[3][j]=sud[5][j+3];
        }
        for(i=4; i<6; i++)
        {
            for(j=0; j<3; j++)
            {
                sud[i][j]=sud[i-1][j+3];
            }
        }
        //��ʼ���ұ�
        for(j=6; j<9; j++)
        {
            sud[5][j]=sud[3][j-3];
        }
        for(i=3; i<5; i++)
        {
            for(j=6; j<9; j++)
            {
                sud[i][j]=sud[i+1][j-3];
            }
        }
    }
    else
    {
        //��ʼ�����
        for(j=0; j<3; j++)
        {
            sud[5][j]=sud[3][j+3];
        }
        for(i=3; i<5; i++)
        {
            for(j=0; j<3; j++)
            {
                sud[i][j]=sud[i+1][j+3];
            }
        }
        //��ʼ���ұ�
        for(j=6; j<9; j++)
        {
            sud[3][j]=sud[5][j-3];
        }
        for(i=4; i<6; i++)
        {
            for(j=6; j<9; j++)
            {
                sud[i][j]=sud[i-1][j-3];
            }
        }
    }
    //ͨ���б任�õ�����3��3���
    for(a=0; a<9; a+=3)
    {
        k=rand()%2;//ÿ���б任�������ֿ���
        if(k==1)
        {
            //��ʼ���ϱ�
            for(i=0; i<3; i++)
            {
                sud[i][a]=sud[i+3][a+2];
            }
            for(j=a+1; j<a+3; j++)
            {
                for(i=0; i<3; i++)
                {
                    sud[i][j]=sud[i+3][j-1];
                }
            }
            //��ʼ���±�
            for(i=6; i<9; i++)
            {
                sud[i][a+2]=sud[i-3][a];
            }
            for(j=a; j<a+2; j++)
            {
                for(i=6; i<9; i++)
                {
                    sud[i][j]=sud[i-3][j+1];
                }
            }
        }
        else
        {
            //��ʼ���ϱ�
            for(i=0; i<3; i++)
            {
                sud[i][a+2]=sud[i+3][a];
            }
            for(j=a; j<a+2; j++)
            {
                for(i=0; i<3; i++)
                {
                    sud[i][j]=sud[i+3][j+1];
                }
            }
            //��ʼ���±�
            for(i=6; i<9; i++)
            {
                sud[i][a]=sud[i-3][a+2];
            }
            for(j=a+1; j<a+3; j++)
            {
                for(i=6; i<9; i++)
                {
                    sud[i][j]=sud[i-3][j-1];
                }
            }
        }
    }
}

/*
************************************
creatSudProblem���ڲ�����������
����Ϊ����������֣�ͨ��ָ�뷵�������ɵ���������
�㷨˼�룺ȫ������ڶ����ɣ��������ڶ���
easy  20holes,   normal  40holes,    evil  60holes
************************************
*/
int createSudProblem(int(*sud)[9])
{
    int level;//���ڱ��������Ѷ�
    int hole_num;//���ڼ�¼�ڶ���Ŀ
    int i;
    int hole_x;//��¼�ڶ�λ��
    int hole_y;

    //�����ڶ���
    printf("�����������Ѷȣ�\n");
    printf("1��easy\n2��normal\n3��evil\n\n");
    printf("------------------------------------\n");
    printf("��������ѡ���Ѷȣ���1~3��\n");
    scanf("%d",&level);
    while(level>3||level<1)
        printf("����Խ�磡��1~3��\n");
    hole_num=level*20;

    //�ڶ�,�ѱ���ȥ�Ĳ�����Ϊ0
    srand((unsigned)time(NULL));//�����������������
    for(i=1; i<=hole_num; i++)
    {
        hole_x=rand()%9;//��������������ڶ�λ��
        hole_y=rand()%9;
        while(sud[hole_x][hole_y]==0)
        {
            hole_x=rand()%9;//��������������ڶ�λ��
            hole_y=rand()%9;
        }
        sud[hole_x][hole_y]=0;
    }
    return hole_num;
}

/*
************************************
cnfToFile()���ڽ�������cnf��ʽ���뵽�ļ���
����Ϊ������cnf��ʽ�����һ��cnf��ʽ
************************************
*/
void cnfToFile(Formula* S)
{
    FILE* fp;//���ڴ򿪴������ļ�
    char filename[100];
    Statement* p_s;//���ڱ�����ʽ
    Literal* p_l;//���ڱ����Ӿ�


    printf("�����뱣���ļ�������ֻ�������ļ��������������ļ����͡�\n");
    scanf("%s",filename);
    fp=fopen(filename,"w");
    char str[]=".cnf";
    strcpy(filename+strlen(filename),str);//Ϊ�ļ������Ϻ�׺
    if(!fp)
        printf("�ļ���ʧ��!\n");
    else
    {
        //����ע�Ͳ���
        fprintf(fp,"c\nc      write by zjx\nc\n");
        time_t t;//���������ǰʱ��
        struct tm* lt;
        time(&t);
        lt=localtime(&t);
        fprintf(fp,"c      in %d/%d/%d %d:%d:%d\nc\n",lt->tm_year+1900,lt->tm_mon,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
        //�����Ԫ�����Ӿ�������Ϣ
        fprintf(fp,"p cnf %d %d\n",S->num_v,S->num_st);
        //�����Ӿ䲿��
        p_s=S->root;
        while(p_s)
        {
            p_l=p_s->elem;
            while(p_l)
            {
                if(p_l->pos)
                    fprintf(fp,"%d ",p_l->num);
                else
                    fprintf(fp,"%d ",-p_l->num);
                p_l=p_l->next;
            }
            fprintf(fp,"0\n");
            p_s=p_s->next;
        }
    }
}

/*
*******************************
transfSud()���ڽ���������ת��ΪSAT����
����Ϊ������ֺ�cnf��ʽ��ַ
���Ϊ�����ɵ�cnf��ʽ�ͱ�Ԫ��ֵ��ϵ�����б�Ԫ��ֵ��ϵͨ������ֵ���أ���ʽͨ����ʽָ�뷵��
�㷨˼�룺����ÿ���ո������ҽ���һ�����֡�1~9�е�������ÿ�С�ÿ�к�ÿ�����ڳ����ҽ�����һ�δ����Ӿ䣬ͨ���ڽӱ��¼ÿ���ո��п��ܳ��ֵ�����
�Ż�˼·����9��10�����鱣��ÿ�����ֿ��ܳ��ֵ�λ��
*******************************
*/
int* transfSud(int(*sud)[9],Formula*S,hole* holes)
{
    int* Varies;//���ڱ�ʾ��Ԫ��ֵ��ϵ������
    int i;//����ѭ������
    int j;
    int k;
    int x;//���ڱ�������
    int y;
    int hole_num;//���ڼ�¼�ո���
    hole_num=0;
    digtal* p_d;//�������ɿո��п��ܳ��ֵ�����,�������Ӿ������ڱ���
    digtal* p_df;//����ָ��ո���ܵ����ֵ�βλ�ã��������Ӿ������ڱ���
    Statement* p_s;//���ڴ����Ӿ�
    Statement* p_sf;//���ڱ�����ʽ
    Literal* p_l;//���ڴ�������
    Literal* p_lf;//���ڱ����Ӿ�

    //���ɿո�����ܵ������ڽӱ�
    for(i=0; i<9; i++) //��������ҵ�ÿһ���ո�
    {
        for(j=0; j<9; j++)
        {
            if(sud[i][j]==0)
            {
                (holes+hole_num)->x=i;
                (holes+hole_num)->y=j;
                hole_num++;//����ո���
            }
        }
    }
    for(i=0; i<hole_num; i++) //�ҵ�ÿ���ո��Ӧ�����֣��������Ԫ���
    {
        holes[i].elem=NULL;
        p_df=NULL;
        holes[i].dig_num=0;
        for(j=1; j<=9; j++) //�������1~9����Щ�����ܳ����ڴ˿ո�
        {
            int find;//��־�����Ƿ��ѳ���
            find=0;
            for(k=0; k<9&&(find==0); k++) //�����в���
            {
                if(sud[holes[i].x][k]==j)
                    find=1;//��ʾ���ҵ�
            }
            for(k=0; k<9&&(find==0); k++) //�����в���
            {
                if(sud[k][holes[i].y]==j)
                    find=1;
            }
            x=(holes[i].x)/3;//���ڼ�¼�ո����ڵĹ�
            y=(holes[i].y)/3;
            for(int a=3*x; (a>=3*x)&&(a<3*(x+1))&&(find==0); a++)//�ڹ��в���
            {
                for(int b=3*y; (b>=3*y)&&(b<3*(y+1))&&(find==0); b++)
                {
                    if(sud[a][b]==j)
                        find=1;
                }
            }
            if(find==0)//û�з��ֵ�ǰ���֣������ֿ��ܳ����ڿո���
            {
                p_d=(digtal*)malloc(sizeof(digtal));
                p_d->num=j;//��¼���ܵ�����
                p_d->v_num=++(S->num_v);//����������һ����Ԫ��ţ�ͬʱ��Ԫ����һ
                p_d->next=NULL;
                holes[i].dig_num++;//�ո���ܳ��ֵ�������Ŀ��һ
                if(holes[i].elem==NULL)
                {
                    holes[i].elem=p_d;
                    p_df=p_d;
                }
                else
                {
                    p_df->next=p_d;
                    p_df=p_d;
                }
            }
        }
    }

    //�ɿո������һ�����֣�����һ������ �����Ӿ�
    for(i=0; i<hole_num; i++)
    {
        p_d=holes[i].elem;
        p_df=p_d;
        p_s=(Statement*)malloc(sizeof(Statement));
        p_s->elem=NULL;
        p_s->next=NULL;
        S->num_st++;
        if(i==0&&(S->root==NULL))//�����Ӿ�,��Ϊ��һ���Ӿ�ʱ�����ȿ��ǹ�ʽ�ĸ��Ӿ�ָ��
        {
            S->root=p_s;
        }
        else
        {
            p_sf->next=p_s;
        }
        p_sf=p_s;
        while(p_d)//����ÿ���ո�����һ�����ִ����Ӿ�
        {
            p_l=(Literal*)malloc(sizeof(Literal));
            p_l->next=NULL;
            p_sf->num_lit++;//�Ӿ���������һ
            if(p_s->elem==NULL)
            {
                p_s->elem=p_l;
            }
            else
            {
                p_lf->next=p_l;
            }
            p_lf=p_l;
            p_lf->pos=1;//������Ϊ�����Ա�֤��ȡ֮��������һ��Ϊ1
            p_lf->num=p_d->v_num;
            p_d=p_d->next;
        }
        while(p_df)//����ÿ���ո����һ�����ִ����Ӿ�
        {
            p_d=p_df->next;
            while(p_d)
            {
                p_s=(Statement*)malloc(sizeof(Statement));//����һ�����Ӿ�
                p_s->next=NULL;
                S->num_st++;
                p_sf->next=p_s;
                p_sf=p_s;
                p_sf->num_lit=2;//ÿ���Ӿ�ֻ�����������Դ���ֻ��һ������Ϊ��
                p_sf->elem=(Literal*)malloc(sizeof(Literal));
                p_sf->elem->num=p_df->v_num;
                p_sf->elem->pos=0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
                p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                p_sf->elem->next->num=p_d->v_num;
                p_sf->elem->next->pos=0;
                p_sf->elem->next->next=NULL;
                p_d=p_d->next;
            }
            p_df=p_df->next;
        }
    }

    //��ÿ��������ÿ��������һ�Σ����ٳ���һ�� �����Ӿ�
    j=0;
    for(i=0; i<9; i++) //����ÿһ��
    {
        x=j;//���ڼ�¼ÿһ�еĿ�ʼ�ո�λ��
        for(k=1; k<=9; k++) //����ÿ������
        {
            int v[10];//���ڴ������еĿո���ÿ�����ֿ��ܳ���λ�õı�Ԫ��
            v[0]=0;//�������ڴ洢�����ڴ��г��ִ���
            int a;//���ڱ���v����
            int b;
            a=1;
            j=x;
            while((holes[j].x==i)&&j<hole_num)//�ҵ�ÿ�����ֶ�Ӧ�Ŀո����λ�ñ�����Ӧ��Ԫ��
            {
                p_df=holes[j].elem;
                while(p_df)
                {
                    if(p_df->num==k)
                    {
                        v[a]=p_df->v_num;
                        v[0]++;
                        a++;
                        break;
                    }
                    p_df=p_df->next;
                }
                j++;
            }
            if(v[0]==0)
                continue;
            p_s=(Statement*)malloc(sizeof(Statement));//����һ��������һ�������ٳ���һ�����ɹ�ʽ
            S->num_st++;//�Ӿ�����һ
            p_s->num_lit=v[0];
            p_s->next=NULL;
            p_sf->next=p_s;
            p_sf=p_s;
            for(a=1; a<=v[0]; a++)
            {
                p_l=(Literal*)malloc(sizeof(Literal));
                p_l->next=NULL;
                if(a==1)
                {
                    p_sf->elem=p_l;
                }
                else
                {
                    p_lf->next=p_l;
                }
                p_lf=p_l;
                p_lf->pos=1;//��ֻ֤���������ٳ���һ�Σ��ʴ��Ӿ������ȫΪ��
                p_lf->num=v[a];
            }
            for(a=1; a<=v[0]; a++) //����һ��������һ����������һ�����ɹ�ʽ
            {
                for(b=a+1; b<=v[0]; b++)
                {
                    p_s=(Statement*)malloc(sizeof(Statement));
                    S->num_st++;//�Ӿ�����һ
                    p_s->num_lit=2;
                    p_s->next=NULL;
                    p_sf->next=p_s;
                    p_sf=p_s;
                    p_sf->elem=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->num=v[a];
                    p_sf->elem->pos=0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
                    p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->next->num=v[b];
                    p_sf->elem->next->pos=0;
                    p_sf->elem->next->next=NULL;
                }
            }
        }
    }

    //��ÿ��������ÿ��������һ�Σ����ٳ���һ�� �����Ӿ�
    for(j=0; j<9; j++)
    {
        for(k=1; k<=9; k++) //����ÿ������
        {
            int v[10];//���ڴ������еĿո���ÿ�����ֿ��ܳ���λ�õı�Ԫ��
            v[0]=0;//�������ڴ洢�����ڴ��г��ִ���
            int a;//���ڱ���v����
            a=1;
            int b;
            for(i=0; i<hole_num; i++) //�ҵ�ÿ�����ֶ�Ӧ�Ŀո����λ�ñ�����Ӧ��Ԫ��
            {
                if(holes[i].y==j)
                {
                    p_df=holes[i].elem;
                    while(p_df)
                    {
                        if(p_df->num==k)
                        {
                            v[a]=p_df->v_num;
                            v[0]++;
                            a++;
                            break;
                        }
                        p_df=p_df->next;
                    }
                }
            }
            if(v[0]==0)
                continue;
            p_s=(Statement*)malloc(sizeof(Statement));//����һ��������һ�������ٳ���һ�����ɹ�ʽ
            S->num_st++;//�Ӿ�����һ
            p_s->num_lit=v[0];
            p_s->next=NULL;
            p_sf->next=p_s;
            p_sf=p_s;
            for(a=1; a<=v[0]; a++)
            {
                p_l=(Literal*)malloc(sizeof(Literal));
                p_l->next=NULL;
                if(a==1)
                {
                    p_sf->elem=p_l;
                }
                else
                {
                    p_lf->next=p_l;
                }
                p_lf=p_l;
                p_lf->pos=1;//��ֻ֤���������ٳ���һ�Σ��ʴ��Ӿ������ȫΪ��
                p_lf->num=v[a];
            }
            for(a=1; a<=v[0]; a++) //����һ��������һ����������һ�����ɹ�ʽ
            {
                for(b=a+1; b<=v[0]; b++)
                {
                    p_s=(Statement*)malloc(sizeof(Statement));
                    S->num_st++;//�Ӿ�����һ
                    p_s->num_lit=2;
                    p_s->next=NULL;
                    p_sf->next=p_s;
                    p_sf=p_s;
                    p_sf->elem=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->num=v[a];
                    p_sf->elem->pos=0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
                    p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->next->num=v[b];
                    p_sf->elem->next->pos=0;
                    p_sf->elem->next->next=NULL;
                }
            }
        }
    }
    //��ÿ��������ÿ���ӹ���������һ�Σ����ٳ���һ�� �����Ӿ�
    int place;//���ڱ�����
    for(place=0; place<9; place++)
    {
        int ub_x;//��ʾ�����Ͻ�
        int ub_y;
        int lb_x;//��ʾ�����½�
        int lb_y;
        lb_x=(place/3)*3;
        ub_x=(place/3+1)*3;
        switch (place)//ȷ����ǰ����Ӧ�����½�
        {
        case 0:
        case 3:
        case 6:
        {
            lb_y=0;
            ub_y=3;
            break;
        }
        case 1:
        case 4:
        case 7:
        {
            lb_y=3;
            ub_y=6;
            break;
        }
        case 2:
        case 5:
        case 8:
        {
            lb_y=6;
            ub_y=9;
            break;
        }
        }
        for(k=1; k<=9; k++) //����ÿ������
        {
            int v[10];//���ڴ������еĿո���ÿ�����ֿ��ܳ���λ�õı�Ԫ��
            v[0]=0;//�������ڴ洢�����ڴ��г��ִ���
            int a;//���ڸ�������
            int b;
            a=0;
            b=1;
            for(a=0; a<hole_num; a++)//�ҵ�ÿ�����ֶ�Ӧ�Ŀո����λ�ñ�����Ӧ��Ԫ��
            {
                if((holes[a].x>=lb_x)&&(holes[a].x<ub_x)&&(holes[a].y>=lb_y)&&(holes[a].y<ub_y))//���ո��ڵ�ǰ����ʱ
                {
                    p_df=holes[a].elem;
                    while(p_df)//�����ո��п��ܳ��ֵ�����
                    {
                        if(p_df->num==k)//���ǡΪ��ǰ�������������
                        {
                            v[b]=p_df->v_num;
                            v[0]++;
                            b++;
                            break;
                        }
                        p_df=p_df->next;
                    }
                }
            }
            if(v[0]==0)
                continue;
            p_s=(Statement*)malloc(sizeof(Statement));//����һ��������һ�������ٳ���һ�����ɹ�ʽ
            S->num_st++;//�Ӿ�����һ
            p_s->num_lit=v[0];
            p_s->next=NULL;
            p_sf->next=p_s;
            p_sf=p_s;
            for(a=1; a<=v[0]; a++)
            {
                p_l=(Literal*)malloc(sizeof(Literal));
                p_l->next=NULL;
                if(a==1)
                {
                    p_sf->elem=p_l;
                }
                else
                {
                    p_lf->next=p_l;
                }
                p_lf=p_l;
                p_lf->pos=1;//��ֻ֤���������ٳ���һ�Σ��ʴ��Ӿ������ȫΪ��
                p_lf->num=v[a];
            }
            for(a=1; a<=v[0]; a++) //����һ��������һ����������һ�����ɹ�ʽ
            {
                for(b=a+1; b<=v[0]; b++)
                {
                    p_s=(Statement*)malloc(sizeof(Statement));
                    S->num_st++;//�Ӿ�����һ
                    p_s->num_lit=2;
                    p_s->next=NULL;
                    p_sf->next=p_s;
                    p_sf=p_s;
                    p_sf->elem=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->num=v[a];
                    p_sf->elem->pos=0;//��������ֻ��һ��Ϊ�棬�ʶ��Ǹ�����
                    p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->next->num=v[b];
                    p_sf->elem->next->pos=0;
                    p_sf->elem->next->next=NULL;
                }
            }
        }
    }

    //�ɱ�Ԫ�����ɱ�Ԫ��ֵ��ϵ����
    Varies=(int*)malloc((S->num_v+1)*sizeof(int));
    for(i=1; i<(S->num_v+1); i++)
    Varies[i]=-1;
    return Varies;
}

/*
*******************************
showSudResult()���ڽ�cnf��Ԫ��ֵ��ϵת��Ϊ�����ĽⲢ���
����Ϊһ��cnf��Ԫ��ֵ��ϵ
���Ϊ�����Ľ�
�㷨˼�룺�������Ԫ�أ�����Ԫ��Ϊ0ʱ���ҵ��ո������ж�Ӧ�Ŀո񣬱����鿴�ո����Ǹ����ֶ�Ӧ�ı�ԪΪ�������������
*******************************
*/
void showSudResult(int* Varies,hole* holes,int(*sud)[9])
{
    int i;//���ڱ����������
    int j;
    int k;//���ڱ����ո�����
    k=0;
    digtal* p;

    printf("\n******************************\n\n");
    printf("�����Ľ�Ϊ��\n\n");
    printf("        -------------------\n");
    for(i=0; i<9; i++)
    {
        printf("\t|");
        for(j=0; j<9; j++)
        {
            if(sud[i][j]==0)//���˴�Ϊ��ʱ
            {
                p=holes[k++].elem;
                while(p)
                {
                    if(Varies[p->v_num])
                    {
                        sud[i][j]=p->num;
                        break;
                    }
                    else
                        p=p->next;
                }
            }
            printf("%d|",sud[i][j]);
        }
        printf("\n");
    }
    printf("        -------------------\n\n");
}
