#include <iostream>
struct CandyBar
{
       char brand[20];
       double weight;
       int CLL;
};

int main()
{
    using namespace std;
    CandyBar snack={"Mocha Munch",2.3,350};
    CandyBar wahaha={"whh",3.8,250};
    
    cout<<"snack:\n"<<"Brand:"<<snack.brand<<endl
        <<"Weight:"<<snack.weight<<endl
        <<"CLL:"<<snack.CLL<<endl;
    cout<<"wahaha:\n"<<"Brand:"<<wahaha.brand<<endl
        <<"Weight:"<<wahaha.weight<<endl
        <<"CLL:"<<snack.CLL<<endl;
    cin.get();
    return 0;
}
