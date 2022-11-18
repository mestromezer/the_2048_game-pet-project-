#include <iostream>
#include <string>
#include "Plate.hpp"
#include "Field.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Hello, world!" << endl;

    unsigned short Size = {10};

    Field a(Size);

    cout << a;

    return 0;
}
