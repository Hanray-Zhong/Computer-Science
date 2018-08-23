#include <iostream>
int main()
{
    using namespace std;
    double a;
    double b;
    cout<<"a number:______\b\b\b\b\b\b ";
    cin>>a;
    cin.get();
    cout<<"another number:______\b\b\b\b\b\b ";
    cin>>b;
    cin.get();
    
    cout<<"a+b= "<<a+b<<endl;
    cout<<"a-b= "<<a-b<<endl;
    cout<<"a*b= "<<a*b<<endl;
    cout<<"a/b= "<<a/b<<endl;
    cin.get();
    
    int c;
    int d;
    cout<<"输入一个整数：______\b\b\b\b\b\b";
    cin>>c;
    cin.get();
    cout<<"输入一个整数: ______\b\b\b\b\b\b";
    cin>>d;
    cin.get();
    
    cout<<"c%d= "<<c%d;                                               //% 运算符只支持整数 
    cin.get();
    return 0;
}
    
