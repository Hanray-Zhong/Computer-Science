#include <iostream>

struct years_end
{
       int year;
};                                      //�����ṹ 

int main()
{
    using namespace std;
    years_end s01,s02,s03;              //���ṹ�м����Ա 
    s01.year=1998;                      
    years_end* pa=&s02;                 //���ڶ����ṹ��Ա���ָ�� 
    pa->year=1999;
    years_end trio[3];                  //�ýṹ����һ�����飬�����е����г�Ա�����ϸýṹ 
    trio[0].year=2003;                 
    cout<<trio->year<<endl;             //�൱��trio[0].year,��Ϊ���������Ҳ���������е�һ��Ԫ�ص�ָ�룬�ü�ͷ����� 
    const years_end* arp[3]={&s01,&s02,&s03};          //����һ��ָ�����飬���������е�Ԫ��ȫ������ָ�� 
    cout<<arp[0]->year<<endl;
    const years_end** ppa=arp;         //��һ��ָ��һ��ָ�룬����** 
    const years_end** ppb=arp;
    cout<<(*ppa)->year<<endl;
    cout<<(*(ppb+1))->year<<endl;      //ָ���������(ppb+1)��&s02 
    cin.get();
    return 0;
}
