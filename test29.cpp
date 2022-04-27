#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    cout << "Your name ? : ";
    int name;
    cin >> name;
    //std::getline(std::cin, name);

    cout << "Your age ? : ";
    string age;
    cin >> age;
    //std::getline(std::cin, age);

   //std::cin.ignore(32767, '\n');

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << name << " " << age << endl;


    return 0;
}