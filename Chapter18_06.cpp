#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //<exit>
#include <sstream>

using namespace std;

int main()
{

    if(false)
    {

    }

    if(true)
    {
        ifstream ifs("my_first_file.dat", ios::binary);

        if(!ifs)
        {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        // const unsigned num_data = 10;
        // ifs.write((char*)&num_data, sizeof(num_data));

        // for(int i = 0; i < num_data; ++i)
        // ifs.write((char*)&i, sizeof(i));

        // while (ifs)
        // {
        //     std::string str;
        //     getline(ifs,str);

        //     std::cout << str << endl;
        // }

        // ifs << "Line 1" << endl;
        // ifs << "Line 2" << endl;
        
        
    }

    if(true)
    {
        ifstream ifs("my_first_file.dat");

        if(!ifs)
        {
            cerr << "Cannot open file" << endl;
            exit(1);
        }
    }

    while(ifs)
    {
        std::string str;
        getline(ifs, str);

        std::cout << str << endl;
    }

    unsigned num_data = 0;
    ifs.read((char*)&num_data, sizeof(num_data));

    for(unsigned i = 0; i < num_data; ++i){
        int num;
        ifs.read((char*)&num, sizeof(num));

        std::cout << num << endl;
    }




    return 0;

}