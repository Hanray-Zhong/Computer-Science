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
    Pizza pizza; 
    cout<<"Please enter the name of the pizza company:";
    cin.getline(pizza.name,30);
    cout<<"Please enter the D of the Pizza:";
    cin>>pizza.D;
    cin.get();
    cout<<"Please enter the weight of the pizza:";
    cin>>pizza.weight;
    cin.get();
    
    cout<<endl<<"The name of the company:"<<pizza.name<<endl;
    cout<<"D:"<<pizza.D<<"cm"<<endl;
    cout<<"weight:"<<pizza.weight<<"g"<<endl;
    
    cin.get();
    return 0;
}
