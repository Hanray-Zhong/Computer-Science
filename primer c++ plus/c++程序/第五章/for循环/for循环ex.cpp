#include <iostream>
int main()
{
    using namespace std; 
    int limit;
    cout<<"Enter the number of the limit:\n";
    cin>>limit;              //�����ʱ�������0�����ڼ����ʽ��ֱ��Ϊfalse��ֱ���˳���i=0 
    cin.get();
    int i;
    for(i=limit;i;i--)      //�ڼ����ʽ�����ֻ��i����i����0ʱ�˳�ѭ�� 
       cout<<"i="<<i<<endl;
    cout<<"Done now that i="<<i<<endl;
    cin.get();
    return 0;
} 
