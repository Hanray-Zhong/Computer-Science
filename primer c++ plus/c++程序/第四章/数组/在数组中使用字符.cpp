#include <iostream>
#include <cstring>                     //strlen()������Ҫ��ͷ�ļ� 
int main()
{
    using namespace std;
    const int size=15;
    char name1[size];
    char name2[size]="c++owboy";
    cout<<"Howdy!I'm "<<name2<<"! What's your name?";
    cin>>name1;
    cin.get();
    cout<<"Well,"<<name1<<",your name has "<<strlen(name1)<< " letters and is stored\n";      //strlen()��ʾ�����ַ����ĳ���
                                                                     //Ҫ����n���ַ����ַ��������鳤�Ȳ�������n+1����'\0'�� 
    cout<<"in an array of "<<sizeof(name1)<<" bytes.\n";                     //sizeof()������ʾ������������ĳ��� 
    cout<<"Your initial is "<<name1[0]<<endl;
    name2[3]='\0';
    cout<<"Here are the first 3 letters of my name:"<<name2;
    cin.get();
    return 0;
}
