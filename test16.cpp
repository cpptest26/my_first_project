#include <iostream>

int add( int a, int b)
{
    return a + b;
}

int main() {

    using namespace std;
    int x = 1, y = 2;
    int v = add( x, ++y);
    
    cout << v <<  endl;
    



    return 0;
}