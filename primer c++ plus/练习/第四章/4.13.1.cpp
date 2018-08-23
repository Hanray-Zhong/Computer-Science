#include <iostream>
int main()
{
    using namespace std;
    cout<<"What is your first name?";
    string a;
    getline(cin,a);
    cout<<"What is your last name?";
    string b;
    cin>>b;
    cin.get();
    cout<<"What letter grade do you deserve?A,B,C,D,E,F?";
    char c;
    cin>>c;
    cin.get();
    cout<<"What is your age?";
    int d;
    cin>>d;
    cin.get();
    cout<<"Name:"<<b<<","<<a<<endl
        <<"Grade:"<<char(c+1)<<endl                      //将字母往上调 ，直接加一 
        <<"Age:"<<d<<endl;
    cin.get();
    return 0;
}
