#include "head.h"

/*--------------SAT中的一个模块------------------*/

/*cnfParser()用于通过cnf文件生成cnf范式*/
void cnfParser(FILE* fp,Formula* S)
{
    //通过fgetc和fgets跳过注释
    char buff[1000];
    while(fgetc(fp)=='c')
        fgets(buff,1000,fp);
    //通过fscanf读取变元数和子句数
    int i;
    for(i=0; i<=4; i++)
        fgetc(fp);//读取“ cnf ”字符串
    fscanf(fp,"%d %d",&(S->num_v),&(S->num_st));
    fgetc(fp);


    //根据文件创建公式
    Statement* p_s;//用于创建子句
    S->root=(Statement*)malloc(sizeof(Statement));
    p_s=S->root;
    p_s->next=NULL;
    p_s->num_lit=0;//文字数初值为0
    for(i=1; i<=S->num_st; i++) //外层循环根据子句数创建子句节点，内层循环根据0的创建文字节点
    {
        if(S->root->num_lit!=0)
        {
            p_s->next=(Statement*)malloc(sizeof(Statement));
            p_s=p_s->next;
            p_s->next=NULL;
            p_s->num_lit=0;//文字数初值为0
        }
        Literal* p_l;//用于创建文字
        p_s->elem=(Literal*)malloc(sizeof(Literal));
        p_l=p_s->elem;
        p_l->next=NULL;
        int k;
        fscanf(fp,"%d",&k);
        while(k!=0)//子句以0结尾
        {
            if(p_s->num_lit!=0)
            {
                p_l->next=(Literal*)malloc(sizeof(Literal));
                p_l=p_l->next;
                p_l->next=NULL;
            }
            if(k>0)//当读取得正文字时则设置文字的pos为正
            {
                p_l->pos=1;
                p_l->num=k;
            }
            else//当读取得负文字时则设置文字的pos为负
            {
                p_l->pos=0;
                p_l->num=(-k);
            }
            (p_s->num_lit)++;//每读取一个文字，子句的文字数加一
            fscanf(fp,"%d",&k);
        }
        fgetc(fp);//读取每行子句尾的换行符
    }
}



/*------------solver中需要的函数--------------*/

/*copy_S用于拷贝当前的公式*/
Formula* copy_S(Formula* S)
{
    Formula* S1;//拷贝者
    S1=(Formula*)malloc(sizeof(Formula));
    //复制当前公式中的所有信息
    S1->sta=S->sta;
    S1->num_st=S->num_st;
    S1->num_v=S->num_v;
    S1->root=(Statement*)malloc(sizeof(Statement));
    S1->root->next=NULL;
    //复制公式链表
    Statement* p_s1;//用于复制子句
    Statement* p_s;
    p_s1=S1->root;
    p_s=S->root;
    while(p_s!=NULL)
    {
        p_s1->num_lit=p_s->num_lit;
        p_s1->elem=(Literal*)malloc(sizeof(Literal));
        p_s1->elem->next=NULL;
        Literal* p_l1;//用于复制文字
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

/*copy_V用于拷贝当前变元真值关系*/
int* copy_V(int* V,int num_v)
{
    int* V1;//拷贝者
    int i;
    V1=(int*)malloc((num_v+1)*sizeof(int));
    for(i=1; i<=num_v; i++) //根据变元数依次复制每个变元的值
    {
        V1[i]=V[i];
    }
    return V1;
}

/*judgeClause()用于判断当前公式是否含有单子句，如有则返回TURE，如果没有则返回FALSE*/
status judgeClause(Formula* S)
{
    int token;//用于标识公式是否含有单子句，如有则标志为1，如没有则标志为0
    token=0;
    Statement* p_s;//用于遍历整个公式
    p_s=S->root;
    //遍历公式检验公式中是否含有单子句
    while((token!=1)&&(p_s!=NULL))
    {
        if(p_s->num_lit==1)
            token=1;
        p_s=p_s->next;
    }
    //当标志为1的时候返回有单子句，不为1时返回无单子句
    if(token==1)
    {
        return TURE;
    }
    else
    {
        return FALSE;
    }
}

/*removeClause()用于去除含有指定文字的子句*/
void removeClause(Literal lit,Formula* S)
{
    int token;//用于标记当前子句是否含有特定文字,1代表含有
    token=0;
    int token_root;//用于标记根节点是否被检验,1表示已检验
    token_root=0;
    Statement* p_s;//用于遍历公式
    p_s=NULL;
    Statement* p_sf;//用于删除子句
    p_sf=NULL;
    Literal* p_l;//用于遍历子句
    p_l=NULL;
    Literal* p_lf;//用于删除文字
    p_lf=NULL;
    //遍历所有子句，碰到含有特定文字的子句则删除之
    //先判断根子句是否含有特定文字
    while((token_root!=1)&&S->root!=NULL)
    {
        p_l=S->root->elem;
        while((token!=1)&&(p_l!=NULL))//遍历整个子句
        {
            if((p_l->pos==lit.pos)&&(p_l->num==lit.num))
                token=1;
            p_l=p_l->next;
        }
        if(token==1)
        {
            p_sf=S->root;
            S->root=S->root->next;
            //清空子句占用的空间
            p_l=p_sf->elem;
            free(p_sf);
            p_sf=NULL;
            while(p_l!=NULL)
            {
                p_lf=p_l->next;
                free(p_l);
                p_l=p_lf;
            }
            (S->num_st)--;//子句数减一
        }
        else
            token_root=1;
        token=0;
    }
    if(S->root)
    {
        //遍历剩余公式
        p_sf=S->root;
        p_s=p_sf->next;
        while(p_s!=NULL)
        {
            p_l=p_s->elem;
            while((token!=1)&&(p_l!=NULL))//遍历整个子句
            {
                if((p_l->pos==lit.pos)&&(p_l->num==lit.num))
                    token=1;
                p_l=p_l->next;
            }
            //删除含有特定文字的子句
            if(token==1)
            {
                p_s=p_s->next;
                //清空子句占用的空间
                p_l=p_sf->next->elem;
                free(p_sf->next);
                while(p_l!=NULL)
                {
                    p_lf=p_l->next;
                    free(p_l);
                    p_l=p_lf;
                }
                p_sf->next=p_s;
                (S->num_st)--;//子句数减一
            }
            else
            {
                p_s=p_s->next;
                p_sf=p_sf->next;
            }
            token=0;//重置标记
        }
    }
}

/*clearClause()用于清除子句中的特定文字*/
void clearClause(Literal lit,Formula* S)
{
    Statement* p_s;//用于遍历公式
    p_s=NULL;
    Literal* p_l;//用于遍历子句
    p_l=NULL;
    Literal* p_lf;//用于删除文字
    p_lf=NULL;
    int token;//用于标记根文字是否被检验,1表示已检验
    token=0;
    //遍历公式
    p_s=S->root;
    while(p_s!=NULL)
    {
        while((token!=1)&&(p_s->elem!=NULL))//先检验根文字
        {
            p_l=p_s->elem;
            if((p_l->pos==lit.pos)&&(p_l->num==lit.num))//根文字为特定文字
            {
                p_s->elem=p_s->elem->next;
                free(p_l);//删除根文字
                p_l=NULL;
                (p_s->num_lit)--;//子句文字数减一
            }
            else
            {
                token=1;//根文字已检验
            }
        }
        if(p_s->elem)
        {
            p_lf=p_s->elem;
            p_l=p_lf->next;
            while(p_l!=NULL)//检验其他文字
            {
                if((p_l->pos==lit.pos)&&(p_l->num==lit.num))//此文字为特定文字
                {
                    p_l=p_l->next;
                    free(p_lf->next);//删除根文字
                    (p_s->num_lit)--;//子句文字数减一
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
        token=0;//下一句根文字未检验
    }
}

/*existEmptyClause()用于判断当前公式是否含有空子句，有则返回TRUE*/
status existEmptyClause(Formula* S)
{
    int token;//用于标记是否存在空子句,1为存在
    token=0;
    Statement* p;//用于遍历公式
    p=S->root;
    while((token!=1)&&(p!=NULL))
    {
        if(p->num_lit==0)//判断子句是否为空
        {
            token=1;
        }
        p=p->next;
    }
    if(token==1)//当子句为空时，返回TRUE
        return TURE;
    else
        return FALSE;
}

/*
*****************************
choose_v()用于在公式中选择一个特定的文字并返回
ps：用于分裂策略
输入为一个公式，输出返回一个特定文字
思路：遍历公式选出长度最短的子句，在子句中选择出现次数最多的变元，返回其正文字
*****************************
*/
Literal choose_v(Formula* S)
{
    Literal lit;//用于返回选择变元的正文字
    Statement* shortest;//用于指向最短的子句
    Literal* p_l;//用于遍历最短子句
    Statement* p;//用于遍历公式
    int v[2];//用于保存出现次数最多的变元及出现次数
    int i;
    //遍历公式找出最短的子句
    p=S->root;
    shortest=p;
    while(p!=NULL)
    {
        if((p->num_lit)<(shortest->num_lit))
            shortest=p;
        p=p->next;
    }
    //在最短子句中找出出现次数最多的变元
    int** num_v;//生成一个保存变元及其出现数目的二维数组
    num_v=(int**)malloc((shortest->num_lit)*sizeof(int*));
    for(i=0; i<shortest->num_lit; i++)
    {
        num_v[i]=(int*)malloc(2*sizeof(int));
        num_v[i][0]=0;
        num_v[i][1]=0;
    }
    p_l=shortest->elem;
    i=0;
    while(p_l!=NULL)//保存各变元数目
    {
        for(i=0; (num_v[i][0]!=p_l->num)&&(num_v[i][0]!=0)&&(i<shortest->num_lit); i++); //在数组内，当遇见当前变元或者无变元处，开始增加变元数
        if(num_v[i][0]==p_l->num)//当为数组中已有变元时，变元数加一
            num_v[i][1]++;
        else if(num_v[i][0]==0)//当数组中不存在该变元时，存入变元，变元数为一
        {
            num_v[i][0]=p_l->num;
            num_v[i][1]=1;
        }
        p_l=p_l->next;
    }
    v[0]=num_v[0][0];
    v[1]=num_v[0][1];
    for(i=0; i<shortest->num_lit; i++) //找出文字数目最多的变元
    {
        if(num_v[i][1]>v[1])
        {
            v[0]=num_v[i][0];
            v[1]=num_v[i][1];
        }
    }
    //把出现次数最多的变元变为正文字
    lit.pos=1;
    lit.num=v[0];
    return lit;
}

/*
*******************************
addClause函数用于将一个给定的文字加入一个公式中
输入一个文字和一个公式
返回一个新的公式(该公式的另外开辟储存空间)
*******************************
*/
Formula* addClause(Literal lit,Formula* S)
{
    Formula* S1;//用于返回生成的公式
    Statement* p_s;//用于生成一个单子句
    Statement* p;//用于遍历公式
    S1=copy_S(S);//拷贝公式S
    //根据文字生成一个单子句
    p_s=(Statement*)malloc(sizeof(Statement));
    p_s->elem=(Literal*)malloc(sizeof(Literal));
    p_s->elem->num=lit.num;
    p_s->elem->pos=lit.pos;
    p_s->elem->next=NULL;
    p_s->num_lit=1;
    p_s->next=NULL;
    //将单子句纳入公式中
    p=S1->root;
    while(p->next!=NULL)
        p=p->next;
    p->next=p_s;
    S1->num_st++;//子句数加一
    return S1;
}

/*
********************************
destoryFormula()用于销毁输入指针所指向的公式所占用的内存区域
输入：公式的指针，无返回值
********************************
*/
void destoryFormula(Formula* S)
{
    Statement* p_s;//用于遍历公式
    Statement* p_sf;//用于删除子句
    Literal* p_l;//用于遍历子句
    Literal* p_lf;//用于删除文字
    //删除公式，记录根子句位置
    p_s=S->root;
    free(S);
    //外层循环遍历删除子句，内层循环遍历删除文字
    while(p_s!=NULL)
    {
        p_sf=p_s;
        p_s=p_s->next;
        p_l=p_sf->elem;//记录根文字位置，删除子句
        free(p_sf);
        while(p_l!=NULL)
        {
            p_lf=p_l;
            p_l=p_l->next;
            free(p_lf);
        }
    }
}


/*---------------------Sudoku模块中的函数---------------------*/

/*
*******************************
creatFinalSud()用于生成数独完全格局
输入为数独格局数组，通过指针直接返回生成结果
算法思想：通过给定的初始3×3格局，通过行变换列变幻生成数独终局格局
ps:最终格局一共有16种可能

优化思路：如何完全随机生成一个数独？
*******************************
*/
void createFinalSud(int(*sud)[9])
{
    int i;//循环变量
    int j;
    int k;
    int a;
    //在数独格局中给定最初的位于数独格局中央的3×3格局
    k=1;
    while(k<=9)//由1到9依次为3×3格局赋值
    {
        for(i=3; i<6; i++)
        {
            for(j=3; j<6; j++)
            {
                sud[i][j]=k++;
            }
        }
    }
    //通过行变换得到初始3×3格局左右3×3位置中的数字
    srand((unsigned)time(NULL));
    k=rand()%2;//通过随机数决定完全行变换产生的3×3格局的左右位置
    if(k==1)
    {
        //初始化左边
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
        //初始化右边
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
        //初始化左边
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
        //初始化右边
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
    //通过列变换得到其他3×3格局
    for(a=0; a<9; a+=3)
    {
        k=rand()%2;//每个列变换具有两种可能
        if(k==1)
        {
            //初始化上边
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
            //初始化下边
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
            //初始化上边
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
            //初始化下边
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
creatSudProblem用于产生数独问题
输入为完整数独格局，通过指针返回已生成的数独问题
算法思想：全盘随机挖洞生成，可设置挖洞数
easy  20holes,   normal  40holes,    evil  60holes
************************************
*/
int createSudProblem(int(*sud)[9])
{
    int level;//用于保存数独难度
    int hole_num;//用于记录挖洞数目
    int i;
    int hole_x;//记录挖洞位置
    int hole_y;

    //生成挖洞数
    printf("数独有以下难度：\n");
    printf("1、easy\n2、normal\n3、evil\n\n");
    printf("------------------------------------\n");
    printf("输入数字选择难度：【1~3】\n");
    scanf("%d",&level);
    while(level>3||level<1)
        printf("输入越界！【1~3】\n");
    hole_num=level*20;

    //挖洞,把被挖去的部分设为0
    srand((unsigned)time(NULL));//设置随机数生成种子
    for(i=1; i<=hole_num; i++)
    {
        hole_x=rand()%9;//利用随机数生成挖洞位置
        hole_y=rand()%9;
        while(sud[hole_x][hole_y]==0)
        {
            hole_x=rand()%9;//利用随机数生成挖洞位置
            hole_y=rand()%9;
        }
        sud[hole_x][hole_y]=0;
    }
    return hole_num;
}

/*
************************************
cnfToFile()用于将给定的cnf范式输入到文件中
输入为给定的cnf范式，输出一个cnf公式
************************************
*/
void cnfToFile(Formula* S)
{
    FILE* fp;//用于打开待输入文件
    char filename[100];
    Statement* p_s;//用于遍历公式
    Literal* p_l;//用于遍历子句


    printf("请输入保存文件名：【只需输入文件名，不用输入文件类型】\n");
    scanf("%s",filename);
    fp=fopen(filename,"w");
    char str[]=".cnf";
    strcpy(filename+strlen(filename),str);//为文件名加上后缀
    if(!fp)
        printf("文件打开失败!\n");
    else
    {
        //输入注释部分
        fprintf(fp,"c\nc      write by zjx\nc\n");
        time_t t;//用于输出当前时间
        struct tm* lt;
        time(&t);
        lt=localtime(&t);
        fprintf(fp,"c      in %d/%d/%d %d:%d:%d\nc\n",lt->tm_year+1900,lt->tm_mon,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
        //输入变元数和子句数等信息
        fprintf(fp,"p cnf %d %d\n",S->num_v,S->num_st);
        //输入子句部分
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
transfSud()用于将数独问题转化为SAT问题
输入为数独格局和cnf公式地址
输出为已生成的cnf公式和变元真值关系。其中变元真值关系通过返回值返回，公式通过公式指针返回
算法思想：根据每个空格内有且仅有一个数字、1~9中的数字在每行、每列和每个宫内出现且仅出现一次创建子句，通过邻接表记录每个空格中可能出现的数字
优化思路：用9×10的数组保存每个数字可能出现的位置
*******************************
*/
int* transfSud(int(*sud)[9],Formula*S,hole* holes)
{
    int* Varies;//用于表示变元真值关系的数组
    int i;//用作循环变量
    int j;
    int k;
    int x;//用于保存行列
    int y;
    int hole_num;//用于记录空格数
    hole_num=0;
    digtal* p_d;//用于生成空格中可能出现的数字,在生成子句中用于遍历
    digtal* p_df;//用于指向空格可能的数字的尾位置，在生成子句中用于遍历
    Statement* p_s;//用于创建子句
    Statement* p_sf;//用于遍历公式
    Literal* p_l;//用于创建文字
    Literal* p_lf;//用于遍历子句

    //生成空格及其可能的数字邻接表
    for(i=0; i<9; i++) //遍历格局找到每一个空格
    {
        for(j=0; j<9; j++)
        {
            if(sud[i][j]==0)
            {
                (holes+hole_num)->x=i;
                (holes+hole_num)->y=j;
                hole_num++;//保存空格数
            }
        }
    }
    for(i=0; i<hole_num; i++) //找到每个空格对应的数字，生成其变元编号
    {
        holes[i].elem=NULL;
        p_df=NULL;
        holes[i].dig_num=0;
        for(j=1; j<=9; j++) //遍历检查1~9中哪些数可能出现于此空格
        {
            int find;//标志此数是否已出现
            find=0;
            for(k=0; k<9&&(find==0); k++) //在行中查找
            {
                if(sud[holes[i].x][k]==j)
                    find=1;//表示已找到
            }
            for(k=0; k<9&&(find==0); k++) //在列中查找
            {
                if(sud[k][holes[i].y]==j)
                    find=1;
            }
            x=(holes[i].x)/3;//用于记录空格所在的宫
            y=(holes[i].y)/3;
            for(int a=3*x; (a>=3*x)&&(a<3*(x+1))&&(find==0); a++)//在宫中查找
            {
                for(int b=3*y; (b>=3*y)&&(b<3*(y+1))&&(find==0); b++)
                {
                    if(sud[a][b]==j)
                        find=1;
                }
            }
            if(find==0)//没有发现当前数字，则数字可能出现在空格中
            {
                p_d=(digtal*)malloc(sizeof(digtal));
                p_d->num=j;//记录可能的数字
                p_d->v_num=++(S->num_v);//给定此数字一个变元编号，同时变元数加一
                p_d->next=NULL;
                holes[i].dig_num++;//空格可能出现的数字数目加一
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

    //由空格内最多一个数字，最少一个数字 创建子句
    for(i=0; i<hole_num; i++)
    {
        p_d=holes[i].elem;
        p_df=p_d;
        p_s=(Statement*)malloc(sizeof(Statement));
        p_s->elem=NULL;
        p_s->next=NULL;
        S->num_st++;
        if(i==0&&(S->root==NULL))//创建子句,当为第一个子句时，优先考虑公式的根子句指针
        {
            S->root=p_s;
        }
        else
        {
            p_sf->next=p_s;
        }
        p_sf=p_s;
        while(p_d)//根据每个空格最少一个数字创建子句
        {
            p_l=(Literal*)malloc(sizeof(Literal));
            p_l->next=NULL;
            p_sf->num_lit++;//子句文字数加一
            if(p_s->elem==NULL)
            {
                p_s->elem=p_l;
            }
            else
            {
                p_lf->next=p_l;
            }
            p_lf=p_l;
            p_lf->pos=1;//文字设为正，以保证析取之后至少有一个为1
            p_lf->num=p_d->v_num;
            p_d=p_d->next;
        }
        while(p_df)//根据每个空格最多一个数字创建子句
        {
            p_d=p_df->next;
            while(p_d)
            {
                p_s=(Statement*)malloc(sizeof(Statement));//生成一个新子句
                p_s->next=NULL;
                S->num_st++;
                p_sf->next=p_s;
                p_sf=p_s;
                p_sf->num_lit=2;//每个子句只有两个文字以代表只有一个文字为真
                p_sf->elem=(Literal*)malloc(sizeof(Literal));
                p_sf->elem->num=p_df->v_num;
                p_sf->elem->pos=0;//两个文字只有一个为真，故都是负文字
                p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                p_sf->elem->next->num=p_d->v_num;
                p_sf->elem->next->pos=0;
                p_sf->elem->next->next=NULL;
                p_d=p_d->next;
            }
            p_df=p_df->next;
        }
    }

    //由每个数字在每行最多出现一次，最少出现一次 创建子句
    j=0;
    for(i=0; i<9; i++) //遍历每一行
    {
        x=j;//用于记录每一行的开始空格位置
        for(k=1; k<=9; k++) //遍历每个数字
        {
            int v[10];//用于储存在行的空格上每个数字可能出现位置的变元号
            v[0]=0;//首行用于存储数字在此行出现次数
            int a;//用于遍历v数字
            int b;
            a=1;
            j=x;
            while((holes[j].x==i)&&j<hole_num)//找到每个数字对应的空格出现位置保持相应变元号
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
            p_s=(Statement*)malloc(sizeof(Statement));//根据一个数字在一行内最少出现一次生成公式
            S->num_st++;//子句数加一
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
                p_lf->pos=1;//保证只有数字最少出现一次，故此子句的文字全为正
                p_lf->num=v[a];
            }
            for(a=1; a<=v[0]; a++) //根据一个数字在一行内最多出现一次生成公式
            {
                for(b=a+1; b<=v[0]; b++)
                {
                    p_s=(Statement*)malloc(sizeof(Statement));
                    S->num_st++;//子句数加一
                    p_s->num_lit=2;
                    p_s->next=NULL;
                    p_sf->next=p_s;
                    p_sf=p_s;
                    p_sf->elem=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->num=v[a];
                    p_sf->elem->pos=0;//两个文字只有一个为真，故都是负文字
                    p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->next->num=v[b];
                    p_sf->elem->next->pos=0;
                    p_sf->elem->next->next=NULL;
                }
            }
        }
    }

    //由每个数字在每列最多出现一次，最少出现一次 创建子句
    for(j=0; j<9; j++)
    {
        for(k=1; k<=9; k++) //遍历每个数字
        {
            int v[10];//用于储存在列的空格上每个数字可能出现位置的变元号
            v[0]=0;//首行用于存储数字在此列出现次数
            int a;//用于遍历v数字
            a=1;
            int b;
            for(i=0; i<hole_num; i++) //找到每个数字对应的空格出现位置保持相应变元号
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
            p_s=(Statement*)malloc(sizeof(Statement));//根据一个数字在一行内最少出现一次生成公式
            S->num_st++;//子句数加一
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
                p_lf->pos=1;//保证只有数字最少出现一次，故此子句的文字全为正
                p_lf->num=v[a];
            }
            for(a=1; a<=v[0]; a++) //根据一个数字在一行内最多出现一次生成公式
            {
                for(b=a+1; b<=v[0]; b++)
                {
                    p_s=(Statement*)malloc(sizeof(Statement));
                    S->num_st++;//子句数加一
                    p_s->num_lit=2;
                    p_s->next=NULL;
                    p_sf->next=p_s;
                    p_sf=p_s;
                    p_sf->elem=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->num=v[a];
                    p_sf->elem->pos=0;//两个文字只有一个为真，故都是负文字
                    p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->next->num=v[b];
                    p_sf->elem->next->pos=0;
                    p_sf->elem->next->next=NULL;
                }
            }
        }
    }
    //由每个数字在每个子宫内最多出现一次，最少出现一次 创建子句
    int place;//用于遍历宫
    for(place=0; place<9; place++)
    {
        int ub_x;//表示宫的上界
        int ub_y;
        int lb_x;//表示宫的下界
        int lb_y;
        lb_x=(place/3)*3;
        ub_x=(place/3+1)*3;
        switch (place)//确定当前宫对应的上下界
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
        for(k=1; k<=9; k++) //遍历每个数字
        {
            int v[10];//用于储存在列的空格上每个数字可能出现位置的变元号
            v[0]=0;//首行用于存储数字在此列出现次数
            int a;//用于辅助遍历
            int b;
            a=0;
            b=1;
            for(a=0; a<hole_num; a++)//找到每个数字对应的空格出现位置保持相应变元号
            {
                if((holes[a].x>=lb_x)&&(holes[a].x<ub_x)&&(holes[a].y>=lb_y)&&(holes[a].y<ub_y))//当空格在当前宫内时
                {
                    p_df=holes[a].elem;
                    while(p_df)//遍历空格中可能出现的数字
                    {
                        if(p_df->num==k)//如果恰为当前数字则计入数组
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
            p_s=(Statement*)malloc(sizeof(Statement));//根据一个数字在一行内最少出现一次生成公式
            S->num_st++;//子句数加一
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
                p_lf->pos=1;//保证只有数字最少出现一次，故此子句的文字全为正
                p_lf->num=v[a];
            }
            for(a=1; a<=v[0]; a++) //根据一个数字在一行内最多出现一次生成公式
            {
                for(b=a+1; b<=v[0]; b++)
                {
                    p_s=(Statement*)malloc(sizeof(Statement));
                    S->num_st++;//子句数加一
                    p_s->num_lit=2;
                    p_s->next=NULL;
                    p_sf->next=p_s;
                    p_sf=p_s;
                    p_sf->elem=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->num=v[a];
                    p_sf->elem->pos=0;//两个文字只有一个为真，故都是负文字
                    p_sf->elem->next=(Literal*)malloc(sizeof(Literal));
                    p_sf->elem->next->num=v[b];
                    p_sf->elem->next->pos=0;
                    p_sf->elem->next->next=NULL;
                }
            }
        }
    }

    //由变元数生成变元真值关系数组
    Varies=(int*)malloc((S->num_v+1)*sizeof(int));
    for(i=1; i<(S->num_v+1); i++)
    Varies[i]=-1;
    return Varies;
}

/*
*******************************
showSudResult()用于将cnf变元真值关系转化为数独的解并输出
输入为一组cnf变元真值关系
输出为数独的解
算法思想：输出数独元素，当此元素为0时，找到空格数组中对应的空格，遍历查看空格中那个数字对应的变元为真则输出此数字
*******************************
*/
void showSudResult(int* Varies,hole* holes,int(*sud)[9])
{
    int i;//用于遍历数独格局
    int j;
    int k;//用于遍历空格数组
    k=0;
    digtal* p;

    printf("\n******************************\n\n");
    printf("数独的解为：\n\n");
    printf("        -------------------\n");
    for(i=0; i<9; i++)
    {
        printf("\t|");
        for(j=0; j<9; j++)
        {
            if(sud[i][j]==0)//当此处为空时
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
