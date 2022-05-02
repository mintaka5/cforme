#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float num, square_root;

    cout << "enter a number to get square root: *";
    cin >> num;
    square_root = sqrt(num);
    cout << "square root  of " << num << " is " << square_root << endl;

    return 0;
}