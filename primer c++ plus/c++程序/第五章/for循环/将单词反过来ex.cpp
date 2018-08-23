#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout<<"Enter a word:";
    string word;
    cin>>word;
    cin.get();
    
    char temp;
    int i,j;
    for(j=0,i=word.size()-1;j<i;--i,++j)
    {
          temp=word[i];
          word[i]=word[j];
          word[j]=temp;
    }
    cout<<word<<endl;
    cout<<"Done\n";
    cin.get();
    return 0;
} 
