#include <stdio.h>
int main(void)
{
	char c;
    printf("Input a text end of ctrl+z:\n"); //ctrl+z ��������һ�� EOF ��getchar() 
    
    c=getchar();
    while(c!=EOF){
    	putchar(c);
    	c=getchar();                        //ÿ�δ�ӡһ���������е��ַ� 
	}
	return 0;
}
