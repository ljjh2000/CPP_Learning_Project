#include "aircraftFactory.hpp"

#include <iostream>

AircraftFactory::AircraftFactory()
{
    init_aircraft_types();
    init_count_airlines();
}

void AircraftFactory::create_aircraft(const AircraftType& type, AircraftManager& aircraftManager,
                                      Tower& tower)
{
    // assert(airport); // make sure the airport is initialized before creating aircraft
    int num_airline           = std::rand() % 8;
    std::string flight_number = airlines[num_airline] + std::to_string(1000 + (rand() % 9000));
    const float angle         = (rand() % 1000) * 2 * 3.141592f / 1000.f; // random angle between 0 and 2pi
    const Point3D start       = Point3D { std::sin(angle), std::cos(angle), 0 } * 3 + Point3D { 0, 0, 2 };
    const Point3D direction   = (-start).normalize();

    while (std::find(number_aircraft.begin(), number_aircraft.end(), flight_number) != number_aircraft.end())
    {
        num_airline   = std::rand() % 8;
        flight_number = airlines[num_airline] + std::to_string(1000 + (rand() % 9000));
    }

    std::unique_ptr<Aircraft> aircraft =
        std::make_unique<Aircraft>(type, flight_number, start, direction, tower);
    // GL::display_queue.emplace_back(aircraft);
    // GL::move_queue.emplace(aircraft);
    aircraftManager.add(std::move(aircraft));
    count_airlines->at(num_airline)++;
}

void AircraftFactory::create_random_aircraft(AircraftManager& aircraftManagert, Tower& tower)
{
    create_aircraft(*(aircraft_types[rand() % 3]), aircraftManagert, tower);
}

void AircraftFactory::init_aircraft_types()
{
    assert(aircraft_types);
    aircraft_types[0] = new AircraftType { .02f, .05f, .02f, MediaPath { "l1011_48px.png" } };
    aircraft_types[1] = new AircraftType { .02f, .05f, .02f, MediaPath { "b707_jat.png" } };
    aircraft_types[2] = new AircraftType { .04f, .10f, .04f, MediaPath { "concorde_af.png" } };
}

void AircraftFactory::init_count_airlines()
{
    std::fill(count_airlines->begin(), count_airlines->end(), 0);
}

int AircraftFactory::get_count_airlines(int index)
{
    return count_airlines->at(index);
}
