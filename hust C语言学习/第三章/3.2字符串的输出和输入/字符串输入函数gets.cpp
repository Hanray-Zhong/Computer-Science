#include <stdio.h>
int main()
{
     printf("What's your name?\n");
     char name[20];
     gets(name);                 //该输入流到"\n"为止，因此不需要在后面添加getchar() 
     printf("Hello!%s!",name);
     getchar();
     return 0;
}
