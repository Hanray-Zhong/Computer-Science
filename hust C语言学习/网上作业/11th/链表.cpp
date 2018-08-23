#include<stdio.h> 
#include<stdlib.h>
struct lianbiao
{
	int c;
	struct lianbiao *Next;
};
int main(void)
{
	struct lianbiao *head=NULL,*tail,*p;
	int i=1;
	head=(struct lianbiao *)malloc(sizeof(struct lianbiao));        //分配第一个节点 
	head->c=i;
	tail=head;
	while(tail->c!=10)
	{
		tail->Next=(struct lianbiao *)malloc(sizeof(struct lianbiao));
		tail=tail->Next;
		tail->c=++i;
	}
	p=head;
	while(p->c!=10)
	{
		printf("%d",p->c);
		p=p->Next;
	}
	return 0;
}
