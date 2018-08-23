#include<stdio.h>
#include<stdlib.h>
struct student
{
	int number;
	char name[9];
	int g1;
	int g2;
	int g3;
	int g4;
	struct student *prior;
	struct student *next;
};
void make_list(struct student **);
int main(void)
{
	struct student *head=NULL,*p;
	int i,j;
	make_list(&head);
	p=head->next;
	for(i=1;i<=4;i++)
	{
		printf("第%d位同学：\n",i);
		printf("学号：%d\n名字：%s\n英语成绩：%d\n高等数学：%d\n普通物理：%d\nC语言程序设计：%d\n",p->number,p->name,p->g1,p->g2,p->g3,p->g4);
		p=p->next;
		printf("\n");
	}
	printf("需要修改数据吗？\n(Y/N)");
	char injust;
	scanf("%c",&injust);
	getchar();
	while(injust=='Y')
	{
		printf("输入你想要更改的学生顺序:");
		scanf("%d",&j);
		getchar();
		p=head->next;
		for(i=1;i<j;i++) p=p->next;
		printf("请输入你要修改的数据：\n1-学号\n2-名字\n3-英语\n4-高等数学\n5-普通物理\n6-C语言程序设计\n");
		scanf("%d",&j);
		getchar();
		switch(j)
		{
			case 1:printf("重新输入数据：");
			       scanf("%d",p->number);
			       getchar();
			       break;
		    case 2:printf("重新输入数据：");
			       scanf("%s",p->name);
			       getchar();
			       break;
		    case 3:printf("重新输入数据：");
			       scanf("%d",p->g1);
			       getchar();
			       break;
		    case 4:printf("重新输入数据：");
			       scanf("%d",p->g2);
			       getchar();
			       break;
		    case 5:printf("重新输入数据：");
			       scanf("%d",p->g3);
			       getchar();
			       break;
		    case 6:printf("重新输入数据：");
			       scanf("%d",p->g4);
			       getchar();
			       break;
		} 
		printf("还需要修改数据吗？\n(Y/N)");
		scanf("%c",&injust);
		getchar();
	}
	printf("\n");
	p=head->next;
	for(i=1;i<=4;i++)
	{
		double ave;
		ave=(p->g1+p->g2+p->g3+p->g4)/4.0;
		printf("第%d位同学：\n",i);
		printf("学号：%d\n名字：%s\n英语成绩：%d\n高等数学：%d\n普通物理：%d\nC语言程序设计：%d\n",\
p->number,p->name,p->g1,p->g2,p->g3,p->g4);                                  //不知道为什么不能按照浮点输出
        printf("平均成绩：%.2lf",ave); 
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
	*headp=loc_head;
	tail=loc_head;
	for(i;i<=4;i++)
	{
		tail->next=(struct student *)malloc(sizeof(struct student));
		tail->next->prior=tail;
		tail=tail->next;
		printf("请输入第%d位同学的学号，名字，英语，高等数学，普通物理，C语言程序设计的成绩：\n",i);
	    scanf("%d %s %d %d %d %d",&tail->number,tail->name,&tail->g1,&tail->g2,&tail->g3,&tail->g4);
	    getchar();
    }
    tail->next=NULL;
}
