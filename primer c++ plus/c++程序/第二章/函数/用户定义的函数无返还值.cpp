#include <iostream>
 using namespace std;                                           //���Խ����ƿռ��������������ǰ�棬�����Ͳ��������������ж��������ƿռ� 
 void simon(int); 
 
int main()
{
     simon(3);
     cout<<"Pick an integer: ";
     int count;
     cin>>count;                                                //cin<< =����Ҫ�����䡰cin.get();��,��ȡ����*****
     cin.get(); 
     simon(count);
     cout<<"Done!"<<endl;
     cin.get();
     return 0;
}

void simon(int n)                                          //�º�����Դ������ main() ��ǰ����ߺ��棬������Ƕ��main�����У�ÿ��������������
                                                          //�������У�������һ����������n 
{
     cout<<"Simon says touch your toes "<<n<<" times."<<endl;               //�ú�������Ҫ return 0 ????? 
}
