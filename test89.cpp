#include <iostream>
using namespace std;
class Digit
{
    private:
    int m_digit;
    public:
    Digit(int digit = 0) : m_digit(digit) {}

    Digit & operator ++ ()
    {
        ++m_digit;

        return *this;
    }

    Digit operator ++(int)
    {
        Digit temp(m_digit);

        ++(*this);

        return temp;
    }

    friend ostream & operator << (ostream &out, const Digit &d)
    {
        cout << d.m_digit;
        return out;

    }
};

int main(){

Digit d(5);
cout << ++d << endl;
cout << d << endl;

cout << d++ << endl;
cout << d << endl;

return 0;
}