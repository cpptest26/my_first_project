#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
#include <utility>


using namespace std;

template<class T>
{
void MySwap(T &a, T &b)
{
T tmp{ std::move(a)};
a = std::move(b);
b = std::move(tmp);
}

void print()
{
    for(unsigned i = 0; i < m_length; i++)
    std::cout << m_data[i] << " ";
    std::cout << std::endl;
}

void setAll(const int& v)
{
    for (unsigned i = 0; i < m_length; ++i)
    
    m_data[i] = v;
}
};
int main()
{
    {
        AutoPtr<Resource> res1(new Resource(10000000));

        cout << res1.m_ptr << endl;

        AutoPtr<Resource> res2 = std::move(res1);

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }
}

    {
    
    AutoPtr<Resource> res1(new Resource(3));
    res1->setAll(3);
    

    AutoPtr<Resource> res2(new Resource(5));
    res1->setAll(5);


    res1->print();
    res2->print();

    MySwap(res1, res2);

    res1->print();
    res2->print();
    
    

    return 0;
}