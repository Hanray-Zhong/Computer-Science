#include <iostream>
#include <cstring>                     //strlen()函数需要的头文件 
int main()
{
    using namespace std;
    const int size=15;
    char name1[size];
    char name2[size]="c++owboy";
    cout<<"Howdy!I'm "<<name2<<"! What's your name?";
    cin>>name1;
    cin.get();
    cout<<"Well,"<<name1<<",your name has "<<strlen(name1)<< " letters and is stored\n";      //strlen()显示的是字符串的长度
                                                                     //要储存n个字符的字符串，数组长度不得少于n+1（含'\0'） 
    cout<<"in an array of "<<sizeof(name1)<<" bytes.\n";                     //sizeof()函数显示的是整个数组的长度 
    cout<<"Your initial is "<<name1[0]<<endl;
    name2[3]='\0';
    cout<<"Here are the first 3 letters of my name:"<<name2;
    cin.get();
    return 0;
}
