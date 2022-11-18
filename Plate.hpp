#pragma once

class Plate
{
    unsigned short Value;

public:
    static unsigned short NumberOfPlates;

    explicit Plate(unsigned short Value = 0)
    {
        this->Value = Value;
    }

    static void SetNumberOfPlates(unsigned short Num = unsigned short(0))
    {
        NumberOfPlates = Num;
    }

    static unsigned short GetNumberOfPlates() { return NumberOfPlates; }

    void SetValue(unsigned short Value) { this->Value = Value; }

    unsigned short GetValue() const { return this->Value; }
};

// Plate::NumberOfPlates = 0;
