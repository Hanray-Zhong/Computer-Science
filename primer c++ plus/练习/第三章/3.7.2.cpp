#include <iostream>
int main()
{
    using namespace std;
    cout<<"������ߣ�Ӣ��____\b\b\b\b";
    int x;
    cin>>x;
    cout<<"          Ӣ��____\b\b\b\b";
    int y;
    cin>>y;
    cin.get();
    cout<<"��������(��)��____\b\b\b\b";
    int z;
    cin>>z;
    cin.get(); 
    const int c1 = 12;
    const double c2 = 0.0254;
    const double c3 = 2.2;
    double m = (x*c1+y)*c2;
    double n = z/c3; 
    cout<<"BMI="<<n/(m*m)<<endl;
    cin.get();
    return 0;
}

