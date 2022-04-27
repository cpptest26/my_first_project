#include <iostream>

int pow(int base, int exponent)
{
    int result = 1;

    for (int count = 0; count < exponent; ++count)
    result *= base;

    return result;
}

int main()
{
    using namespace std;
    
    for ( int i = 9 ; i >=0; --i)
        cout << i << endl;

    return 0;
}