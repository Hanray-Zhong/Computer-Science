#include <iostream>
int main()
{
    using namespace std;
    int donuts=6;
    double cups=4.5;
    
    cout<<"donuts value="<<donuts;
    cout<<" and donuts address="<<&donuts<<endl;        //运算符&指出变量的储存位置  
    cout<<"cups value="<<cups
        <<" and cups address="<<&cups<<endl;
    cin.get();
    
    cout<<endl;
    
    int updates=6;                 
    int* p_updates;                          //*运算符表示将某地址表示的值显示出来 ，运用前需要先定义，*只能运算指针 
    p_updates=&updates;                      //也可将这两行写为：int* p_updates=&updates 
    
    cout<<"Values:updates="<<updates;
    cout<<", *p_updates="<<*p_updates<<endl;
    
    cout<<"Addresses:&updates="<<&updates;
    cout<<", p_updates="<<p_updates<<endl;
    
    cout<<"*p_updates=*p_updates+1,";               //*p_updates与updates是等价的 ,即&与* 互为 
    *p_updates=*p_updates+1;                       //当修改*.....时，也会修改.....的指向值 
    cout<<"Now,updates="<<updates<<endl;
    
    cin.get();
    return 0;
    
}    
