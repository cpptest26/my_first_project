#include <iostream>

using namespace std;

int Sum(int x)
{
    if ( x == 1 )
    {
    return x;
    }

    else
    {
        if(x % 2 == 0)
    {
        return Sum(x / 2) * 2 + (x/2) * (x/2);
    }
        else
        {
            return Sum(x-1 / 2) * 2 + (x-1 / 2) * (x-1 / 2);
        }
        
    }

    return 0;


}

int main()
{
    int a;
    cin >> a;
    cout << Sum(a);
}

