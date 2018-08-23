#include <stdio.h> 
void butler(void);                  //声明自定义函数时要打分号 
int main(void)
{
	printf("I will summon the butler function.\n");
	butler();
	printf("Yes. Bring me some tea and writeable DVDs.\n");
}

void butler(void)
{
	printf("You rang, sir?\n");
}
