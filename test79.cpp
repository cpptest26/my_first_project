#include <iostream>
#include <string>


using namespace std;

class Something
{
    public:
    string m_value = "default";

    const string& getValue() const {
        cout << "const version" << endl;
        return m_value;}

    string& getValue() { 
        cout <<"non-c" <<endl;
        return m_value;}
    

};


int main()
{
    Something something;
    something.getValue() = 10;

    const Something something2;
    something2.getValue();

    

    return 0;
}