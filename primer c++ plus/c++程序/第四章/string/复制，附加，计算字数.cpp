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
    strcpy(charr1,charr2);            //两者等价     strcpy()函数将charr2复制给charr1 
    
    str1+=" paste";
    strcat(charr1," juice");           //两者等价，strcat用于char，+=用于string      strcat()函数将" juice"接到charr1后 
    
    int len1=str1.size();              // aaa.size()只能计算string   c++string使用对象名和句点 
    int len2=strlen(charr1);            //计算数组的字符数 ,strlen()只能计算char      c函数使用参数 
    
    cout<<"The string "<<str1<<" contains "<<len1<<" characters.\n";
    cout<<"The string "<<charr1<<" contains "<<len2<<" characters.\n";
    cin.get();
    return 0;
}
