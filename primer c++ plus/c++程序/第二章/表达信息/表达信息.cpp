#include <iostream>                          // ��iostream��������������ļ���������� ��60-[ʹ��cin��cout�������������ĳ������ʹ��  
int main()                                   // ����ͷ--��ΪC++��windows�Ľӿ� 
{                                            // ������Ŀ�ͷ
 
    using namespace std;                     // ������һ����Ϊstd�����ƿռ��У�namespace��ָ��ʶ���ĸ��ֿɼ���Χ,ʹ�ø����ƿռ�ʹiostream��
                                             // �ó�����Ч���Ժ��ٿ��ǣ������������ֲ�ͬ�汾�ĺ���
                                             //����ú���count(),ʵ����Ϊ std::count��endlΪ std::endl
                                             //��ˣ�����ʡ��using��䣬��ʡ�Ե�"std::"���ϣ��ȼ�
                                             //���⣬"using namespace std"�Ƕ�����std���ƿռ�Ķ��嶼����
                                             //���Ҫֻ�ü�����������"using std::cout  std::cin  std::endl",��������iostreamָ���޷�ʹ�� 
    
    cin.get();                               //���»س� ִ����һ������������������һ�� 
    
    cout << "welcome to the world of C++.";  //messsage   ��Ҫ""��� 
                                             //��["......"]Ϊ�ַ�����<<��ʾ��"....."�ַ������͸�cout��cout������ʾ�ַ��������֣������ַ��� 
    
    cout << endl;                            //ʹ����Ƶ���һ�� 
    
    cin.get();                               //���»س� ִ����һ������  
    cout << "come up and C++ me some time."; //message,too
    cout << endl;
    cin.get();                               //���»س� ִ����һ������
    cout << "I'm hanray";                   //another message
    cout << endl;
    cin.get();
    return 0;                                 //�����նˣ�ֻ������main���������� 
}
