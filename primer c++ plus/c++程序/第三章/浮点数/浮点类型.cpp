#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);                   //调用cout.setf（）函数，强制使用定点表示，小数点后保留6位 
                                                                        //且不会删除后几位的0 
    float tub = 10.0/3.0;
    double mint = 10.0/3.0;
    const float million = 1.0e6;
    
    cout << "tub = " << tub <<endl;
    cout << "a million tub = " << tub*million <<endl;                //float 保证6位有效 ，所以乘十万后tub不准确 
    cout << "ten million tubs = " << 10*million*tub <<endl;
    cout << "mint = " << mint <<endl;                                //double 保证15位有效 
    cout << "a million mint = " << million*mint <<endl;
    cin.get();
    return 0;
}
