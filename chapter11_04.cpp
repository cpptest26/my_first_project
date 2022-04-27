#include <iostream>
using namespace std;

class Base
{
    protected:
    int m_value;

public:
Base(int value)
:m_value (value)
{

}

void print()
{
    cout<< "base" << endl;
}

friend std::ostream & operator << (std::ostream & out, const Base & b)
{
    cout <<static_cast<Base>(b) << endl;
    out << "This is base output" << endl;
 return out;
}
};

class Derived : public Base{
    public:
    Derived(int value):
    Base(value)
    {
    }
    void setValue(int value)
    {
        Base::m_value = value;
    }

    void print()
    {
        Base::print();
        cout <<"derived" << endl;
    }

    friend std::ostream & operator << (std::ostream & out, const Derived & b)
{cout <<static_cast<Base>(b) << endl;
 out << "This is Derived output" << endl;
 return out;
}
};

int main()
{
Base base(5);
cout << base;

Derived derived(7);
cout << derived;
    return 0;
}