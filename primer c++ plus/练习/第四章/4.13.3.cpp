#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char first_name[20];
    char last_name[20];
    char jd[2]=",";
    cout<<"Enter your first name:";
    cin>>first_name;
    cin.get();
    cout<<"Enter your last name:";
    cin>>last_name;
    cin.get();
    cout<<"Here's the information of a single string:";
    strcat(first_name,jd);
    strcat(first_name,last_name);
    cout<<first_name;
    cin.get();
    return 0;
}
