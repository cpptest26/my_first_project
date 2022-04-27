#include <iostream>
#include "Constants.h"

extern int a = 456;
void doSomething()
{
    
    using namespace std;

    cout << "In test,cpp" << Constants::pi << " " << &Constants::pi << endl;
}