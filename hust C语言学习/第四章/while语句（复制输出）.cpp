#include <stdio.h>
int main(void)
{
	char c;
    printf("Input a text end of ctrl+z:\n"); //ctrl+z 等于输入一个 EOF 给getchar() 
    
    c=getchar();
    while(c!=EOF){
    	putchar(c);
    	c=getchar();                        //每次打印一个输入流中的字符 
	}
	return 0;
}
