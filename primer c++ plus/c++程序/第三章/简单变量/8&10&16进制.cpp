#include <iostream>
int main()
{
    using namespace std;
    int chest = 42;                                                        //10���Ʊ�� 
    int waist = 0x42;                                                      //16���Ʊ�0x-- 
    int inseam = 042;                                                      //8���Ʊ� ��һ������Ϊ0����һλ���� 1~7 
    
    cout<<"����������ת��Ϊ10����"<<endl;
    cout<<"10����42ת��Ϊ10����: "<<chest<<endl;
    cout<<"16����42ת��Ϊ10����: "<<waist<<endl;
    cout<<"8����42ת��Ϊ10���ƣ�"<<inseam<<endl;                         //cout ���ϵͳĬ��10������� 
    cin.get();
    
    //���������Ƿ�ʮ�������42
    int n_chest = 42;
    int n_waist = 42;
    int n_inseam = 42;
    
    cout<<dec;                                                           //10���������ʽ 
    cout<<"ʮ�������42��"<<n_chest<<endl;
    cout<<hex;                                                           //16���������ʽ 
    cout<<"ʮ���������42��"<<n_waist<<endl;
    cout<<oct;                                                           //8���������ʽ 
    cout<<"�˽������42��"<<n_inseam<<endl;
    cin.get();                                                           //���ϸ�ʽ���޸�ǰ��һֱ����ԭ��ʽ 
    return 0;
}
