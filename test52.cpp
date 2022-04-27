#include <iostream>
using namespace std;


struct Something
{
    int v1;
    float v2;
};

struct Other
{
    Something st;
};

int main()
{
    int value = 5;
    int *const ptr = &value;
    int &ref = value;

    *ptr = 10;
    ref = 10;

    return 0;
}