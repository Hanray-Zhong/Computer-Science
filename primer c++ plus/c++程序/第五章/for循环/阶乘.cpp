#include <iostream>
const int Arsize=16;                          //���������鳤��ʱ����const 
int main()
{
    using namespace std;
    long long jiecheng[Arsize];
    jiecheng[1]=jiecheng[0]=1;
    for (int i=2;i<Arsize;i++)              //�ڣ����ж���i��ֻ�ڸ�ѭ������Ч 
         jiecheng[i]=i*jiecheng[i-1];       //����һ����1����15�������� 
    for (int i=0;i<Arsize;i++)
         cout<<i<<"!="<<jiecheng[i]<<endl;   //���������ÿһ����Ա��ӡ���� 
    cin.get();
    return 0;
}
