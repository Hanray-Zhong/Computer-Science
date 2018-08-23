#include <iostream>
#define ZERO 0                                                   //定义 ZERO 为 0  
#include <climits>
int main()
{
    using namespace std;
    short sam = SHRT_MAX;                                       //short 表示含正含负 
    unsigned short sue = sam;                                    //unsigned short 表示只有正 
    
    //以下展示超出限值的后果 
    cout << "Sam has "<< sam << " dollars and sue has " << sue <<" dollars.";
    cin.get();
    cout << "add $1 to each one." ;
    cin.get();
    sam = sam + 1;
    sue = sue + 1;
    cout << "Now,Sam has "<<sam<<" dollars and sue has "<<sue<<" dollars.";
    cin.get();
    sam = ZERO;
    sue = ZERO;
    cout<<"Sam has "<<sam<<" dollars and sue has "<<sue<<" dollars"<<endl;
    cout<<"Take $1 from each one";
    cin.get();
    sam = sam - 1;
    sue = sue - 1;
    cout<<"Now,Sam has "<<sam<<" dollars and sue has "<<sue<<" dollars.";
    cin.get();
    return 0;
} 
