#include <iostream>
int main()
{
    using namespace std;
    int a,x;
    cout<<"Enter a number:";
    cin>>a;
    cin.get();
    x=(a%3==0)&&((a%5==0)&&(a%10!=0));
    cout<<x;
    cin.get();
    return 0;
}
