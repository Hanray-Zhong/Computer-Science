#include <iostream>
int main()
{
    using namespace std;
    int carrots;
    cout<<"���������м���buff�������»س�"<<endl;
    cin>>carrots;                                       //��C++�У�cin>> ��ʾ���룬����Ϊ int ֻ���������� ���ԣ�ֻ�������������������ᵯ�� 
    cout<<"�������ٸ����һ��";                         //cin<< =����Ҫ�����䡰cin.get();��,��ȡ����***** 
    carrots=carrots+5;
    cout<<endl;
    cin.get(); 
    cout<<"�밴�س���ʾ�����ڵ�buff����";
    cin.get();
    cout<<carrots<<endl;
    cout<<"�Ҷ�������5��buff����л�Ұ�"
        <<endl
        <<endl
        <<"���س�����";                                //��������������ݽ϶��� 
    cin.get();
    return 0;
}
