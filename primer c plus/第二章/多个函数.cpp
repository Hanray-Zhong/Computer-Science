#include <stdio.h> 
void butler(void);                  //�����Զ��庯��ʱҪ��ֺ� 
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
