#include <iostream>
int main()
{
    using namespace std;
    int a,b,c;
    
    a=19.99+11.99;                                          //19.99+11.99=31.98，int省去小数得31 
    b=(int)19.99+(int)11.99;                                //int(19.99)=19,int(11.99)=11,19+11=30 
    c=int(19.99)+int(11.99);                                //所以a=31，b=30，c=30 
    
    cout<<"a="<<a<<endl<<"b="<<b<<endl<<"c="<<c;
    cin.get();
    
    char ch = 'Z';
    cout<<"The code for "<<ch<<" is "<<int(ch)<<endl;          //int(ch)=90，为数 
    cout<<"Yes,the code is "<<static_cast<int>(ch)<<endl;      //static_cast<>()强制转换符 
    cin.get();
    return 0;
}
