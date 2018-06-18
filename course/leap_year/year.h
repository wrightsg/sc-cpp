#ifndef SC_CPP_YEAR_H
#define SC_CPP_YEAR_H

class Year
{
public:
    Year (int number)
        : _number(number)
    {
    }

    bool isLeapYear () const
    {
        if (can_be_divided_by(100)) {
            return can_be_divided_by(400);
        }
        if (can_be_divided_by(4)) {
            return true;
        }
        return false;
    }

    static bool isLeapYear (int number)
    {
        return Year(number).isLeapYear();
    }

private:
    int _number;

    bool can_be_divided_by (int divisor) const
    {
        return _number % divisor == 0;
    }
};

#endif //SC_CPP_YEAR_H
