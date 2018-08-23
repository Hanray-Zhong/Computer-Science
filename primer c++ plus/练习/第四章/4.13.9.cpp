#include <iostream>
struct CandyBar
{
       char brand;
       double weight;
       int CLL;
};

int main()
{
    using namespace std;
    CandyBar* snack=new CandyBar [2];
    snack[0].brand="A";                        //??????????
    snack[0].weight=2.3;
    snack[0].CLL=350;
    snack[1].brand="B";
    snack[1].weight=3.6;
    snack[1].CLL=400;
    
    for(int i=0;i<=1;i++)
    {
            cout<<"Brand:"<<snack[i].brand<<endl;
            cout<<"Weight:"<<snack[i].weight<<endl;
            cout<<"CLL:"<<snack[i].CLL<<endl;
    }
    
    cin.get();
    delete [] snack;
    return 0;
}
