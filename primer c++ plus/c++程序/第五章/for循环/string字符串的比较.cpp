#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string word="?ate";
    for (char ch='a';word!="mate";ch++)              //string��Ϳ���ֱ����������� 
    {
        cout<<word<<endl;
        word[0]=ch;
    }
    
    cout<<"After loop ends,word is "<<word<<endl;
    cin.get();
    return 0;
} 
