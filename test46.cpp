#include <iostream>
#include <cstddef>



void doSomething(double *ptr)
{

    std::cout << "address of pointer dosomething" << &ptr << std::endl;
    if( ptr != nullptr)
    {
        std::cout << *ptr << std::endl;
    }
    else
    {
        std::cout << "Null ptr, do nothing" << std::endl;
    }
}

int main()
{
    double *ptr = nullptr;

    doSomething(ptr);
    doSomething(nullptr);

    double d = 123.4;
    
    doSomething(&d);

    ptr = &d;

    doSomething(ptr);

    
    std::cout << "address of pointer variavle in main()" <<&ptr << std::endl;

   
    return 0;
}