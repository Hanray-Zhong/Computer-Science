#include <iostream>
struct inflatable
{
       char name[20];
       float volume;
       double price;
};                                         //放在主函数前可以是该结构使以下所有函数使用 
                                           //若放在某函数中，则结构只在该函数中有用 
int main()
{
    using namespace std;
    inflatable guest=                      //将guest初始化 
    {
               "Glorious Gloria",
               1.88,
               29.99
    };
    
    inflatable pal=
    {
               "Audacious Arthur",
               3.12,
               32.99
    };
    
    cout<<"Expand your guest list with "<<guest.name;
    cout<<" and "<<pal.name<<"!\n";               //pal.name显示字符串，pal.price显示double，后缀即结构中的定义 
    cout<<"You can have both for $";
    cout<<guest.price+pal.price<<"!\n";
    cin.get();
    return 0;
}
