#include <stdio.h>


void main(void){
    typedef struct 
    {
        char name[10];
        char passWord[10];
    };
    
    
    int op=0;
    char[10] a;
    
    printf("\t\t....SHOPE  NAME....\n");
    printf("提示输入姓名\n");
    scanf("%s", name);
    printf("%s", name);
    printf("提示输入密码\n");

    while(op!=6){
        printf("1=查询商品信息,2=修改商品信息,3=计算推荐度,\n");
        printf("4=计算推荐度排名,5=输出全部商品信息,6=程序退出.\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                
            case 2:
                
            case 3:
                
            case 4:
                
            case 5:
                
            case 6:
                return;
            case 0:
                break;
        }
    }
    
}