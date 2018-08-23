#include <iostream>                                   //该程序用来显示不同类的 位数 和 储存的最大值 
#include <climits>
int main()
{
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    
    cout << "int is " << sizeof (int) << " bytes." << endl;         //sizeof 计算字节数的多少，如果对 类 ，放在括号中，对变量，括号可选 
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << "bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." <<endl;
    cout << endl;
    
    cout << "Maxium values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;
    
    cout << "Minimum int value = " << INT_MIN <<endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    cin.get();
    return 0;
}
