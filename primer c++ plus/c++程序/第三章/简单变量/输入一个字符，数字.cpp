#include <iostream>
int main()
{
    using namespace std;
    char ch;
    
    cout<<"What's your name?"<<endl;
    cin>>ch;                                       //���� M ��cin �Ƚ� M ת��Ϊ�ַ�����ֵ77 
    cin.get();
    cout<<"Hello, Mr."<<ch<<" .";                  //cout �ٽ�77ת��Ϊ M ��� 
    cin.get(); 
    return 0;
}
