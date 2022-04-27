#include <iostream>
#include <array>
#include <tuple>

using namespace std;

std::tuple<int, double> getTuple()
{
    int a = 10;
    int d = 3.14;
    return std::make_tuple(a,d)
}
int main()
{
   std::tuple<int, double> my_tp= getTuple();
   std::get<0>(my_tp);
   std::get<1>(my_tp);

   return 0;
}

