#include <iostream>
#include <string>
#include <cstring>
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20]="jaguar";
    string str1;
    string str2="panther";
    
    str1=str2;
    strcpy(charr1,charr2);            //���ߵȼ�     strcpy()������charr2���Ƹ�charr1 
    
    str1+=" paste";
    strcat(charr1," juice");           //���ߵȼۣ�strcat����char��+=����string      strcat()������" juice"�ӵ�charr1�� 
    
    int len1=str1.size();              // aaa.size()ֻ�ܼ���string   c++stringʹ�ö������;�� 
    int len2=strlen(charr1);            //����������ַ��� ,strlen()ֻ�ܼ���char      c����ʹ�ò��� 
    
    cout<<"The string "<<str1<<" contains "<<len1<<" characters.\n";
    cout<<"The string "<<charr1<<" contains "<<len2<<" characters.\n";
    cin.get();
    return 0;
}
