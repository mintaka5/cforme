#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    array<string, 3> thecars = {"BMW", "Volvo", "Ferrari"};

    for(size_t i=0; i<thecars.size(); i++)
    {
        cout << thecars[i] << endl;
    }

    return EXIT_SUCCESS;
}