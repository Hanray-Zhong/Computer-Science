#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int number;
	char name[9];
	int g1;
	int g2;
	int g3;
	int g4;
	struct student *next;
};
void make_list(struct student **);
int main(void)
{
	struct student *head=NULL,*p;
	int i,j,t;
	double ave[4];
	make_list(&head);
	p=head;
	for(i=1;i<=4;i++)
	{
		printf("��%dλͬѧ��\n",i);
		printf("ѧ�ţ�%d\n���֣�%s\nӢ��ɼ���%d\n�ߵ���ѧ��%d\n��ͨ����%d\nC���Գ�����ƣ�%d\n",p->number,p->name,p->g1,p->g2,p->g3,p->g4);
		p=p->next;
		printf("\n");
	}
	printf("*************************************\n��Ҫ�޸�������\n(Y/N)");
	char injust;
	scanf("%c",&injust);
	getchar();
	while(injust=='Y')
	{
		printf("��������Ҫ���ĵ�ѧ��˳��:");
		scanf("%d",&j);
		getchar();
		p=head;
		for(i=1;i<j;i++) p=p->next;
		printf("��������Ҫ�޸ĵ����ݣ�\n1-ѧ��\n2-����\n3-Ӣ��\n4-�ߵ���ѧ\n5-��ͨ����\n6-C���Գ������\n");
		scanf("%d",&j);
		getchar();
		switch(j)
		{
			case 1:printf("�����������ݣ�");
			       scanf("%d",p->number);
			       getchar();
			       break;
		    case 2:printf("�����������ݣ�");
			       scanf("%s",p->name);
			       getchar();
			       break;
		    case 3:printf("�����������ݣ�");
			       scanf("%d",p->g1);
			       getchar();
			       break;
		    case 4:printf("�����������ݣ�");
			       scanf("%d",p->g2);
			       getchar();
			       break;
		    case 5:printf("�����������ݣ�");
			       scanf("%d",p->g3);
			       getchar();
			       break;
		    case 6:printf("�����������ݣ�");
			       scanf("%d",p->g4);
			       getchar();
			       break;
		} 
		printf("*************************************\n����Ҫ�޸�������\n(Y/N)");
		scanf("%c",&injust);
		getchar();
	}
	printf("\n");
	p=head;
	for(i=1;i<=4;i++)
	{
		ave[i]=(p->g1+p->g2+p->g3+p->g4)/4.0;
		p=p->next;
	}
	j=1;
	while(j<=4)                      //ð�ݷ����� 
	{
		for(i=1;i<=3;i++)
		{
			if(ave[i]<=ave[i+1])
		    {
	            int x;
	            char y[9];
	            double z;
	            p=head;
		        for(t=1;t<i;t++) p=p->next;
	            x=p->number,p->number=p->next->number,p->next->number=x;
	            strcpy(y,p->name),strcpy(p->name,p->next->name),strcpy(p->next->name,y);
	            x=p->g1,p->g1=p->next->g1,p->next->g1=x;
	            x=p->g2,p->g2=p->next->g2,p->next->g2=x;
	            x=p->g3,p->g3=p->next->g3,p->next->g3=x;
	            x=p->g4,p->g4=p->next->g4,p->next->g4=x;
	            z=ave[i],ave[i]=ave[i+1],ave[i+1]=z;                                 //���������� 
            }
		}
	    j++;
	}
	p=head;
	printf("*************************************\n��ƽ��������\n\n");
	for(i=1;i<=4;i++)
	{
		printf("��%dλͬѧ��\n",i);
		printf("ѧ�ţ�%d\n���֣�%s\nӢ��ɼ���%d\n�ߵ���ѧ��%d\n��ͨ����%d\nC���Գ�����ƣ�%d\n",\
p->number,p->name,p->g1,p->g2,p->g3,p->g4);                                  //��֪��Ϊʲô���ܰ��ո������
        printf("ƽ���ɼ���%.2lf\n",ave[i]); 
		p=p->next;
		printf("\n");
	}
	getchar();
	return 0;
} 

void make_list(struct student **headp)
{
	struct student *loc_head,*tail;
	int i=1;
	loc_head = (struct student *)malloc(sizeof(struct student));
	printf("�������%dλͬѧ��ѧ�ţ����֣�Ӣ��ߵ���ѧ����ͨ����C���Գ�����Ƶĳɼ���\n",i++);
	scanf("%d %s %d %d %d %d",&loc_head->number,loc_head->name,&loc_head->g1,&loc_head->g2,&loc_head->g3,&loc_head->g4);
	getchar();
	tail=loc_head;
	for(i;i<=4;i++)
	{
		tail->next=(struct student *)malloc(sizeof(struct student));
		tail=tail->next;
		printf("�������%dλͬѧ��ѧ�ţ����֣�Ӣ��ߵ���ѧ����ͨ����C���Գ�����Ƶĳɼ���\n",i);
	    scanf("%d %s %d %d %d %d",&tail->number,tail->name,&tail->g1,&tail->g2,&tail->g3,&tail->g4);
	    getchar();
    }
    tail->next=NULL;
    *headp=loc_head;
}
