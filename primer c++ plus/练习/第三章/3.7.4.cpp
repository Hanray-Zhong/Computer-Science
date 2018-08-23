#include <iostream>
int main()
{
    using namespace std;
    cout<<"Enter the number of seconds: ";
    long long all_seconds;
    cin>>all_seconds;
    cin.get();
    int days=all_seconds/(24*60*60);
    int a=all_seconds%(24*60*60);
    int hours=a/3600;
    int b=a%3600;
    int minutes=b/60;
    int seconds=b%60;
    cout<<all_seconds<<" seconds="<<days<<" days "<<hours<<" hours "<<minutes<<" minutes "<<seconds<<" seconds";
    cin.get();
    return 0;
}
