#include <iostream>
using namespace std;

int sumTo(int sumto)
{
    if(sumto <= 0)
        return 0;
    else if( sumto <=1)
        return 1;
    else {
        const int sum_minus_one = sumTo(sumto -1);
        return sumTo(sumto -1) + sumto;
    }
}
int main()
{
    cout << sumTo(10) << endl;


    return 0;
}