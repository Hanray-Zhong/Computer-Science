#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    string first_name;
    string last_name;
    cout<<"What is your first name:";
    cin>>first_name;
    cin.get();
    cout<<"What is your last name:";
    cin>>last_name;
    cin.get();
    cout<<"Here's your information of a string:";
    first_name+=",";
    first_name+=last_name;
    cout<<first_name;
    cin.get();
    return 0;
}
