#include <iostream>
const int size=20;
int main()
{
    using namespace std;
    char name[size];
    cout<<"Your first name please:";
    cin>>name;
    cin.get();
    cout<<"Here is your name, verticalized and ASCIIized:\n";
    int i=0;
    while (name[i]!='\0')           //while�����䣬��name[i]Ϊ���ַ�ʱ����ѭ�� 
    {
          cout<<name[i]<<":"<<int(name[i])<<endl;     //��ӡ�ַ���ASCII�� 
          i++;
    }
    
    cin.get();
    return 0;
}
