#include <iostream>
using namespace std;

const char* Name()
{
    return "jack jakc";
}
int main()
{
    char c = 'Q';
    cout << *&c << endl;

    return 0;
}