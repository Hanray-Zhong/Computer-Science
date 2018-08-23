#include <iostream>
int main()
{
    using namespace std;
    cout<<"Enter an integer:";
    int by;
    cin>>by;
    cin.get();
    cout<<"Counting by "<<by<<"s:\n";
    for(int i=0;i<100;i=i+by)                //步长可自由选择i=i+by,还可以用乘法和除法 ，i=i+by等价于i+=by 
        cout<<i<<endl;
    cin.get();
    return 0;
}
