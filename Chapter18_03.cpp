#include <iostream>
#include <sstream>
using namespace std;

int main()
{
//     stringstream os;

//     // int i = 12345;
//     // double d = 67.89;

//     // os << i << " " << d;

//     os << "12345 67.89";
    

//    os.clear();

//    os << "Hello";

//    cout <<os.str() << endl;

int hours, minutes, seconds;
char temp;

string log = "05:12:48";
istringstream iss(log);
iss >> hours >> temp >> minutes >> temp >> seconds;


    return 3600 * hours + 60 * minutes + seconds;
}
