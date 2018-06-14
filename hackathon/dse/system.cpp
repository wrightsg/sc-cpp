#include "system.h"

#include <algorithm>

int get_resource_total (const std::vector<const entity_interface*>& entities, resource r)
{
    return std::accumulate(entities.cbegin(), entities.cend(), 0, [&r](int total, const entity_interface* e){
        return total + e->get_resource(r);
    });
}