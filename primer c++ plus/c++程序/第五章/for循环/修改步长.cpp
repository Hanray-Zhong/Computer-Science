#include <iostream>
int main()
{
    using namespace std;
    cout<<"Enter an integer:";
    int by;
    cin>>by;
    cin.get();
    cout<<"Counting by "<<by<<"s:\n";
    for(int i=0;i<100;i=i+by)                //����������ѡ��i=i+by,�������ó˷��ͳ��� ��i=i+by�ȼ���i+=by 
        cout<<i<<endl;
    cin.get();
    return 0;
}
