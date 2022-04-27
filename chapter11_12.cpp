#include <iostream>
using namespace std;

class Base{
    public:
    virtual void func1() {};
    virtual void func2() {};
};

class Der : public Base{
    public:
    virtual void func1() {};
    virtual void func3() {};
};

int main()
{
    cout << sizeof(Base) << endl;
    cout << sizeof(Der) << endl;

    return 0;
}
