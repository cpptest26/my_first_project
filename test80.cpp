#include <iostream>

using namespace std;

class Something{
    public:
    static int m_value;
};

//int Something::m_value = 1; //define in cpp
int main()
{

    cout << &Something::m_value << " " << Something::m_value << endl;

    Something st1;
    Something st2;

   //st1.m_value = 2;

    cout << &st1.m_value << " " << st1.m_value << endl;
    cout << &st2.m_value << " " << st1.m_value << endl;

    //Something::m_value = 1024;

    cout << &Something::m_value << " " << Something::m_value << endl;

    return 0;
}