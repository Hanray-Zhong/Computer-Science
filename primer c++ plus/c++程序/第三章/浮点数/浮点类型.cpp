#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);                   //����cout.setf����������ǿ��ʹ�ö����ʾ��С�������6λ 
                                                                        //�Ҳ���ɾ����λ��0 
    float tub = 10.0/3.0;
    double mint = 10.0/3.0;
    const float million = 1.0e6;
    
    cout << "tub = " << tub <<endl;
    cout << "a million tub = " << tub*million <<endl;                //float ��֤6λ��Ч �����Գ�ʮ���tub��׼ȷ 
    cout << "ten million tubs = " << 10*million*tub <<endl;
    cout << "mint = " << mint <<endl;                                //double ��֤15λ��Ч 
    cout << "a million mint = " << million*mint <<endl;
    cin.get();
    return 0;
}
