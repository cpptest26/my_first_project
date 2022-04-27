#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
    {
        for (int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
        std::cout << std::endl;
    }

    //expicit instantiation

    //template void MyArray<int>::print();

    template class MyArray<int>;