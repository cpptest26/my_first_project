#include <iostream>
#include <array>
#include <functional>

using namespace std;

bool isEven(const int& number)
{
     if(number % 2 == 0) return true;
     else return false;
}

bool isOdd(const int& number)
{
     if(number % 2 == 0) return true;
      else return false;
}
void printNumbers(const array<int, 10>&my_array, bool(*check_fcn)(const int&))
{
    for (auto element : my_array)
    {
        if(std::function<bool(const int&)>) cout << element;
       
    }
    cout << endl;


}
using check_fcn_t = bool(*)(const int&);


int main()
{

    std::array<int,10> my_array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::function<bool(const int&)>fcnptr = isEven;

    printNumbers(my_array, isEven);
    printNumbers(my_array, isOdd);
    cout << endl;
    return 0;
}