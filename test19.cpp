#include <iostream>

int main()
{
    using namespace std;
    
    
    bool v1 = true;
    bool v2 = false;
    bool v3 = false;

    bool r1 = v1 || v2 && v3;
    bool r2 = (v1 || v2) && v3; //false
    bool r3 = v1 || (v2 && v3); //true

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;


return 0;
}

