#ifndef SC_CPP_SYSTEM_H
#define SC_CPP_SYSTEM_H

#include <vector>

#include "entity_interface.h"
#include "resource.h"

int get_resource_total (const std::vector<const entity_interface*>& entities, resource r);

#endif //SC_CPP_SYSTEM_H
