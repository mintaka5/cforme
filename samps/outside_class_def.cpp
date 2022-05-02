#include <iostream>
#include <string>

using namespace std;

class product
{
    string prod_name;
    float weight, price;
    public:
        void mgetdata();
        void mfdisplay();
} item;

void product::mgetdata()
{
    cout << "enter a product name: ";
    cin >> prod_name;
    cout << "enter weight and price: ";
    cin >> weight >> price;
}

void product::mfdisplay()
{
    cout << "product name is " << prod_name << endl;
    cout << "weight is " << weight << endl;
    cout << "and the price is " << price << endl;
}

int main()
{
    product item;
    item.mgetdata();
    item.mfdisplay();

    return 0;   
}