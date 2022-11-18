#pragma once

/*struct Position
{
    short x;
    short y;
    Position(short x = -1, short y = -1)
    {
        this->x = x;
        this->y = y;
    }
};*/

class Plate
{
    static unsigned short NumberOfPlates;

    unsigned short Value; // unsigned short 0 - 65,535
    // Position MyPosition;

public:
    explicit Plate(unsigned short Value = 0)
    {
        this->Value = Value;
    }

    void SetValue(unsigned short Value) { this->Value = Value; }

    unsigned short GetValue() const { return this->Value; }

    /*explicit Plate(unsigned short Value, short x, short y)
    {
        this->Value = Value;
        MyPosition = {x, y};
        NumberOfPlates += 1;
    }*/
};