#include <iostream>
struct Pizza
{
       char name[30];
       double D;
       double weight;
};

int main()
{
    using namespace std;
    Pizza* pizza=new Pizza;
    cout<<"Please enter the D of the pizza:";
    cin>>pizza->D;
    cin.get();
    cout<<"Please enter the name of the pizza:";
    cin.getline(pizza->name,30);
    cout<<"Please enter the weight of the pizza:";
    cin>>pizza->weight;
    cin.get();
    
    cout<<"The name of the pizza company:"<<pizza->name<<endl;
    cout<<"The D of the pizza:"<<pizza->D<<"cm"<<endl;
    cout<<"The weight of the pizza:"<<pizza->weight<<"g";
    
    delete [] pizza;
    
    cin.get();
    return 0;
}
