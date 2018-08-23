#include <iostream>
#include <cstring>
using namespace std;
char* getname(void);                    //自定义函数，返还一个指针的地址 
int main()
{
    char* name;
    
    name=getname();
    cout<<name<<" at "<<(int*)name<<endl;
    delete [] name;
    
    name=getname();
    cout<<name<<" at "<<(int*)name<<endl;
    delete [] name;
    cin.get();
    return 0;
}

char* getname()
{
      char temp[80];
      cout<<"Enter last name:";
      cin>>temp;
      cin.get();
      char* pn=new char[strlen(temp)+1];
      strcpy(pn,temp);
      return pn;
}
     
