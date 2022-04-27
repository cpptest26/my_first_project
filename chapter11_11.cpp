#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}
int subtract(int x, int y)
{
    return x - y;
}
int multiply(int x, int y)
{
    return x * y;
}
int main()
{
    int x , y;
    cin >> x >> y;

    int op;
    cout << "0: add, 1: subtreact, 2: multiply" << endl;
    cin >>op;

    // int result;
    // switch(op)
    // {
    //     case0 : result = add(x,y); 
    //     break;
    //     case1 : result = subtract(x,y); 
    //     break;
    //     case2 : result = multiply(x,y); 
    //     break;
    // }

    int(*func_ptr)(int, int) = nullptr;

    switch(op)
    {
        case0 : func_ptr = add; 
        break;
        case1 : func_ptr = subtract; 
        break;
        case2 : func_ptr = multiply; 
        break;
    }


    cout << func_ptr(x,y) << endl;
    return 0;
}
