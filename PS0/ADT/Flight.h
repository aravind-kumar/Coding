#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

using namespace std;

typedef class Flight_* Flight;

class Flight_
{
 public:
  string flightName ();     // returns name of this flight
  string departsFrom ();    // returns name of the airport it departs
  string arrivesAt ();      // returns name of the airport it goes to
  int departureTime ();     // returns time (in UTC, see below) of departure
  int arrivalTime ();       // returns time (in UTC, see below) of arrival
  bool sameFlight (Flight); // returns true if that flight equals this one
  bool operator== (Flight); // delegates to sameFlight
  friend Flight makeFlight (string, string, string, int, int);
  void setVisited(bool value) { visited_= value;}
  bool isvisited() { return visited_== true;}
 private:
  string name_;  // the name of this flight
  string ap1_;   // the airport from which this flight departs
  string ap2_;   // the airport at which this flight arrives
  int departs_;  // the time of departure, in UTC (see below)
  int arrives_;  // the time of arrival, in UTC (see below)
  bool visited_;
};

struct DeptTimeCompare {
  bool operator() (const Flight& lhs, const Flight& rhs) const
  {return lhs->departureTime()<rhs->departureTime();}
};

typedef vector<Flight> Flights;


// UTC times are less than 2400, their two low-order
// digits are less than 60 and indicate minutes, and
// their higher-order digits indicate hours.

/*
 * Factory method for creating flights.
 * Given:
 *     the name of the flight
 *     the name of the airport from which the flight departs
 *     the name of the airport at which the flight arrives
 *     the time of departure (in UTC)
 *     the time of arrival (in UTC)
 * Returns: an object that encapsulates the given information
 */

Flight makeFlight (string name, string ap1, string ap2,
                   int departs, int arrives);

Flights GetAllNonVisitedFlights(Flights flights);

Flights GetAllFlightsWithDepartureTime(unsigned int time,Flights flights);
 
#endif
