#include <iostream>
using namespace std;

class Something{
    public:

    class _init
    {
        public:
        _init()
        {
            s_value = 9876;
        }
    };

private:
    static int s_value;
    int m_value;
    static _init s_initializer;
};
   
Something::_init Something::s_initializer;


int main()
{

    Something s1,s2;
   
    //cout << s1.s_value << endl;



    return 0;
}