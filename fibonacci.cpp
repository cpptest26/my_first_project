#include <iostream>
using namespace std;

int fibonachi(int n)
{
    if(n ==1)
        return 0;
    else if(n ==2)
        return 1;

    else {
        const int sum = int(n -2) + int(n-1);
        return sum;
    }
}
int main()
{
    for( int n =2 ; n < 99; n++)
    {
        int sum = int(n -2) + int(n-1);
    }
    cout << fibonachi(99) << endl;


    return 0;
}