#include <iostream>
#include <string>
#include <cassert>
#include <array>


int main()
{
    const int x = 5;

    assert(x ==5);

    static_assert( x ==5, " x should be 5");

    return 0;
}