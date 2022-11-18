#include <iostream>
#include <string>
#include "Plate.hpp"
#include "Field.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned short Size = {10};

    Field a(Size);

    a.Play();

    return 0;
}
