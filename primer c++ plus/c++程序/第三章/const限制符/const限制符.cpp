#include <iostream>
int main()
{
    using namespace std;
    const int MONTHS = 12;                   //const 限制符规定该值为常数，若后面初始化，则编译器会显示错误
    
    cout<<"One year has "<<MONTHS<<" years.";
    MONTHS = MONTHS + 1;
    cin.get();
    return 0;
}
