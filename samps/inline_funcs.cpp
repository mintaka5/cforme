#include <iostream>

using namespace std;

// declare an inline function
inline int area(int l, int w)
{
    return l * w;
}

int main()
{
    cout << "the area of a rectangle 3x5 " << area(3, 5) << endl;

    return 0;
}