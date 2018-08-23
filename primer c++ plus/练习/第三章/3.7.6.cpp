#include <iostream>
int main()
{
    using namespace std;
    cout<<"输入你的车程:        km\b\b\b\b\b\b\b\b\b\b";
    long km;
    cin>>km;
    cin.get();
    cout<<"输入你的总耗油量:        L\b\b\b\b\b\b\b\b\b";
    long L;
    cin>>L;
    cin.get();
    
    double x=double(L)/double(km);
    double y=x*100;
    cout<<"耗油量为："<<y<<"L/100km";
    cin.get();
    return 0;
}
