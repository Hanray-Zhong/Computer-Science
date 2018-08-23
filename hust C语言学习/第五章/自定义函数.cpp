#include <stdio.h>
#include <stdlib.h>
#include <time.h>             //调用系统的时间
#define MAX_NUMBER 1000

int Getnumber(void);
void Guessnumber(int);             //自定义函数 

int main()
{
	char command;
	int magic;
	printf("This is a guessing game\n\n");
	
	srand(time(NULL));              //用系统时间初始化随机数生成器
	do
	{
		magic=Getnumber();
		Guessnumber(magic);
		printf("Play again?(Y/N)");
		scanf("%1s",&command);
	 } while (command=='Y'||command=='y');
	
	return 0;
}

/****************自定义函数****************/
int Getnumber(void)
{
	int x;
	printf("A magic number between 1 and %d has been chosen.\n\a",MAX_NUMBER);
	
	x=rand();                 //产生随机数
	x=x%MAX_NUMBER + 1;       //限制该数字在 1 到 MAX_NUMBER 上 
	return(x);
} 
 
void Guessnumber(int x)
{
 	int guess,counter=0;
 	for(;;)                             //无限循环语句 
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
