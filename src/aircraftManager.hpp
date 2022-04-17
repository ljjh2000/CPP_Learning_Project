#pragma once

#include "GL/dynamic_object.hpp"
#include "aircraft.hpp"

#include <vector>

class AircraftManager : public GL::DynamicObject
{

public:
    bool move() override;
    void add(std::unique_ptr<Aircraft> aircraft);

private:
    std::vector<std::unique_ptr<Aircraft>> aircrafts;
};