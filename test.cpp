#include <iostream> 
using namespace std;


void doSomething (int x) 
{ 
  x= 123;
cout << "dosomething" << x << endl; //#2
}

int main()
{ 
 int x = 0;
 cout << "intmain" << x << endl; //#1
 doSomething(x);
 cout << "dosomethoing2" << x << endl; //#3
 return 0;
 }