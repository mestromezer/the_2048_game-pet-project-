#pragma once

#include <time.h>
#include <vector>
#include <iterator>
#include <random>
#include <conio.h>
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

    void SumUp(int i, int j)
    {
        auto P = vector<Plate>::iterator((Plates.at(i)).begin());

        P += j;

        while (P != (Plates.at(i)).end())
        {
            if (P->GetValue() == Plates.at(i).at(j).GetValue())
            {
                Plates.at(i).at(j).SetValue((P->GetValue()) * 2);
                P->SetValue(0);
                break;
            }
            else
                P++;
        }
    }

    void SlideUp()
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                SumUp(i, j);
            }
        }
    }

    void SumDown(int i, int j)
    {
        auto P = vector<Plate>::reverse_iterator((Plates.at(i)).rbegin());

        P += j;

        while (P != (Plates.at(i)).rend())
        {
            if (P->GetValue() == Plates.at(i).at(j).GetValue())
            {
                Plates.at(i).at(j).SetValue((P->GetValue()) * 2);
                P->SetValue(0);
                break;
            }
            else
                P++;
        }
    }

    void SlideDown()
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = Size; j > 0; j--)
            {
                SumDown(i, j);
            }
        }
    }

    void SumLeft(int i, int j)
    {
        unsigned short k = 0;

        while (Plates.at(i).at(j).GetValue() != Plates.at(k).at(j).GetValue())
        {
            if (k == Size)
                return;
            k++;
        }

        Plates.at(i).at(j).SetValue((Plates.at(k).at(j).GetValue()) * 2);
        Plates.at(k).at(j).SetValue(0);
    }

    void SlideLeft()
    {
        for (int j = 0; j < Size; j++)
        {
            for (int i = 0; i < Size; i++)
            {
                SumLeft(i, j);
            }
        }
    }

    void SumRight(int i, int j)
    {
        unsigned short k = Size;

        while (Plates.at(i).at(j).GetValue() != Plates.at(k).at(j).GetValue())
        {
            if (k == Size)
                return;
            k--;
        }

        Plates.at(i).at(j).SetValue((Plates.at(k).at(j).GetValue()) * 2);
        Plates.at(k).at(j).SetValue(0);
    }

    void SlideRight()
    {
        for (int j = 0; j < Size; j++)
        {
            for (int i = 0; i < Size; i++)
            {
                SumRight(i, j);
            }
        }
    }

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

    void AddRand()
    {
        srand((unsigned int)time(0));

        unsigned short ValueToAdd = 2;

        int x = 0;
        int y = 0;

        while (Plates.at(x).at(y).GetValue())
        {
            x = rand() % Size;
            y = rand() % Size;
        }

        Plates.at(x).at(y).SetValue(ValueToAdd);

        Plate::SetNumberOfPlates(unsigned short((Plate::GetNumberOfPlates() + 1)));
    }

public:
    explicit Field(unsigned short Size)
    {
        Plate::SetNumberOfPlates();

        this->Size = Size;
        DeclarePlates();
        InitPlates();
    }

    unsigned short GetSize() const { return this->Size; }

    void Slide(Slides Direction)
    {
        switch (Direction)
        {
        case Up:
            SlideUp();
            break;
        case Down:
            SlideDown();
            break;
        case Left:
            SlideLeft();
            break;
        case Right:
            SlideRight();
            break;
        }
    }

    void Play()
    {
        while (true)
        {
            if (Plate::GetNumberOfPlates() == pow(Size, 2))
            {
                return;
            }

            AddRand();

            cout << (*this);

            cout << "\n\n";
            cout << "\t\"\n\t|" << endl;

            cout << "<-\t->" << endl;

            cout << "\t|\n\t\"" << endl;

            while (_getch() != 1)
            {
                // switch arrows
                break;
            }
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