#include <iostream>
#include <vector>
#include <string>
#include <sstream>


template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}


template <typename T>
bool FromString(const std::string & str, T &x)
{
    std::istringstream isstream(str);
    return (isstream >> x ) ? true : false;
}

int main()
{
    std::string my_str(ToString(3.141592));

    //my_str += std::to_string(128);

    double d;

    if(FromString(my_str, d))
    std::cout <<d << std::endl;
    else 
    std::cout <<"cannot convert string to double" << std::endl;

    std::cout << my_str << std::endl;
  
    return 0;
}