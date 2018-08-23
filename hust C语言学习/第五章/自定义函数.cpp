#include <stdio.h>
#include <stdlib.h>
#include <time.h>             //����ϵͳ��ʱ��
#define MAX_NUMBER 1000

int Getnumber(void);
void Guessnumber(int);             //�Զ��庯�� 

int main()
{
	char command;
	int magic;
	printf("This is a guessing game\n\n");
	
	srand(time(NULL));              //��ϵͳʱ���ʼ�������������
	do
	{
		magic=Getnumber();
		Guessnumber(magic);
		printf("Play again?(Y/N)");
		scanf("%1s",&command);
	 } while (command=='Y'||command=='y');
	
	return 0;
}

/****************�Զ��庯��****************/
int Getnumber(void)
{
	int x;
	printf("A magic number between 1 and %d has been chosen.\n\a",MAX_NUMBER);
	
	x=rand();                 //���������
	x=x%MAX_NUMBER + 1;       //���Ƹ������� 1 �� MAX_NUMBER �� 
	return(x);
} 
 
void Guessnumber(int x)
{
 	int guess,counter=0;
 	for(;;)                             //����ѭ����� 
 	{
 		printf("guess it:");
 		scanf("%d",&guess);
 		counter++;
 		if(guess==x)
 		{
 			printf("You guess the right number by %d times!",counter);
 			return;
		 }
		else if(guess<x)
		    printf("Too low.Try again!\n");
		else 
		    printf("Too high.Try again!\n");
	 }
}
