#include <iostream>
int main()
{
    using namespace std;
    int carrots;
    cout<<"请输入你有几层buff，并按下回车"<<endl;
    cin>>carrots;                                       //在C++中，cin>> 表示输入，但因为 int 只定义整数， 所以，只能输入整数，否则程序会弹出 
    cout<<"现在我再给你加一点";                         //cin<< =后需要添加语句“cin.get();”,读取输入***** 
    carrots=carrots+5;
    cout<<endl;
    cin.get(); 
    cout<<"请按回车显示你现在的buff数量";
    cin.get();
    cout<<carrots<<endl;
    cout<<"我多给你加了5层buff，感谢我吧"
        <<endl
        <<endl
        <<"按回车结束";                                //有利于在输出内容较多编程 
    cin.get();
    return 0;
}
