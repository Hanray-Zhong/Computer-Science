#include <iostream>
int main()
{
    using namespace std;
    double* p3=new double [3];
    p3[0]=0.2;
    p3[1]=0.5;
    p3[2]=0.8;
    cout<<"p3[1] is "<<p3[1]<<endl;
    p3=p3+1;                         //��������������һ 
    cout<<"Now p3[0] is "<<p3[0]<<" and p3[1] is "<<p3[1]<<endl;
    cout<<"p3[2] is "<<p3[2]<<"\n";                      //p3[2]��Ϊ�����룿������������ 
    p3=p3-1;                       //��Ҫ��ȥһ���ܸ�delete��ȷ�ĵ�ַ 
    delete [] p3;
    cin.get();
    return 0;
}
