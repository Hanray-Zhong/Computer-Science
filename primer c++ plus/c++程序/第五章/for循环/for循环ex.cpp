#include <iostream>
int main()
{
    using namespace std; 
    int limit;
    cout<<"Enter the number of the limit:\n";
    cin>>limit;              //如果此时输入的是0，则在检测表达式中直接为false，直接退出，i=0 
    cin.get();
    int i;
    for(i=limit;i;i--)      //在检测表达式中如果只有i，则当i等于0时退出循环 
       cout<<"i="<<i<<endl;
    cout<<"Done now that i="<<i<<endl;
    cin.get();
    return 0;
} 
