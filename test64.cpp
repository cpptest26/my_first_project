#include <iostream>
#include <string>
using namespace std;

typedef int my_int;

void print(unsigned int value){}
void print(float value){}


int main()
{
    print(0u);
    print(3.141592f);
    print((unsigned int)'a');

    return 0;
}