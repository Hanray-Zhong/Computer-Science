#include <iostream>
int main()
{
    using namespace std;
    cout<<"����������(Ӣ��):________\b\b\b\b\b\b\b\b";
    int height;
    cin>>height;
    cin.get();
    const int x = 12;
    int y = height/x;
    int z = height%x;
    cout<<"������Ϊ��"<<y<<"Ӣ��"<<z<<"Ӣ��";
    cin.get();
    return 0;
} 
