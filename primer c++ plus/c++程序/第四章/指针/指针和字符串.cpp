#include <cstring>
#include <iostream>
int main()
{
    using namespace std;
    char animal[20]="bear";
    const char* bird="wren";
    char* ps;                        //����ʼ��ָ��Ƚ�Σ�գ������ʼ�� 
    
    cout<<animal<<" and "<<bird<<endl;
    
    cout<<"Enter a kind of animal:";
    cin>>animal;
    cin.get(); 
    
    ps=animal;                                //��animal����ps���ḳֵ�ַ�������ֻ�Ǹ��Ƶ�ַ��ps��animal����һ����ַ 
    cout<<ps<<"!\n";
    cout<<"Before using strcpy():\n";
    cout<<animal<<" at "<<(int*)animal<<endl;        //(int*)animal����cout��˵��ʾanimal�е��ַ����ĵ�ַ��������ָ��ĵ�ַ 
    cout<<ps<<" at "<<(int*)ps<<endl;
    
    ps=new char[strlen(animal)+1];          // Ҫ�����һ������������Ҫ������һ������ռ䣬���Ϊanimal�Ĵ�С��һ�����Ͽ��ַ��� 
    strcpy(ps,animal);                      //��animal���ַ�����ַ���Ƶ��µ�psָ�봦�������������һ��animal���� 
    cout<<"After using strcpy():"<<endl;
    cout<<animal<<" at "<<(int*)animal<<endl;
    cout<<ps<<" at "<<(int*)ps<<endl;
    cin.get();
    return 0;
}
