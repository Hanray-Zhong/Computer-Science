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
    CandyBar snack=
    {
             "Mocha Munch",
             2.3,
             350
    };
    cout<<"Brand:"<<snack.brand<<endl;
    cout<<"Weight:"<<snack.weight<<endl;
    cout<<"CLL:"<<snack.CLL<<endl;
    cin.get();
    return 0;
}
             
