#include <stdio.h>
int main()
{
    char ch;;
    scanf("%c",&ch);
    if(int(ch)>='0'&&int(ch)<='9')                   //Ҫ�Ƚ��ַ���ASCII���С��������Լ������ģ���int()���Ƚ� 
      printf("%c",ch);
    else if((int(ch)>='a'&&int(ch)<='f')||(int(ch)>='A'&&int(ch)<='F'))
      printf("%c",ch);
    else
      printf("%d",ch);
    return 0; 
}
