//���������������ı仯��cout �������� 


#include <iostream>
int main()
{
    using namespace std;
    
    int carrots;                                     //����һ������ carrots �ı�������һ������������carrots�� 
    
    carrots=25;                                     //��ñ���Ϊ 25 
    cin.get();
    cout << "I have " << carrots                    //cout ���������������������ַ��� 
    << " carrots";     // 
    cout << endl;
    carrots=carrots-1;                          //�仯���� 
    cout << "I eat one." << endl;
    cout << "Now,I have " << carrots << " carrots";
    cin.get();
    return 0;
}
     
