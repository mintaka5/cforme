#include <iostream>

using namespace std;

int main()
{
    int test_arr[3][3] = {
        {2, 3, 4},
        {4, 6, 8},
        {6, 4, 6}
    };

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << test_arr[i][j] << "";
        }

        cout << "\n";
    }

    return 0;
}