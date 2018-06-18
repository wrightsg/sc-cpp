#ifndef SC_CPP_USER_VALIDATION_MOCK_H
#define SC_CPP_USER_VALIDATION_MOCK_H

#include "gmock/gmock.h"

#include "user_validation.h"

class UserValidationMock : public UserValidation
{
public:
    MOCK_METHOD1(validateUser, bool(const User& user));
};

#endif //SC_CPP_USER_VALIDATION_MOCK_H
