#include <iostream>
#include "Monster.h"
#include "Position2D.h"

using namespace std;

int main()
{
    Monster mon1("sanson", Position2D(0, 0));
    mon1.m_location;

    cout << mon1 << endl;

    Monster mon2("parsival", Position2D(0, 0));

    //while(1)//gameloop
    {
        mon1.moveTo(Position2D(1,1));
        cout << mon1 << endl;
    }
    return 0;
}