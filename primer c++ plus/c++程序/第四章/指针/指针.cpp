#include <iostream>
int main()
{
    using namespace std;
    int donuts=6;
    double cups=4.5;
    
    cout<<"donuts value="<<donuts;
    cout<<" and donuts address="<<&donuts<<endl;        //�����&ָ�������Ĵ���λ��  
    cout<<"cups value="<<cups
        <<" and cups address="<<&cups<<endl;
    cin.get();
    
    cout<<endl;
    
    int updates=6;                 
    int* p_updates;                          //*�������ʾ��ĳ��ַ��ʾ��ֵ��ʾ���� ������ǰ��Ҫ�ȶ��壬*ֻ������ָ�� 
    p_updates=&updates;                      //Ҳ�ɽ�������дΪ��int* p_updates=&updates 
    
    cout<<"Values:updates="<<updates;
    cout<<", *p_updates="<<*p_updates<<endl;
    
    cout<<"Addresses:&updates="<<&updates;
    cout<<", p_updates="<<p_updates<<endl;
    
    cout<<"*p_updates=*p_updates+1,";               //*p_updates��updates�ǵȼ۵� ,��&��* ��Ϊ 
    *p_updates=*p_updates+1;                       //���޸�*.....ʱ��Ҳ���޸�.....��ָ��ֵ 
    cout<<"Now,updates="<<updates<<endl;
    
    cin.get();
    return 0;
    
}    
