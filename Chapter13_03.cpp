#include "MyArray.h"

int main()
{
    const int a = 100;
    MyArray<double,a> my_array;

    for(int i = 0; i <my_array.getLength(); ++i)
    my_array[i] = i + 65;

    my_array.print();

    return 0;
}