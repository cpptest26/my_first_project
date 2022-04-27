#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  // try, catch, throw
   
    try{
        throw std::string("My error message");
    }
    catch (int x)
    {
        cout << "Integer " << x << endl;
    }

    catch (double x)
    {
        cout << "Double " << x << endl;
    }

    catch (const char *error_message)
    {
        cout << "Char * " << error_message << endl;
    }


    catch (std::string error_message)
    {

        cout << error_message << endl;
    }

 return 0;
}



