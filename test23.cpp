#include <iostream>
#include <bitset>

using namespace std;

int main()
{

    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;
    
    cout << std::bitset<32>(red_mask) << endl;
    cout << std::bitset<32>(green_mask) << endl;
    cout << std::bitset<32>(blue_mask) << endl;


    unsigned int pixel_coler = 0xDAA520;

    cout << std::bitset<32>(pixel_coler) << endl;
    unsigned char blue =pixel_coler & blue_mask;
    unsigned char green =(pixel_coler & green_mask) >> 8;
    unsigned char red =(pixel_coler & red_mask) >> 64;

    cout << "blue " << std::bitset<8>(blue) << " " << (int)blue << endl;
    cout << "green " << std::bitset<8>(green) << " " << (int)green << endl;
    cout << "red " << std::bitset<8>(red) << " " << (int)red << endl;



    return 0;
}