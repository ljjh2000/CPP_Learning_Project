#include "aircraftManager.hpp"

#include "GL/dynamic_object.hpp"

bool AircraftManager::move()
{
    for (auto it = aircrafts.begin(); it != aircrafts.end();)
    {
        if ((*it)->doDestroye())
        {
            auto aircraft = std::move(*it);
            it            = aircrafts.erase(it);
            aircraft.reset();
        }
        else
        {
            (*it)->move();
            it++;
        }
    }
    /*aircrafts.erase(std::remove_if(aircrafts.begin(), aircrafts.end(), [](auto it) { return (*it).move();
       }), aircrafts.end());*/
    return false;
}

void AircraftManager::add(std::unique_ptr<Aircraft> aircraft)
{
    aircrafts.emplace_back(std::move(aircraft));
}
