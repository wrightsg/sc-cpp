#ifndef SC_CPP_TURTLE_MOCK_H
#define SC_CPP_TURTLE_MOCK_H

#include "turtle_interface.h"

#include "gmock/gmock.h"

class turtle_mock : public turtle_interface
{
public:
    MOCK_METHOD0(pen_up, void());
    MOCK_METHOD0(pen_down, void());
    MOCK_METHOD1(forward, void(int distance));
    MOCK_METHOD1(turn, void(int degrees));
    MOCK_METHOD2(go_to, void(int x, int y));
    MOCK_CONST_METHOD0(get_x, int());
    MOCK_CONST_METHOD0(get_y, int());
};

#endif //SC_CPP_TURTLE_MOCK_H
