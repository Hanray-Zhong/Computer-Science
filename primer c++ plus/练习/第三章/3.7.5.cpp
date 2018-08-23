#include <iostream>
int main()
{
    using namespace std;
    cout<<"Enter the world's population: ";
    long long a;
    cin>>a;
    cin.get();
    cout<<"Enter the population of the US: ";
    long long b;
    cin>>b;
    cin.get();
    double A=a;
    double B=b;
    double m=B/A;
    cout<<"The population of the US is "<<m*100<<"% of the world population";
    cin.get();
    return 0;
}
