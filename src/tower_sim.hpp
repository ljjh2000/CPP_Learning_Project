#pragma once
#include "aircraftManager.hpp"

class Airport;
struct AircraftType;

class TowerSimulation
{
private:
    bool help                        = false;
    Airport* airport                 = nullptr;
    AircraftManager* aircraftManager = new AircraftManager {};

    TowerSimulation(const TowerSimulation&) = delete;
    TowerSimulation& operator=(const TowerSimulation&) = delete;

    void create_aircraft(const AircraftType& type);
    void create_random_aircraft();

    void create_keystrokes();
    void display_help();

    void init_airport();
    void init_aircraftManager();

public:
    TowerSimulation(int argc, char** argv);
    ~TowerSimulation();

    void launch();
};
