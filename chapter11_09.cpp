#include <iostream>
using namespace std;

class A
{
    public:
    void print()
    {
        cout << "A" << endl;
    }
    virtual A* getThis()
    {
         cout << "A::getThis()" <<endl;
     return this;}
};

class B :public A
{
    public:
    void print ()
    {
        cout << "B" << endl;
    }
     virtual B* getThis()
     {
         cout << "B::getThis()" <<endl;
     return this;}
};

int main()
{
    A a;
    B b;
    //C c;

    A &ref = b;
    b.getThis() -> print();
    ref.getThis() -> print();

    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(ref.getThis()).name() << endl;
    return 0;
}