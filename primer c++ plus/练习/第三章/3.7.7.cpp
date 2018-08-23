#include <iostream>
int main()
{
    using namespace std;
    cout<<"输入欧洲式100km耗油量:        L\b\b\b\b\b\b\b\b\b";
    double x;
    cin>>x;
    cin.get();
    double y=(62.14*3.875)/x;
    cout<<"美式耗油量为："<<y<<"mpg";
    cin.get();
    return 0;
}
    
    
