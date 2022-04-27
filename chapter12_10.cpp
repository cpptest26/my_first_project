#include <iostream>
using namespace std;

class Base
{
private:
	int base;
public:
	Base(const int& input = 0)
		:base(input) {}
	friend ostream& operator << (ostream& out, const Base& base)
	{
		return base.print(out);
	}
	virtual ostream& print(ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	virtual ostream& print(ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};
int main()
{
    Base b;
    std::cout << b << '\n';

    Derived d;
    std::cout << d << '\n';

    Base & bref = d;
    std::cout << bref << '\n';
}