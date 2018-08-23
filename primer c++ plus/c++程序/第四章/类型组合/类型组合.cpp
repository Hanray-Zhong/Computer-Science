#include <iostream>

struct years_end
{
       int year;
};                                      //创建结构 

int main()
{
    using namespace std;
    years_end s01,s02,s03;              //给结构中加入成员 
    s01.year=1998;                      
    years_end* pa=&s02;                 //给第二个结构成员添加指针 
    pa->year=1999;
    years_end trio[3];                  //用结构创建一个数组，数组中的所有成员均符合该结构 
    trio[0].year=2003;                 
    cout<<trio->year<<endl;             //相当于trio[0].year,因为数组的名称也就是数组中第一个元素的指针，用箭头运算符 
    const years_end* arp[3]={&s01,&s02,&s03};          //建立一个指针数组，数组中所有的元素全部都是指针 
    cout<<arp[0]->year<<endl;
    const years_end** ppa=arp;         //给一个指针一个指针，运用** 
    const years_end** ppb=arp;
    cout<<(*ppa)->year<<endl;
    cout<<(*(ppb+1))->year<<endl;      //指针运算符，(ppb+1)即&s02 
    cin.get();
    return 0;
}
