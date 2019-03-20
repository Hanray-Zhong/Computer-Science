#include "head.h"
/*
*******************************
SAT()用于通过文件生成cnf范式并验证其可满足性，
输入为程序开始和结束时间
*******************************
*/
void SAT(long time_start,long time_end)
{
    system("cls");
    FILE* fp;//用于打开一个文件
    char filename[100];//保存文件名
    Formula S;//用于保存生成的公式
    int SAT;//cnf可满足性标记，0为不满足，1为满足
    int i;
    int* Varies;//用于保存变元信息，0为假，1为真，-1为未知
    //S初始化
    S.sta=-1;//是否满足待定
    S.num_st=0;//子句数为0
    S.root=NULL;//无任何子句
    //Varies初始化
    Varies=NULL;


    printf("\n\n\n现在开始通过文件生成cnf范式并验证其可满足性\n\n");
    printf("------------------------------------\n\n\n");


    /*通过文件生成cnf公式*/
    printf("请输入将要打开文件的文件名：\n");
    scanf("%s",filename);
    fp=fopen(filename,"r");//将cnf文件以只读形式打开
    if(!fp)
    {
        printf("文件打开失败！\n");
    }
    cnfParser(fp,&S);//生成cnf公式
    fclose(fp);


    /*验证cnf范式的可满足性*/
    Varies=(int*)malloc((S.num_v+1)*sizeof(int));
    for(i=1;i<=S.num_v;i++)
    {
        Varies[i]=-1;
    }
    time_start=clock();//记录程序开始时间
    SAT=solver(&S,Varies);


    /*输出验证结果*/
    time_end=clock();//记录程序结束时间
    //将文件名改为以.res结尾
    int str_length;
    str_length=strlen(filename);
    char str[]=".res";
    strcpy(filename+str_length-4,str);
    fp=fopen(filename,"w");//打开一个与算例同名的res文件
    if(!fp)
    {
        printf("文件打开失败！\n");
    }
    //输出可满足性
    printf("s %d\n",SAT);
    //向文件中写入可满足性
    char c='s';
    fprintf(fp,"%c\t",c);
    fprintf(fp,"%d\n",SAT);
    //文件可满足时，输出一组真值，并向文件中写入一组真值
    if(SAT==1)
    {
        c='v';
        printf("%c ",c);
        fprintf(fp,"%c\t",c);
        for(i=1;i<=S.num_v;i++)
        {
            //根据value值判断输出，当value为1时输出为正，当value为0或-1时输出为负
            if(Varies[i])
            {
                printf("%d ",i);
                fprintf(fp,"%d ",i);
            }
            else
            {
                printf("-%d ",i);
                int k=-i;
                fprintf(fp,"%d ",k);
            }
        }
        printf("\n");
        fprintf(fp,"\n");
    }
    //输出程序运行时间
    long k;
    k=time_end-time_start;
    c='t';
    printf("%c %ld",c,k);
    fprintf(fp,"%c\t",c);
    fprintf(fp,"%ld",k);
    fclose(fp);
}
