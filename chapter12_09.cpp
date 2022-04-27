#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
    public:
    int m_i = 0;

    virtual void print()
    {
        cout << "i'm base" << endl;
    }
};

class Derived1: public Base
{
    public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "i'm derived" << endl;
    }
};


void doSomething(Base & b)
{
    b.print();
}

int main()
{   

    Derived1 d1;
    Base *base = *d1;

    int *base_to_d1 = static_cast<Derived1*>(base);
    cout << base_to_d1 -> m_j << endl;

    return 0;
}

