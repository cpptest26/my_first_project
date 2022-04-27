#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;


class CustomVector
{
    public:
    unsigned n_data = 0; //동적 배열의 사이즈가 될 멤버변수
    int *ptr = nullptr; //동적 배열 포인터가 될 멤버 변수

    CustomVector(const unsigned & _n_data, const int & _init = 0)
    {
        cout << "Constructor" << endl;

        init(_n_data, _init);
    }

    CustomVector(CustomVector &l_input)//l-value만 받을 수 있다.
    {
        cout << "Copy constructor" << endl;

        init(l_input.n_data);

        for(unsigned i = 0; i < n_data; ++i)
        ptr[i] = l_input.ptr[i];//깊은복사
    }

    CustomVector(CustomVector &&r_input)//r-value만 받을 수 있다.
    {
        cout << "Move constructor" << endl;

        n_data = r_input.n_data;
        ptr = r_input.ptr;//소유권 이전

        r_input.n_data = 0;
        r_input.ptr = nullptr;//소유권 박탈
    }

    ~CustomVector()
    {
        delete[] ptr;
    }

    void init(const unsigned & _n_data, const int & _init = 0)
    {
        n_data = _n_data;
        ptr = new int[n_data];
        for(unsigned i = 0; i < n_data; ++i)
        ptr[i] = _init;
    }
};

    void doSomething(CustomVector & vec)
    {
        cout << "Pass by L-reference" << endl;
        CustomVector new_vec(vec);
    }

    void doSomething(CustomVector && vec)
    {
        cout << "Pass by R-reference" << endl;
        CustomVector new_vec(std::move(vec));//R-value 로 vec를 받았더라도 std::move 로서 넘겨주어야 한다.
    }

    template<typename T>
    void doSomethingTemplate_O(T && vec)//l-value와 r-value를 구분해서컴파일 한다.
    {
        doSomething(std::forward<T>(vec));
    } // l-value 와 R-value 구분함

    // template <typename T>
    // void doSomethingTemplate_X(T vec)
    // {
    //     doSomething(vec);
    // }//l-value 와 R-value 구분 못함

int main()
{
    CustomVector my_vec(10, 1024);
    //doSomething(my_vec);
    //doSomething(CustomVector(10,8));

   doSomethingTemplate_O(my_vec);
   doSomethingTemplate_O(CustomVector(10,8));

    //my_vec;
}