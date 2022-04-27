#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// void doSomething()
// {
//     //Resource *res = new Resource;//dull pointer

//     try{
//     AutoPtr<Resource> res = new Resource;

//     if(true)
//     {
//         throw -1;  
//     }  

//     //delete res; 
// }
//     catch(...)
//     {

//     }
// }

int main()
{

    //doSomething();
{
    AutoPtr<Resource> res1(new Resource);
    AutoPtr<Resource> res2;
 
   //doSomething(res1);


    cout << std::boolalpha;

    cout << res1.m_ptr << endl;
    cout << res1.m_ptr << endl;

    res2 = res1;

    cout << res1.m_ptr << endl;
    cout << res1.m_ptr << endl;
}
// syntax vs semantics
 



    return 0;
}