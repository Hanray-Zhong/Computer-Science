#include <iostream>
double f(double);
int main()
{
    using namespace std;
    cout<<"����һ����longΪ��λ�ľ��룺";
    double x;
    cin>>x;
    cin.get();
    double y = f(x);
    cout<<x<<"long="<<y<<"��";
    cin.get();
    return 0;
}

double f(double n)
{
       return 220*n;
}
     
