#include <iostream>
using namespace std;
void f(int);
int main()
{
    cout<<"Enter the number of the hours: ";
    int hours;
    cin>>hours;
    cin.get();
    cout<<"Enter the number os the minutes: ";
    int minutes;
    cin>>minutes;
    cin.get();
    cout << "Time: ";
    f(hours);
    cout<<":";
    f(minutes);
    cin.get();
    return 0;
}

void f(int n)
{
     cout<<n;
}
