#include <iostream>
#include <string>

using namespace std;

class Animal
{
    protected:
    string m_name;

    public:
    Animal(std::string name)
    : m_name(name)
    {}

    public:
    string getName() { return m_name;}

    virtual void speak() const = 0;//pure virtual function
};

// void Animal::speak() const{
//     cout << m_name << "??" << endl;
// }

class Cat : public Animal
{
    public: 
    Cat(string name)
    :Animal(name)
    {}

    void speak() const{
        cout << m_name << "MEow" << endl;
    }
};

class Cow : public Animal
{
    public: 
    Cow(string name)
    :Animal(name)
    {}

    virtual void speak() const{
    cout << m_name << "??" << endl;
}
};

int main()
{
    Cow cow("hello");
    cow.speak();
    return 0;
}