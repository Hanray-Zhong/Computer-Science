#include <stdio.h>
int main()
{
     printf("What's your name?\n");
     char name[20];
     gets(name);                 //����������"\n"Ϊֹ����˲���Ҫ�ں������getchar() 
     printf("Hello!%s!",name);
     getchar();
     return 0;
}
