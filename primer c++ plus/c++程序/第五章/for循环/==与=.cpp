#include <iostream>
int main()
{
    using namespace std;
    int quizscores[10]={20,20,20,20,20,19,20,18,20,20};
    
    cout<<"Doing it right:\n";
    int i;
    for(i=0;quizscores[i]==20;i++)
        cout<<"quiz"<<i<<" is a 20.\n";              //==表示是否等于，是一个判断语句，而=只表示赋值 
     
    cin.get();
    return 0;
}
