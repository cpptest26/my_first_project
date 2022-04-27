#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception{
    public:
    const char * what() const noexcept
    {
        return "Custom exception";
    }
};


int main()
{
    try
    {
       
    //  std::string s;
    //  s.resize(-1);

    throw std::runtime_error("Bad thing happened");
    throw CustomException();
      
    }

    // catch(std::length_error & exception)
    // {
    //     std::cout << "Length_Error"<< std::endl;
    //     std::cerr<< exception.what() << std::endl;
    // }

    catch(std::exception & exception)
    {
        std::cout << typeid(exception).name() << std::endl;
        std::cerr<< exception.what() << std::endl;
    }

return 0;
}


    