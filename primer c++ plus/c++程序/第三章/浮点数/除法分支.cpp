#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    cout<<"9/5 = "<< 9/5 <<endl;                //��������������С������ 
    cout<<"9.0/5.0 = "<<9.0/5.0<<endl;          //ֻҪ��һ��ΪС������������������С������ 
    cout<<"9.0/5 = "<<9.0/5<<endl;              //ϵͳĬ��double��� 
    cin.get();
    return 0;
}
