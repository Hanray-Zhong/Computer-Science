#include <iostream>
int f(int);
int main()
{
    using namespace std;
    int stone;
    cout<<"enter the weight in stone: ";
    cin>>stone;
    cin.get();
    int pounds = f(stone);                               //有返还值，所以可以这样表达 
    cout<<stone<<"stone="<<pounds<<"pounds";
    cin.get();
    return 0;
}

int f(int n)
{
    return 14*n;
}
