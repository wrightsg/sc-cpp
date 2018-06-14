#ifndef SC_CPP_ENTITY_H
#define SC_CPP_ENTITY_H

#include <map>

#include "entity_interface.h"

class entity : public entity_interface
{
public:
    entity ()
        : _resources()
    {
    }

    int get_resource (resource r) const override
    {
        return _resources.at(r);
    }

private:
    std::map<resource, int> _resources;
};

#endif //SC_CPP_ENTITY_H
