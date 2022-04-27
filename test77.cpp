#include <iostream>

using namespace std;
class Simple
{
    private:
    int m_id;

public:
Simple(int id)
{
    this->setID(id);
    this->m_id;

    cout <<this << endl;

}
void setID(int id) { m_id = id;}
int getID() { return m_id;}
};
int main()
{
    Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2 << endl;

    
   return 0;
}