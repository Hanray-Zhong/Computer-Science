#include <iostream>
double f(double);
int main()
{
    using namespace std;
    cout<<"Please enter a Celsius value: ";
    double C;
    cin>>C;
    cin.get();
    double F = f(C);
    cout<<C<<" degrees Celsius is "<<F<<" degrees Fahrenheit.";
    cin.get();
    return 0;
}

double f(double n)
{      
       int m =1.8*n+32.0;
       return m;
}
