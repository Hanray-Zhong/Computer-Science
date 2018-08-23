#include <iostream>
const int Arsize=16;                          //在引用数组长度时常用const 
int main()
{
    using namespace std;
    long long jiecheng[Arsize];
    jiecheng[1]=jiecheng[0]=1;
    for (int i=2;i<Arsize;i++)              //在（）中定义i，只在该循环中有效 
         jiecheng[i]=i*jiecheng[i-1];       //建立一个从1！到15！的数组 
    for (int i=0;i<Arsize;i++)
         cout<<i<<"!="<<jiecheng[i]<<endl;   //将该数组的每一个成员打印出来 
    cin.get();
    return 0;
}
