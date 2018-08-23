#include <iostream>
int main()
{
    using namespace std;
    char ch;
    
    cout<<"What's your name?"<<endl;
    cin>>ch;                                       //输入 M 后，cin 先将 M 转化为字符字面值77 
    cin.get();
    cout<<"Hello, Mr."<<ch<<" .";                  //cout 再将77转化为 M 输出 
    cin.get(); 
    return 0;
}
