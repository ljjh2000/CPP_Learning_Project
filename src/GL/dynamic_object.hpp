#pragma once

#include <unordered_set>

namespace GL {

class DynamicObject;

inline std::unordered_set<DynamicObject*> move_queue;

class DynamicObject
{

public:
    bool destroye = false;
    virtual ~DynamicObject() {}

    virtual bool move() = 0;
    virtual bool doDestroye() { return destroye; }
};

} // namespace GL
