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
    inflatable* ps=new inflatable;                      //对结构的指针，动态结构 
    
    cout<<"Enter name of inflatable item:";
    cin.get(ps->name,20);                               //指针不是名称，要使用->运算符来表示成员 
    cin.get();
    cout<<"Enter volume in cubic feet:";
    cin>>(*ps).volume;                                 //(*ps)相当于结构名，因此可以使用句点运算符来表示成员 
    cin.get();
    cout<<"Enter price:$";
    cin>>ps->price;
    cin.get();
    
    cout<<"Name:"<<ps->name<<endl;
    cout<<"Volume:"<<(*ps).volume<<endl;
    cout<<"Price:$"<<ps->price<<endl;
    
    cin.get();
    return 0;
}
