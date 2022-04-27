#include <iostream>

using namespace std;

int main()
{
   char name [] = "JACK jack";
   
   char *ptr = name;

   const int n_name = sizeof(name) / sizeof(name[0]);

   for(int i = 0; i < n_name ; ++i)
   {
       cout << *(ptr +i);
   }
    return 0;
    
}