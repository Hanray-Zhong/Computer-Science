#include <iostream>
int main()
{
    using namespace std;
    int nights=1001;
    int* pt=new int;           //new 把一个地址给指针，因此就不需要再初始化指针 
    *pt=1001;                  //当使用完一个指针后，可使用delete还原内存 
    
    
    cout<<"nights value="<<nights
        <<": location "<<&nights<<endl; 
    cout<<"int value="<<*pt<<": location="<<pt<<endl;
    double* pd=new double;
    *pd=10000001.0;
    
    cout<<"double value="<<*pd<<": location="<<pd<<endl;
    cout<<"location of pointer pd:"<<&pd<<endl;
    cout<<"size of pt="<<sizeof(pt);
    cout<<": size of *pt="<<sizeof(*pt)<<endl;
    cout<<"size of pd="<<sizeof(pd);
    cout<<": size of *pd="<<sizeof(*pd)<<endl;
    cin.get();
    return 0;
}
