#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char word[5]="?ate";
    for (char ch='a';strcmp(word,"mate");ch++)           // strcmp()�����Ƚ��ַ����Ĵ�С����д��ĸ��Сд��ĸǰ 
                                                         //���word��mateǰ�棬��ú������ص�ֵΪ������֮Ϊ�� 
                                                         //���ֻ��Ҫmate������Ըĳ�strcmp(word,"mate")!=0
                                                         //�ַ�������ȣ��������ֵΪ1(true)�������Ϊ0(false) 
    {
        cout<<word<<endl;
        word[0]=ch;
    }
    
    cout<<"After loop ends,word is "<<word<<endl;
    cin.get();
    return 0;
}
