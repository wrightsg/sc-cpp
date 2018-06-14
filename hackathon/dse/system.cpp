#include "system.h"

int get_resource_total (const std::vector<const entity_interface*>& entities, resource r)
{
    int total = 0;
    for (const auto& entity : entities) {
        total += entity->get_resource(r);
    }
    return total;
}