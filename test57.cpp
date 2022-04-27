#include <iostream>

#include <vector>

using namespace std;

int main()
{


   vector<int> arr = { 1, 2, 3, 4, 5};

   for(auto &itr : arr)
    cout << itr << " ";
    cout << endl;

    cout << array[1] << endl;
    cout << arr.at(1) << endl;
    return 0;
}