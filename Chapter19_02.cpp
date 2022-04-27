#include <iostream>
#include <tuple>

using namespace std;

auto my_func()
{
    return tuple(123,456);
}

int main()
{

   auto result = my_func();

    cout << get<0>(result) << " " << get<1>(result) << endl;

    return 0;
}