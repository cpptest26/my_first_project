#include <iostream>

using namespace std;

void doSomething();

void doSomething(int &lref)
{
    cout << "L-value ref" << endl;
}

void doSomething(int &&ref)
{
    cout << "R-value ref" << endl;
}


int getResult()
{
    return 100*100;
}

int main()
{
    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    int &lr1 = x;
    //int &lr2 = cx;
    //int &lr3 = 5;

    const int &lr4 = x;
    const int &lr5 = cx;
    const int &lr6 = 5;

    //R-value references

    int &&rr3 = 5;

    cout << rr3 << endl;
    rr3 = 10;
    cout << rr3 << endl;

    const int &&rr6 = 5;

    doSomething(x);
    doSomething(5);
    doSomething(getResult());

    return 0;

}