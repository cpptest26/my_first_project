#include <iostream>

bool isEqual(int a, int b)
{
    bool result = ( a == b );

    return result;
}

int main(){

    using namespace std;

    // cout << std::boolalpha;
    // cout << isEqual(1,1) << endl;
    // cout << isEqual(0,3) << endl;

    if(5)
    {
        cout << "True" << endl;
        
    }
    else
        cout << "False" << endl;
    return 0 ;
}