#pragma once

#include <vector>
#include "Plate.hpp"

using namespace std;

class Field;

ostream &operator<<(ostream &stream, const Field &Object);

enum Slides
{
    Up = 1,
    Down,
    Left,
    Right
};

class Field
{
    vector<vector<Plate>> Plates; // no need in resize => vector
    unsigned short Size;

    void SlideUp();

    void SlideDown();

    void SlideLeft();

    void SlideRight();

    void DeclarePlates()
    {
        Plates.resize(Size);

        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                Plates[i].resize(Size);
            }
        }
    }

    void InitPlates()
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                Plates[i].at(j).SetValue(unsigned short(0));
            }
        }
    }

public:
    explicit Field(unsigned short Size)
    {
        this->Size = Size;
        DeclarePlates();
        InitPlates();
    }

    unsigned short GetSize() const { return this->Size; }

    void Slide(Slides Direction)
    {
        switch (Direction)
        {
        case 1:
            SlideUp();
            break;
        case 2:
            SlideDown();
            break;
        case 3:
            SlideLeft();
            break;
        case 4:
            SlideRight();
            break;
        }
    }

    friend ostream &operator<<(ostream &stream, const Field &Object);
};

ostream &operator<<(ostream &stream, const Field &Object)
{
    for (int i = 0; i < Object.GetSize(); i++)
    {
        for (auto Cell : Object.Plates[i])
        {
            if (Cell.GetValue() != unsigned short(0))
                stream << Cell.GetValue() << "\t";
            else
            {
                stream << "_\t";
            }
        }
        stream << "\n\n\n";
    }

    return stream;
}