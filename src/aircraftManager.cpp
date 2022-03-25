#include "aircraftManager.hpp"

#include "GL/dynamic_object.hpp"

void AircraftManager::move()
{
    for (auto it = aircrafts.begin(); it != aircrafts.end();)
    {
        (*it)->move();
    }
}

void AircraftManager::add(std::unique_ptr<Aircraft> aircraft)
{

    std::cout << aircrafts.size() << std::endl;

    aircrafts.emplace_back(std::move(aircraft));
    // std::cout << aircrafts.size() << std::endl;
}
