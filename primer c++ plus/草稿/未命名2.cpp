#include <iostream>
int main()
{
    using namespace std;
    enum spectrum{red,orange,yellow,green,blue,qingse,zise};
    spectrum band;
    band=red;
    spectrum x=band;
    cout<<x<<endl;
    int color=blue;
    cout<<color<<endl;
    color=red+3;
    cout<<color<<endl;
    cin.get();
    return 0;
}
