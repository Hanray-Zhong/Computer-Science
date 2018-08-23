#include <iostream>
int main()
{
    using namespace std;
    const int ArSize=20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout<<"Enter your name:\n";
    cin.getline(name,ArSize);                               //如果使用cin>>，在输入时出现了空白，则视为字符串终止，若要输入一个含空白的字符串
                                                        //使用对行的函数cin.getline()，cin.get()读取一行直到换行符 
    cout<<"Enter your favorite dessert:\n";
    cin.get(dessert,ArSize);                          //cin.get(要输入的数组，数组长度) 
    cin.get();                                        //注意：cin.get(...)输入后包含换行符，因此后面添加cin.get()来保证不牵连后面的程序 
    cout<<"I have some delicious "<<dessert<<" for you "
        <<name<<endl;
    cin.get();
    return 0;
}
