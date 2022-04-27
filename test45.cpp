#include <iostream>
#include <typeinfo>

using namespace std;

struct Something
{
    int a, b, c, d;
};

int* doSomething( int* ptr_a)
{

}

int main()
{
    int x = 5;
    double d = 1.0;
    
    //typedef int* pint;
    int * ptr_x;

    double *ptr_d;

   //pint ptr_x = &x, ptr_y = &y;
    
    cout << ptr_x << endl;
    cout << *ptr_x << endl;

    cout << ptr_d << endl;
    cout << *ptr_d << endl;

    cout << sizeof(x) << endl;
    cout << sizeof(d) << endl;

    cout << sizeof(&x) << " " << sizeof(ptr_x)<<  endl;
    cout << sizeof(&d) << " " << sizeof(ptr_d)<<  endl;

    Something ss;
    Something *ptr_s;

    cout << sizeof(Something) << endl;
    cout << sizeof(ptr_s) << endl;



return 0;

    

}