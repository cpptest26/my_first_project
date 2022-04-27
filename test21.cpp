#include <iostream>
#include <bitset>

int main()
{

    using namespace std;

    unsigned int a = 0b0101;
    unsigned int b = 0b1100;

    int c = 0b0110;

 

    cout << std::bitset<8> (a & b) << endl;
    cout << std::bitset<8> (a | b) << endl;
    cout << std::bitset<8> (a ^ b) << endl;

    cout << std::bitset<8>(c>>2) << " " << (c>>2) << endl;



    return 0;
}