#include <iostream>
#include <vector>
#include <utility>


using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
    cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
    cout << "Pass by R-ref" << endl;
}

template<typename T>
void func_wrapper(T&& t)
{
    //func(std::forward<T>(t));
}

int main()
{
    MyStruct s;

    func_wrapper(s);
    func_wrapper(MyStruct());

    //func(s);//L-value reference 실행
    //func(MyStruct());//R_value reference 실행

    return 0;
}