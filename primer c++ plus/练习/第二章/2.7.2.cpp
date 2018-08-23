#include <iostream>
double f(double);
int main()
{
    using namespace std;
    cout<<"输入一个以long为单位的距离：";
    double x;
    cin>>x;
    cin.get();
    double y = f(x);
    cout<<x<<"long="<<y<<"码";
    cin.get();
    return 0;
}

double f(double n)
{
       return 220*n;
}
     
