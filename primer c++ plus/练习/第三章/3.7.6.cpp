#include <iostream>
int main()
{
    using namespace std;
    cout<<"������ĳ���:        km\b\b\b\b\b\b\b\b\b\b";
    long km;
    cin>>km;
    cin.get();
    cout<<"��������ܺ�����:        L\b\b\b\b\b\b\b\b\b";
    long L;
    cin>>L;
    cin.get();
    
    double x=double(L)/double(km);
    double y=x*100;
    cout<<"������Ϊ��"<<y<<"L/100km";
    cin.get();
    return 0;
}
