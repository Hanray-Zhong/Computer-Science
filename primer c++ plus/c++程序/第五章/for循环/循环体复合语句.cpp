#include <iostream>
int main()
{
    using namespace std;
    cout<<"The amazing Accounto will sum and average five numbers for you.\n";
    cout<<"Enter five values:\n";
    double number;
    double sum=0.0;
    for(int i=1;i<=5;i++)
    {
            cout<<"Value "<<i<<":";
            cin>>number;
            cin.get();
            sum+=number;
    }
    cout<<"Five expuisite choices indeed!";
    cout<<"The sum to "<<sum<<endl;
    cout<<"and average to "<<sum/5<<endl;
    cin.get();
    return 0;
} 
