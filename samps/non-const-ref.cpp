#include <iostream>


using namespace std;

int main()
{
    double price = 100;
    double &ref_price = price;
    // change the price to 120
    ref_price = 120;

    cout << "price: " << price << endl;

    // now change the price to 150
    price = 150;

    cout << "ref: " << ref_price << endl;

    return 0;
}