#include <iostream>
#include<cmath>
#define M_E

int main() 
{
    using namespace std;

    double d1(100 - 99.99);
    double d2(10 -  9.99);
    
    const double epsilon = 1e -10;

    if(std::abs(d1-d2) < epsilon)
    cout << "Approximately equal" << endl;
    else
    cout << "NOT equal" <<endl;
    
     return 0;
}
