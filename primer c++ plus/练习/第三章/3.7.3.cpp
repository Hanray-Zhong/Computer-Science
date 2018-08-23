#include <iostream>
int main()
{
    using namespace std;
    cout<<"Enter a latitude in degrees, minutes, and seconds:\n"
        <<"First,enter the degrees: ";
    int x;
    cin>>x;
    cin.get();
    cout<<"Next,enter the minutes of arc: ";
    double y;
    cin>>y;
    cin.get();
    cout<<"Finally,enter the seconds of arc: ";
    double z;
    cin>>z;
    cin.get();
    double m = x + y/60 + z/3600;
    cout<<x<<" degrees,"<<y<<" minutes,"<<z<<" seconds="<<m<<" degrees.";
    cin.get();
    return 0;
}
