#include <iostream>
int main()
{
    using namespace std;
    const int ArSize=20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout<<"Enter your name:\n";
    cin.getline(name,ArSize);                               //���ʹ��cin>>��������ʱ�����˿հף�����Ϊ�ַ�����ֹ����Ҫ����һ�����հ׵��ַ���
                                                        //ʹ�ö��еĺ���cin.getline()��cin.get()��ȡһ��ֱ�����з� 
    cout<<"Enter your favorite dessert:\n";
    cin.get(dessert,ArSize);                          //cin.get(Ҫ��������飬���鳤��) 
    cin.get();                                        //ע�⣺cin.get(...)�����������з�����˺������cin.get()����֤��ǣ������ĳ��� 
    cout<<"I have some delicious "<<dessert<<" for you "
        <<name<<endl;
    cin.get();
    return 0;
}
