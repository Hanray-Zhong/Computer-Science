#include <stdio.h>;
int main()
{
    char c;
    int x1;
    unsigned x2;
    float y;
    char name[10];
    
    scanf("%c%d%u%f%s",&c,&x1,&x2,&y,name);
    getchar();                                        //��������У��س���Ȼ���������� 
    printf("%c\t%d\t%u\n%f\t%s",c,x1,x2,y,name);
    getchar();
    return 0;
}
