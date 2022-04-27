#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    try
    {
        
            if(argc != 2)
            {
                std::cerr << "Usage: client <host>" << std::endl;
                return 1;

            }

            tcp::iostream stream(argv[1], std::to_string(int(13)));//port number13
            if(!stream)
            {
                std::cout << "unable to connect: " << stream.error().message() << std::endl;
                return 1;

            }

            stream << "Hello from client";
            stream << std:: endl;

            std::string line;
            std::getline(stream, line);
            std::cout << line << std::endl;
        }

        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;

        }

        return 0;
    
    
}