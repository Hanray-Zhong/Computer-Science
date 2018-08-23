#include <stdio.h>
int main()
{
    char ch;;
    scanf("%c",&ch);
    if(int(ch)>='0'&&int(ch)<='9')                   //要比较字符的ASCII码大小，如果是自己命名的，用int()来比较 
      printf("%c",ch);
    else if((int(ch)>='a'&&int(ch)<='f')||(int(ch)>='A'&&int(ch)<='F'))
      printf("%c",ch);
    else
      printf("%d",ch);
    return 0; 
}
