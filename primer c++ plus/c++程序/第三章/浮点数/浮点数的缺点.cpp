#include <iostream>
int main() 
{
    using namespace std;
    float a = 2.34e22f;
    float b = a + 1.0f;
    
    cout << "a=2.34e22\n" << "b=a+0.1\n";
    cout << "b-a=" << b-a <<endl;                        //��Ϊfloat�ľ���ԭ��b-a=0������1 
    cin.get();
    return 0;
}
