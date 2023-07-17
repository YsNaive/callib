#ifndef CALLIB_GRAPHOBJECT_H
#define CALLIB_GRAPHOBJECT_H

#include <string>
#include <map>
#include <iostream>
#include "callibcore.h"

namespace callib {
    class GraphObject {
    public:
        virtual E_GraphType getType() const = 0;
        virtual std::string getTypeName() const;

    };
} // namespace callib

#endif // CALLIB_GRAPHOBJECT_H
