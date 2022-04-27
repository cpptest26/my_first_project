#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend
{
public:
string m_name;
string address;
int age;
double height;
double weight;

void print()
{
    cout << m_name << " " << address <<" " << age <<  " " << height << " " << weight << " " << endl;
}

};


int main(){

    Friend jj{"jack jack" , "Uptown" , 2, 30, 10 };

    jj.print();
    
    vector<Friend> my_friends;
    my_friends.resize(2);




    /*
    vector<string> name_vec;
    vector<string> addr_vec;
    vector<int> age_vec;
    vector<double> height_vec;
    vector<double> weight_vec;
    */
    
    
    return 0;
}