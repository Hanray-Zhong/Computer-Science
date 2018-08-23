#include <iostream>
int main()
{
    using namespace std;
    int chest = 42;                                                        //10进制表达 
    int waist = 0x42;                                                      //16进制表达：0x-- 
    int inseam = 042;                                                      //8进制表达： 第一个数字为0，后一位数字 1~7 
    
    cout<<"将其他进制转化为10进制"<<endl;
    cout<<"10进制42转化为10进制: "<<chest<<endl;
    cout<<"16进制42转化为10进制: "<<waist<<endl;
    cout<<"8进制42转化为10进制："<<inseam<<endl;                         //cout 输出系统默认10进制输出 
    cin.get();
    
    //以下内容是非十进制输出42
    int n_chest = 42;
    int n_waist = 42;
    int n_inseam = 42;
    
    cout<<dec;                                                           //10进制输出格式 
    cout<<"十进制输出42："<<n_chest<<endl;
    cout<<hex;                                                           //16进制输出格式 
    cout<<"十六进制输出42："<<n_waist<<endl;
    cout<<oct;                                                           //8进制输出格式 
    cout<<"八进制输出42："<<n_inseam<<endl;
    cin.get();                                                           //以上格式在修改前将一直保持原格式 
    return 0;
}
