#ifndef SC_CPP_ENTITY_INTERFACE_H
#define SC_CPP_ENTITY_INTERFACE_H

#include "resource.h"

class entity_interface
{
public:
    virtual ~entity_interface () = default;

    virtual int get_resource (resource r) const = 0;
};

#endif //SC_CPP_ENTITY_INTERFACE_H
