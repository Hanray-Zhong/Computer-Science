#include <iostream>
struct inflatable
{
       char name[20];
       float volume;
       double price;
};
int main()
{
       using namespace std;
       inflatable guests[2]=                  //创建一个数组，全是该结构，并且用以下语言初始化 
       {
                 {"Bambi",0.5,21.99},
                 {"Godzilla",2000,565.99}
       };
       
       cout<<"The guests "<<guests[0].name<<" and "<<guests[1].name    //其使用和数组十分类似 
           <<endl<<"have a combined volume of "
           <<guests[0].volume+guests[1].volume<<" cubic feet.\n";
       cin.get();
       return 0;
}
