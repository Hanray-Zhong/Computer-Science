#include <iostream>
int main()
{
    using namespace std;
    
    int i;
    for(i=0;i<=4;i++)          //i=5表示i从0开始，i<=4或者是i<5表示i到4为止，i++表示i每次循环后加一，等价于i=i+1 
        cout<<"C++ knows loops.\n";          //循环体 
    
    cout<<"C++ knows when to stop.\n";
    cin.get();
    return 0; 
}
