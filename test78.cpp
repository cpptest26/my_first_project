#include <iostream>
#include "Calc.h"
using namespace std;

int main()
{
    Calc cal(10);
    cal.add(10).sub(10).mult(2).print();

    Calc(10).add(10).sub(10).mult(2).print();

    return 0;
}