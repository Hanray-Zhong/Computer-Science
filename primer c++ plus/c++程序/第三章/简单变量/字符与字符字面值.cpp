#include <iostream>
int main()
{
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout<<"�ַ� "<<ch<<" �ı���Ϊ��"<<i<<endl;       //char��cout��ʾ�ַ� ��int��cout��ʾ���� 
    
    cout<<"���ַ������ϼ�1"<<endl;
    ch = ch + 1;
    i = ch;
    cout<<"�ַ� "<<ch<<" �ı���Ϊ��"<<i<<endl;
    
    cout<<"Ҫչʾ ���� ����� �ַ� �ú���cout.put(): ";
    cout.put(ch);
    
    // �����cout.put()������ '��',��Ϊֱ�Ӵ�ӡ�ַ� �� 
    //����� cout<<'!' ��Ϊ��ʾ �� ���ַ�����ֵ 
    cout.put('!');
    
    cin.get();
    return 0;
} 
