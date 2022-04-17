#pragma once

#include "aircraft.hpp"
#include "aircraftManager.hpp"
#include "aircraft_types.hpp"
#include "tower.hpp"

#include <iostream>
#include <string>
#include <vector>

constexpr size_t NUM_AIRCRAFT_TYPES = 3;

class AircraftFactory
{
private:
    const std::string airlines[8] = { "AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY" };
    AircraftType* aircraft_types[NUM_AIRCRAFT_TYPES] {};

    std::vector<std::string> number_aircraft;
    std::vector<int> count_airlines[8];

    void init_count_airlines();
    void create_aircraft(const AircraftType& type, AircraftManager& aircraftManager, Tower& tower);

public:
    void init_aircraft_types();
    void create_random_aircraft(AircraftManager& aircraftManager, Tower& tower);
    int get_count_airlines(int index);
    AircraftFactory();
    ~AircraftFactory();
};
