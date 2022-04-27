#include <iostream>

int getPrice (bool onSale){
    int price;

    if (onSale)
        price = 10;
    else 
        price = 100;

    return price;

}

int main()
{
     using namespace std;
int x = 5;
cout << ((x % 2 == 0) ? "even" : "odd") << endl;

    return 0;
}