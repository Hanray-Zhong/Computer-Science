#include "head.h"
void main(void)
{
    long time_start;//��¼����ʼʱ��
    long time_end;//��¼�������ʱ��
    int choice;//��¼�û�ѡ��Ĺ���
    choice=0;


    printf("\n\n��ӭ��������SAT�����������Ϸ��\n\n");
    printf("�ڱ���Ϸ��\n");
    printf("��������ѡ��\n\n");
    printf("1��ͨ���ļ�����cnf��ʽ����֤���������\n\n");
    printf("2���������һ���������������\n\n");
    printf("------------------------------------\n");
    printf("ѡ����Ϸ����������Ӧ��š�1||2��:\n");
    scanf("%d",&choice);
    while(choice!=1&&choice!=2)
    {
        printf("��������ȷ����š�1��2����\n");
        printf("ѡ����Ϸ����������Ӧ���:\n");
        scanf("%d",&choice);
    }
    if(choice==1)
        SAT(time_start,time_end);
    else
        Sudoku();
}
