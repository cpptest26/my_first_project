

class 
{
    private:
    int m_value;

public:

using namespace std;

Calc(int init_value)
: m_value(init_value)
{}

Calc& add(int value)
{
    m_value +=value;
    return *this;
}
};


