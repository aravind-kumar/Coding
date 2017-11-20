#include "time.h"
#include "ps0.h"
#include <iostream>
#include "FlightExamples.h"
#include "graph.h"

using namespace std;

int main()
{ 
   Graph g;
   for(auto&& flight : *deltaFlights) 
   {
      g.AddFlight(flight);
   }
   cout<<(canGetThere ( "LGA", "ABC", deltaFlights ));
   return 0;
 
}
