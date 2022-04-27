#include <iostream>
#include "Resource.h"
#include <memory>

class Resource
{
public:
	int * m_data = nullptr;
	unsigned m_length = 0;

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
    // Resource *res = new Resource(3);
    // res->setAll(1);
    {
    // std::shared_ptr<Resource> ptr1(res);

    auto ptr1 = std::make_shared<Resource>(3);
    ptr1->setAll(1);

    ptr1->print();
    {

       
        std::shared_ptr<Resource> ptr2(ptr1);

        ptr2->setAll(3);
        ptr2->print();

        std::cout << "Going out of the block" << std::endl;
    }
    ptr1->print();
    std::cout << "Going out of the outer block" << std::endl;
    }


std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(3);
cout << "현재 소유자 수 : " << ptr1.use_count() << endl; // 1 출력

auto ptr2 = ptr1;
cout << "현재 소유자 수 : " << ptr1.use_count() << endl; // 2 출력

ptr2.reset();
cout << "현재 소유자 수 : " << ptr1.use_count() << endl; // 1 출력

     return 0;
}