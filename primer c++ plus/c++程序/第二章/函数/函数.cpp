#include <cmath>                                   //���㷨������Ҫ��ӵ� 
#include <iostream>
#include <cstdlib> 
int main()
{
    using namespace std;
    double x;                                        //�������� 
    x = sqrt(625);                                    //sqrt() ��ʾ���� 
    cout << x;
    cin.get();
    double y;
    y = sqrt(6.25);                               //����С�� 
    cout << y;
    cin.get();
    double z = sqrt(6.25);                        //����������ӷ��� 
    cout << z;
    cin.get();
    double f = pow(5.00, 8.00);                     //pow(a, b) ��ʾa��b���� ��ע�⣺�������� double��������a,bʱ����ΪС�� 
    cout << f;
    cin.get();
    int unknown;                                   //�����ǰ��Ҫ���� 
    unknown = rand();                             //�漴����һ�� �������� 
    cout << unknown;
    cin.get();
    return 0;
}
