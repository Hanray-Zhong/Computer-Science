#include <iostream>
struct inflatable
{
       char name[20];
       float volume;
       double price;
};                                         //����������ǰ�����Ǹýṹʹ�������к���ʹ�� 
                                           //������ĳ�����У���ṹֻ�ڸú��������� 
int main()
{
    using namespace std;
    inflatable guest=                      //��guest��ʼ�� 
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
    cout<<" and "<<pal.name<<"!\n";               //pal.name��ʾ�ַ�����pal.price��ʾdouble����׺���ṹ�еĶ��� 
    cout<<"You can have both for $";
    cout<<guest.price+pal.price<<"!\n";
    cin.get();
    return 0;
}
