#include <iostream>
#define ZERO 0                                                   //���� ZERO Ϊ 0  
#include <climits>
int main()
{
    using namespace std;
    short sam = SHRT_MAX;                                       //short ��ʾ�������� 
    unsigned short sue = sam;                                    //unsigned short ��ʾֻ���� 
    
    //����չʾ������ֵ�ĺ�� 
    cout << "Sam has "<< sam << " dollars and sue has " << sue <<" dollars.";
    cin.get();
    cout << "add $1 to each one." ;
    cin.get();
    sam = sam + 1;
    sue = sue + 1;
    cout << "Now,Sam has "<<sam<<" dollars and sue has "<<sue<<" dollars.";
    cin.get();
    sam = ZERO;
    sue = ZERO;
    cout<<"Sam has "<<sam<<" dollars and sue has "<<sue<<" dollars"<<endl;
    cout<<"Take $1 from each one";
    cin.get();
    sam = sam - 1;
    sue = sue - 1;
    cout<<"Now,Sam has "<<sam<<" dollars and sue has "<<sue<<" dollars.";
    cin.get();
    return 0;
} 
