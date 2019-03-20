#include "head.h"
/*
*******************************
SAT()����ͨ���ļ�����cnf��ʽ����֤��������ԣ�
����Ϊ����ʼ�ͽ���ʱ��
*******************************
*/
void SAT(long time_start,long time_end)
{
    system("cls");
    FILE* fp;//���ڴ�һ���ļ�
    char filename[100];//�����ļ���
    Formula S;//���ڱ������ɵĹ�ʽ
    int SAT;//cnf�������Ա�ǣ�0Ϊ�����㣬1Ϊ����
    int i;
    int* Varies;//���ڱ����Ԫ��Ϣ��0Ϊ�٣�1Ϊ�棬-1Ϊδ֪
    //S��ʼ��
    S.sta=-1;//�Ƿ��������
    S.num_st=0;//�Ӿ���Ϊ0
    S.root=NULL;//���κ��Ӿ�
    //Varies��ʼ��
    Varies=NULL;


    printf("\n\n\n���ڿ�ʼͨ���ļ�����cnf��ʽ����֤���������\n\n");
    printf("------------------------------------\n\n\n");


    /*ͨ���ļ�����cnf��ʽ*/
    printf("�����뽫Ҫ���ļ����ļ�����\n");
    scanf("%s",filename);
    fp=fopen(filename,"r");//��cnf�ļ���ֻ����ʽ��
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
    }
    cnfParser(fp,&S);//����cnf��ʽ
    fclose(fp);


    /*��֤cnf��ʽ�Ŀ�������*/
    Varies=(int*)malloc((S.num_v+1)*sizeof(int));
    for(i=1;i<=S.num_v;i++)
    {
        Varies[i]=-1;
    }
    time_start=clock();//��¼����ʼʱ��
    SAT=solver(&S,Varies);


    /*�����֤���*/
    time_end=clock();//��¼�������ʱ��
    //���ļ�����Ϊ��.res��β
    int str_length;
    str_length=strlen(filename);
    char str[]=".res";
    strcpy(filename+str_length-4,str);
    fp=fopen(filename,"w");//��һ��������ͬ����res�ļ�
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
    }
    //�����������
    printf("s %d\n",SAT);
    //���ļ���д���������
    char c='s';
    fprintf(fp,"%c\t",c);
    fprintf(fp,"%d\n",SAT);
    //�ļ�������ʱ�����һ����ֵ�������ļ���д��һ����ֵ
    if(SAT==1)
    {
        c='v';
        printf("%c ",c);
        fprintf(fp,"%c\t",c);
        for(i=1;i<=S.num_v;i++)
        {
            //����valueֵ�ж��������valueΪ1ʱ���Ϊ������valueΪ0��-1ʱ���Ϊ��
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
    //�����������ʱ��
    long k;
    k=time_end-time_start;
    c='t';
    printf("%c %ld",c,k);
    fprintf(fp,"%c\t",c);
    fprintf(fp,"%ld",k);
    fclose(fp);
}
