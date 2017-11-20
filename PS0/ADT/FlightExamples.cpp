#include <string>
#include <list>
#include "Flight.h"
#include "FlightExamples.h"

using namespace std;

// Returns a list of flights extracted from schedules published
// by Delta Airlines.

list<Flight>* initDeltaFlights() {
  list<Flight>* result = new list<Flight>();

  // C++ interprets a leading 0 to mean octal, so there aren't
  // any leading zeroes here.

  result->push_back (makeFlight ("Delta 0121", "LGA", "MSP", 1100, 1409));
  result->push_back (makeFlight ("Delta 2163", "MSP", "PDX", 1500, 1902));
  result->push_back (makeFlight ("Delta 2079", "BOS", "DTW", 1035, 1259));
  result->push_back (makeFlight ("Delta 1523", "BOS", "DTW", 2158,   20));
  result->push_back (makeFlight ("Delta 0058", "BOS", "LHR",   44,  720));
  result->push_back (makeFlight ("Delta 2531", "BOS", "LAX", 1317, 2020));
  result->push_back (makeFlight ("Delta 2532", "BOS", "LAX", 2250,  555));
  result->push_back (makeFlight ("Delta 1959", "BOS", "MSP", 1050, 1417));
  result->push_back (makeFlight ("Delta 1894", "BOS", "MSP", 1355, 1730));
  result->push_back (makeFlight ("Delta 2391", "BOS", "MSP", 2135,  105));
  result->push_back (makeFlight ("Delta 2734", "BOS", "LGA", 1100, 1230));
  result->push_back (makeFlight ("Delta 3550", "BZN", "LAX", 2020, 2302));
  result->push_back (makeFlight ("Delta 1601", "DEN", "DTW", 1305, 1611));
  result->push_back (makeFlight ("Delta 0916", "DEN", "DTW", 2332,  219));
  result->push_back (makeFlight ("Delta 0010", "DEN", "LHR", 2030,  945));
  result->push_back (makeFlight ("Delta 5703", "DEN", "LAX", 1404, 1715));
  result->push_back (makeFlight ("Delta 5743", "DEN", "LAX",   34,  331));
  result->push_back (makeFlight ("Delta 2437", "DTW", "BOS", 1345, 1546));
  result->push_back (makeFlight ("Delta 0158", "DTW", "BOS", 1700, 1855));
  result->push_back (makeFlight ("Delta 1700", "DTW", "BOS", 2240,   42));
  result->push_back (makeFlight ("Delta 1511", "DTW", "DEN", 1330, 1651));
  result->push_back (makeFlight ("Delta 1645", "DTW", "DEN", 1711, 2038));
  result->push_back (makeFlight ("Delta 1706", "DTW", "LAX", 1320, 1845));
  result->push_back (makeFlight ("Delta 0249", "DTW", "MSP", 1500, 1707));
  result->push_back (makeFlight ("Delta 2359", "DTW", "MSP", 1715, 1920));
  result->push_back (makeFlight ("Delta 2476", "DTW", "MSP",  110,  318));
  result->push_back (makeFlight ("Delta 0059", "LHR", "BOS",  920, 1726));
  result->push_back (makeFlight ("Delta 4378", "LHR", "BOS", 1645,   20));
  result->push_back (makeFlight ("Delta 0011", "LHR", "DEN", 1255,  220));
  result->push_back (makeFlight ("Delta 0302", "LAX", "BOS", 1625, 2214));
  result->push_back (makeFlight ("Delta 5732", "LAX", "BZN",   30,  318));
  result->push_back (makeFlight ("Delta 4574", "LAX", "DEN", 1735, 2007));
  result->push_back (makeFlight ("Delta 5700", "LAX", "DEN",   10,  245));
  result->push_back (makeFlight ("Delta 2077", "LAX", "PDX", 1735, 2009));
  result->push_back (makeFlight ("Delta 1728", "MSP", "BOS", 1600, 1851));
  result->push_back (makeFlight ("Delta 2305", "MSP", "BZN",  221,  513));
  result->push_back (makeFlight ("Delta 1609", "MSP", "DEN", 2035, 2252));
  result->push_back (makeFlight ("Delta 1836", "MSP", "DTW", 1224, 1415));
  result->push_back (makeFlight ("Delta 1734", "MSP", "DTW", 1755, 1941));
  result->push_back (makeFlight ("Delta 0592", "MSP", "LGA", 1730, 2017));
  result->push_back (makeFlight ("Delta 2734", "LGA", "BOS", 1100, 1208));
  result->push_back (makeFlight ("Delta 1294", "LGA", "DEN", 1310, 1754));
  result->push_back (makeFlight ("Delta 0879", "LGA", "DTW", 1410, 1620));
  result->push_back (makeFlight ("Delta 1422", "LGA", "MSP", 1500, 1822));
  result->push_back (makeFlight ("Delta 0950", "PDX", "LAX", 1418, 1655));
  result->push_back (makeFlight ("Delta 2077", "PDX", "LAX", 2045, 2314));
  result->push_back (makeFlight ("Delta 2831", "PDX", "LAX", 2346,  225));
  result->push_back (makeFlight ("Delta 2167", "PDX", "MSP", 2200,  120));

  return result;
}

list<Flight>* panAmFlights = new list<Flight>();
list<Flight>* deltaFlights = initDeltaFlights();
