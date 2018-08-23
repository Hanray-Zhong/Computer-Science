#include <iostream>
double f(double);
int main()
{
    using namespace std;
    cout << "Enter the number of the light years: ";
    double x;
    cin >> x;
    cin.get();
    double y = f(x);
    cout << x <<" light years= "<<y<<" astronomical units.";
    cin.get();
    return 0;
}

double f(double n)
{
       return 63240*n;
}
