#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m;

int main(void)
{
    // decalring local variables
    int x, y;

    // initialization of the variables
    x = 20;
    y = 15;
    m = x + y;

    cout << "m: " << m << endl;

    string cars[3] = {"BMW", "Ferrari", "Red Bull"};
    int nums[5] = {5, 10, 15, 20, 25};

    cout << "nums[1]: " << nums[1] << endl;

    for(int i=0; i<size(cars); i++)
    {
        cout << "car: " << cars[i] << endl;
    }

    char test_str[] = "value is soul!";
    string test_str2 = "value is soul!";
    string test_str3 = string(test_str);

    cout << "char: " << test_str << endl;
    cout << "string: " << test_str2.c_str() << endl;
    cout << "char arr to string: " << test_str3 << endl;

    return 0;
}