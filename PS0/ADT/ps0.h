#ifndef PS0_H
#define PS0_H

#include <string>
#include <list>
#include "Flight.h"

using namespace std;

extern bool canGetThere (string ap1,
			 string ap2,
			 list<Flight>* flights);

extern list<Flight>* fastestItinerary (string ap1, string ap2,
				       list<Flight>* flights);

extern int travelTime (string ap1,
		       string ap2,
		       list<Flight>* flights);

#endif
