#include <iostream>                          // 将iostream（输入输出流）文件的内容添加 ，60-[使用cin和cout进行输入和输出的程序必须使用  
int main()                                   // 函数头--作为C++与windows的接口 
{                                            // 函数体的开头
 
    using namespace std;                     // 定义于一个名为std的名称空间中，namespace是指标识符的各种可见范围,使用该名称空间使iostream对
                                             // 该程序有效（以后再考虑），有利于区分不同版本的函数
                                             //例如该函数count(),实际上为 std::count，endl为 std::endl
                                             //因此，可以省略using语句，将省略的"std::"补上，等价
                                             //另外，"using namespace std"是对所有std名称空间的定义都可用
                                             //如果要只用几个，可输入"using std::cout  std::cin  std::endl",但其他的iostream指令无法使用 
    
    cin.get();                               //按下回车 执行下一条命令，并将光标移至下一行 
    
    cout << "welcome to the world of C++.";  //messsage   不要""亦可 
                                             //由["......"]为字符串，<<表示将"....."字符串发送给cout，cout用来显示字符串，数字，单个字符等 
    
    cout << endl;                            //使光标移到下一行 
    
    cin.get();                               //按下回车 执行下一条命令  
    cout << "come up and C++ me some time."; //message,too
    cout << endl;
    cin.get();                               //按下回车 执行下一条命令
    cout << "I'm hanray";                   //another message
    cout << endl;
    cin.get();
    return 0;                                 //函数终端（只适用于main（）函数） 
}
