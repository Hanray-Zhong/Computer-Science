#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    cout<<"9/5 = "<< 9/5 <<endl;                //都是整数，则丢弃小数部分 
    cout<<"9.0/5.0 = "<<9.0/5.0<<endl;          //只要有一个为小数（浮点数），则保留小数部分 
    cout<<"9.0/5 = "<<9.0/5<<endl;              //系统默认double输出 
    cin.get();
    return 0;
}
