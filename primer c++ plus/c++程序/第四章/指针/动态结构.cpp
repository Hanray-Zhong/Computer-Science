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
    inflatable* ps=new inflatable;                      //�Խṹ��ָ�룬��̬�ṹ 
    
    cout<<"Enter name of inflatable item:";
    cin.get(ps->name,20);                               //ָ�벻�����ƣ�Ҫʹ��->���������ʾ��Ա 
    cin.get();
    cout<<"Enter volume in cubic feet:";
    cin>>(*ps).volume;                                 //(*ps)�൱�ڽṹ������˿���ʹ�þ�����������ʾ��Ա 
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
