#include <iostream>
 using namespace std;                                           //可以将名称空间放在两个函数的前面，这样就不用在两个函数中都定义名称空间 
 void simon(int); 
 
int main()
{
     simon(3);
     cout<<"Pick an integer: ";
     int count;
     cin>>count;                                                //cin<< =后需要添加语句“cin.get();”,读取输入*****
     cin.get(); 
     simon(count);
     cout<<"Done!"<<endl;
     cin.get();
     return 0;
}

void simon(int n)                                          //新函数的源代码在 main() 的前面或者后面，不能镶嵌在main函数中，每个函数独立存在
                                                          //在括号中，定义了一个整数变量n 
{
     cout<<"Simon says touch your toes "<<n<<" times."<<endl;               //该函数不不要 return 0 ????? 
}
