#include <iostream>
using namespace std;
void f(int);
void g(int);
int main()
{
    f(1);
    f(1); 
    g(1);
    g(1);
    cin.get();
    return 0;
}

void f(int n)
{
     cout<<"Three blind mice"<<endl;
}

void g(int n)
{
     cout<<"See how they run"<<endl;
}
