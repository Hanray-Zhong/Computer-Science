#include <iostream>
int main()
{
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout<<"字符 "<<ch<<" 的编码为："<<i<<endl;       //char，cout显示字符 ，int，cout显示整数 
    
    cout<<"在字符编码上加1"<<endl;
    ch = ch + 1;
    i = ch;
    cout<<"字符 "<<ch<<" 的编码为："<<i<<endl;
    
    cout<<"要展示 编码 代表的 字符 用函数cout.put(): ";
    cout.put(ch);
    
    // 如果在cout.put()中输入 '！',则为直接打印字符 ！ 
    //如果是 cout<<'!' 则为显示 ！ 的字符字面值 
    cout.put('!');
    
    cin.get();
    return 0;
} 
