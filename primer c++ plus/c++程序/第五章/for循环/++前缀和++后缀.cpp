#include <iostream>
int main()
{
    using namespace std;
    int a=20;
    int b=20;
    cout<<"a   ="<<a<<":   b="<<b<<endl;
    cout<<"a++ ="<<a++<<": ++b"<<++b<<endl;        //++前缀表达式显示+1之后的值，++后缀表达式显示原值，然后再加1 
    cout<<"a   ="<<a<<":   b="<<b<<endl;
    cin.get();
    return 0;
} 
