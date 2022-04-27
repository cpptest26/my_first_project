#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
    try
    {
    
            boost::asio::io_service io_service;
            tcp::endpoint endpoint(tcp::v4(),13);
            tcp::acceptor acceptor(io_service, endpoint);

            std::cout << "Server started" << std::endl;

            for(;;)//while(true)
            {
                const std::string message_to_send = "Hello From Server";

                boost::asio::ip::tcp::iostream stream;

                std::cout << "Check 1" << std::endl;

                boost::system::error_code ec;
                acceptor.accept(*stream.rdbuf(), ec);

                std::cout << "Check 2" << std::endl;//check2내려 왔다가 다시 for문

                if(!ec)
                {
                    std::string line;
                    std::getline(stream, line);
                    std::cout << line << std::endl;

                    stream << message_to_send;
                    stream << std::endl;


                }
            }
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
    
}