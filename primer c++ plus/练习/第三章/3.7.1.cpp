#include <iostream>
int main()
{
    using namespace std;
    cout<<"输入你的身高(英寸):________\b\b\b\b\b\b\b\b";
    int height;
    cin>>height;
    cin.get();
    const int x = 12;
    int y = height/x;
    int z = height%x;
    cout<<"你的身高为："<<y<<"英尺"<<z<<"英寸";
    cin.get();
    return 0;
} 
