#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char word[5]="?ate";
    for (char ch='a';strcmp(word,"mate");ch++)           // strcmp()用来比较字符串的大小，大写字母在小写字母前 
                                                         //如果word在mate前面，则该函数返回的值为负，反之为正 
                                                         //如果只不要mate，则可以改成strcmp(word,"mate")!=0
                                                         //字符串不相等，则该语句的值为1(true)，相等则为0(false) 
    {
        cout<<word<<endl;
        word[0]=ch;
    }
    
    cout<<"After loop ends,word is "<<word<<endl;
    cin.get();
    return 0;
}
