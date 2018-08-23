#include <cstring>
#include <iostream>
int main()
{
    using namespace std;
    char animal[20]="bear";
    const char* bird="wren";
    char* ps;                        //不初始化指针比较危险，建议初始化 
    
    cout<<animal<<" and "<<bird<<endl;
    
    cout<<"Enter a kind of animal:";
    cin>>animal;
    cin.get(); 
    
    ps=animal;                                //将animal赋给ps不会赋值字符串，而只是复制地址，ps和animal共用一个地址 
    cout<<ps<<"!\n";
    cout<<"Before using strcpy():\n";
    cout<<animal<<" at "<<(int*)animal<<endl;        //(int*)animal对于cout来说显示animal中的字符串的地址，而不是指针的地址 
    cout<<ps<<" at "<<(int*)ps<<endl;
    
    ps=new char[strlen(animal)+1];          // 要获得另一个副本，则需要另外找一个储存空间，因此为animal的大小加一（加上空字符） 
    strcpy(ps,animal);                      //将animal的字符串地址复制到新的ps指针处，即获得了另外一个animal副本 
    cout<<"After using strcpy():"<<endl;
    cout<<animal<<" at "<<(int*)animal<<endl;
    cout<<ps<<" at "<<(int*)ps<<endl;
    cin.get();
    return 0;
}
