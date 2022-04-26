#include <iostream>

using namespace std;

// declaring function prototype
float add(float, float);

float add(float a, float b)
{
    float sum;
    sum = a + b;

    return sum;
}

int main()
{
    float num1, num2, sum;

    cout << "enter 2 numbers: ";
    cin >> num1 >> num2;

    // call the function
    sum = add(num1, num2);

    cout << "sum: " << sum << endl;

    return EXIT_SUCCESS;
}