//创建变量，变量的变化，cout 的新作用 


#include <iostream>
int main()
{
    using namespace std;
    
    int carrots;                                     //定义一个叫做 carrots 的变量，将一个整数储存入carrots中 
    
    carrots=25;                                     //令该变量为 25 
    cin.get();
    cout << "I have " << carrots                    //cout 后可以输出变量，而不是字符串 
    << " carrots";     // 
    cout << endl;
    carrots=carrots-1;                          //变化变量 
    cout << "I eat one." << endl;
    cout << "Now,I have " << carrots << " carrots";
    cin.get();
    return 0;
}
     
