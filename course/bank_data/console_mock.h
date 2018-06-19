#ifndef SC_CPP_CONSOLE_MOCK_H
#define SC_CPP_CONSOLE_MOCK_H

#include "gmock/gmock.h"

#include "console.h"

class ConsoleMock : public Console
{
public:
    MOCK_METHOD1(print, void(const std::string& string));
};

#endif //SC_CPP_CONSOLE_MOCK_H
