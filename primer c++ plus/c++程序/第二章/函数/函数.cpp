#include <cmath>                                   //运算法则所需要添加的 
#include <iostream>
#include <cstdlib> 
int main()
{
    using namespace std;
    double x;                                        //定义整数 
    x = sqrt(625);                                    //sqrt() 表示开方 
    cout << x;
    cin.get();
    double y;
    y = sqrt(6.25);                               //定义小数 
    cout << y;
    cin.get();
    double z = sqrt(6.25);                        //这样输入更加方便 
    cout << z;
    cin.get();
    double f = pow(5.00, 8.00);                     //pow(a, b) 表示a的b次幂 ，注意：若定义是 double，则输入a,b时必须为小数 
    cout << f;
    cin.get();
    int unknown;                                   //随机数前需要定义 
    unknown = rand();                             //随即返还一个 “整数” 
    cout << unknown;
    cin.get();
    return 0;
}
