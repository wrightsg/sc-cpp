#ifndef SC_CPP_USER_VALIDATION_H
#define SC_CPP_USER_VALIDATION_H

#include "user.h"

class UserValidation
{
public:
    virtual bool validateUser (const User& user) = 0;
};

#endif //SC_CPP_USER_VALIDATION_H
