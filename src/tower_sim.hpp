#pragma once
#include "GL/opengl_interface.hpp"
#include "aircraftFactory.hpp"
#include "aircraftManager.hpp"
#include "img/media_path.hpp"

#include <ctime>

struct ContextInitializer
{

public:
    ContextInitializer(int argc, char** argv)
    {
        MediaPath::initialize(argv[0]);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        GL::init_gl(argc, argv, "Airport Tower Simulation");
    }
};

class Airport;
struct AircraftType;

class TowerSimulation
{
private:
    ContextInitializer context_initializer;
    bool help        = false;
    Airport* airport = nullptr;

    AircraftManager aircraftManager {};
    AircraftFactory aircraftFactory {};

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
