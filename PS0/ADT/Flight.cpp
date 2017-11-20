#include <string>
#include "Flight.h"

using namespace std;

/* Factory method for creating flights.
 * 
 * Given:
 *     the name of the flight
 *     the name of the airport from which the flight departs
 *     the name of the airport at which the flight arrives
 *     the time of departure (in UTC)
 *     the time of arrival (in UTC)
 *
 * Returns:
 *     pointer to an object that encapsulates the given information
 */

Flight makeFlight (string name, string ap1, string ap2,
                   int departs, int arrives) {
  Flight flight = new Flight_();
  flight->name_ = name;
  flight->ap1_ = ap1;
  flight->ap2_ = ap2;
  flight->departs_ = departs;
  flight->arrives_ = arrives;
  return flight;
}

string Flight_::flightName () {
  return name_;
}

string Flight_::departsFrom () {
  return ap1_;
}

string Flight_::arrivesAt () {
  return ap2_;
}

int Flight_::departureTime () {
  return departs_;
}

int Flight_::arrivalTime () {
  return arrives_;
}

bool Flight_::sameFlight (Flight flight) {
  return
    (flightName().compare (flight->flightName()) == 0) &&
    (departsFrom().compare (flight->departsFrom()) == 0) &&
    (arrivesAt().compare (flight->arrivesAt()) == 0) &&
    (departureTime() == flight->departureTime()) &&
    (arrivalTime() == flight->arrivalTime());
}

bool Flight_::operator== (Flight flight) {
  return sameFlight (flight);
}

Flights GetAllNonVisitedFlights(Flights flights)
{
   Flights nonVisitedFlights;
   for(auto&& flight: flights)
   {
      if(flight->isvisited() == false)
      {
          nonVisitedFlights.push_back(flight);
      }
    } 
    return nonVisitedFlights;
}

Flights GetAllFlightsWithDepartureTime(unsigned int time,Flights flights)
{
   Flights filteredFlights;
   for(auto&& flight: flights)
   {
      if(flight->departureTime() >= time)
      {
          filteredFlights.push_back(flight);
      }
    } 
    return filteredFlights;
} 
