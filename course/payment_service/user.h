#ifndef SC_CPP_USER_H
#define SC_CPP_USER_H

class User
{
public:
    User (int id)
        : _id(id)
    {
    }

    bool operator== (const User& other) const
    {
        return _id == other._id;
    }

private:
    int _id;
};

#endif //SC_CPP_USER_H
