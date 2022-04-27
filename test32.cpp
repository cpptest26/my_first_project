#include <iostream>
#include <string>

using namespace std;

struct Employee //2 + 4 + 8 = 14  --> 2 + (2) + 4 + 8 = 16
{
    short   id;     //2
    int     age;    //4
    double  wage;   //8
};

int main()
{
    Employee emp1;

    cout << sizeof(Employee) <<endl;
   

    return 0;
}