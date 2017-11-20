// You can include more header files here.

#include <list>
#include "Flight.h"
#include "graph.h"

using namespace std;

// Your forward declarations (etc) go here.

// canGetThere : String String ListOfFlight -> Boolean
// GIVEN: the names of two airports, ap1 and ap2 (respectively),
//     and a ListOfFlight that describes all of the flights a
//     traveller is willing to consider taking
// RETURNS: true if and only if it is possible to fly from the
//     first airport (ap1) to the second airport (ap2) using
//     only the given flights
// EXAMPLES:
//     canGetThere ( "06N", "JFK", panAmFlights )  =>  false
//     canGetThere ( "LGA", "PDX", deltaFlights )  =>  true

bool search(string src,string dst,Graph graph,unsigned int startTime)
{
    Flights alldestinations = graph.GetAllFlights(src,dst);
    Flights nonVisitedFlights = GetAllNonVisitedFlights(alldestinations); 
    Flights flightsWithDepartureTime = GetAllFlightsWithDepartureTime(startTime,nonVisitedFlights);
    if(flightsWithDepartureTime.size()>0)
    {
        return true;
    }
    else
    {
        Airports destinationAirports = graph.GetAirports(src);
        for(auto&& airport: destinationAirports)
        {
           Flights allFlights = airport.getFlights();
           Flights nonVisitedFlights = GetAllNonVisitedFlights(allFlights); 
           Flights flightsWithDepartureTime = GetAllFlightsWithDepartureTime(startTime,nonVisitedFlights);

           for(auto&& flight : flightsWithDepartureTime)
           {
                 unsigned int waitTime = (flight->departureTime() - startTime); 
                 unsigned int travelTime = (flight->arrivalTime() - flight->departureTime()); 
                 unsigned int newStartTime = startTime + waitTime + travelTime;
                 string airportName = airport.GetAirportName();
                 graph.MarkFlightAsVisited(src,airportName,flight);
                 if(search(airportName,dst,graph,newStartTime))
                 {
                      return true;
                 }
           }
        }
      
    }
    return false;
}

bool canGetThere (string ap1,
                  string ap2,
                  list<Flight>* flights) {
     Graph graph;
     for(auto&& flight : *flights)
     {
        graph.AddFlight(flight);
     }
     return search(ap1,ap2,graph,0);
     
}

// fastestItinerary : String String ListOfFlight -> ListOfFlight
// GIVEN: the names of two airports, ap1 and ap2 (respectively),
//     and a ListOfFlight that describes all of the flights a
//     traveller is willing to consider taking
// WHERE: it is possible to fly from the first airport (ap1) to
//     the second airport (ap2) using only the given flights
// RETURNS: a list of flights that tells how to fly from the
//     first airport (ap1) to the second airport (ap2) in the
//     least possible time, using only the given flights
// ALLOCATION: the list returned by this function is freshly
//     allocated and should be deallocated by the caller;
//     the flights in that list are from the given list and
//     haven't been copied
// EXAMPLES:
//     fastestItinerary ("LGA", "PDX", deltaFlights)
// =>  [ makeFlight ("Delta 0121", "LGA", "MSP", 1100, 1409),
//       makeFlight ("Delta 2163", "MSP", "PDX", 1500, 1902) ]

list<Flight>* fastestItinerary (string ap1, string ap2,
                                list<Flight>* flights) {
  return NULL;
  // Your code goes here.
}

// travelTime : String String ListOfFlight -> PosInt
// GIVEN: the names of two airports, ap1 and ap2 (respectively),
//     and a ListOfFlight that describes all of the flights a
//     traveller is willing to consider taking
// WHERE: it is possible to fly from the first airport (ap1) to
//     the second airport (ap2) using only the given flights
// RETURNS: the number of minutes it takes to fly from the first
//     airport (ap1) to the second airport (ap2), including any
//     layovers, by the fastest possible route that uses only
//     the given flights
// EXAMPLES:
//     travelTime ( "LGA", "PDX", deltaFlights )  =>  482

int travelTime (string ap1,
                string ap2,
                list<Flight>* flights) {
  // Your code goes here.
  return -1;
}

// Your help functions (etc) go here.
