#ifndef SC_CPP_ENTITY_MOCK_H
#define SC_CPP_ENTITY_MOCK_H

#include "gmock/gmock.h"

#include "entity_interface.h"

class entity_mock : public entity_interface
{
public:
    MOCK_CONST_METHOD1(get_resource, int(resource r));
};

#endif //SC_CPP_ENTITY_MOCK_H
