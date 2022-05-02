#include <iostream>

using namespace std;

int main()
{
    int num = 12;
    int *ptr;
    // assign memory address to pointer variable
    ptr = &num;
    cout << "the value of `num` is ";
    cout << num << endl;

    cout << "the memory address stored in `ptr` is ";
    cout << ptr << endl;

    cout << "the value of `*ptr` is ";
    cout << *ptr << endl;

    return 0;
}