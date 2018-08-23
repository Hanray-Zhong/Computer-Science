#include <iostream>
const int size=20;
int main()
{
    using namespace std;
    char name[size];
    cout<<"Your first name please:";
    cin>>name;
    cin.get();
    cout<<"Here is your name, verticalized and ASCIIized:\n";
    int i=0;
    while (name[i]!='\0')           //while¼ì²âÓï¾ä£¬µ±name[i]Îª¿Õ×Ö·ûÊ±½áÊøÑ­»· 
    {
          cout<<name[i]<<":"<<int(name[i])<<endl;     //´òÓ¡×Ö·ûµÄASCIIÂë 
          i++;
    }
    
    cin.get();
    return 0;
}
