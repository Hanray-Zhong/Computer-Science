vvb#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20]="jaguar";
    string str1;                           //string类隐藏了数组性质 
    string str2="panther";
    
    cout<<"Enter a kind of feline:";
    cin>>charr1;
    cin.get();
    cout<<"Enter another kind of feline:";
    cin>>str1;
    cin.get();
    cout<<"Here are some feline:\n";
    cout<<charr1<<" "<<charr2<<" "<<str1<<" "<<str2<<endl;
    cout<<"The third letter in "<<charr2<<" is "<<charr2[2]<<endl;
    cout<<"The third letter in "<<str2<<" is "<<str2[2]<<endl;
    cin.get();
    return 0;
} 
