#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    char source[] = "Copy this!";
    char dest[50];
    strcpy(dest, source);
    //strcat()
    //strcmp()

    if(strcmp(source,dest) ==0)
    {

    }

    cout <<strcmp( source, dest) << endl;

    return 0;

}