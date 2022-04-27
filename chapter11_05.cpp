#include <iostream>
using namespace std;

class Base
{
    protected:
    int m_i;

    public:
    Base(int value)
    : m_i(value)
    {}

    void print()
    {
        cout << "base" << endl;
    }

};

class Derived : public Base{
    private :
    double m_d;

    public :
    Derived(int value)
    :Base(value)
    {}

    using Base::m_i;

    private:
    void print() = delete;

};

int main()
{

   
    Derived derived(7);

    derived.m_i = 1024;

    return 0;
}