#ifndef GRAPH_H
#define GRAPH_H

#include "Flight.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Airport
{
    private:
      string m_name;
      Flights m_flights;
    public:
      Airport(string name)
      {
           m_name = name;
      }
      
      void SetAirportName(string name)
      {
         m_name=name;
      }
    
      string GetAirportName() { return m_name;}

      void AddFlight(Flight newFlight)
      {
         //cout<<"\n Adding Flight to Airport" <<m_name;
       	 m_flights.push_back(newFlight);
      }
      
      Flights getFlights() 
      {
          return m_flights;
      }
};

typedef vector<Airport> Airports;

class Graph
{
   unordered_map<string,Airports> graph;

   public:

   void AddFlight(Flight newFlight)
   {
      string src = newFlight->departsFrom();  
      string dst = newFlight->arrivesAt();  
      //cout<<"\n Source is "<<src;
      //cout<<"\n Destination is "<<dst;
      if(graph.find(src) != graph.end())
      {
          bool foundDst = false;
          //cout<<"\n Found Source";
          Airports destinations = graph[src];
          for(auto&& airport : destinations)
          {
               if(airport.GetAirportName() == dst)
               {
                   airport.AddFlight(newFlight);
                   foundDst = true;
                   //cout<<"\n Found Destination";
                   graph[src] = destinations;
                   break;
               } 
          }
          if(foundDst == false)
          {
             Airport newAirport(dst);
             newAirport.AddFlight(newFlight); 
             Airports old = graph[src];
             old.push_back(newAirport);
             graph[src] = old;
          }
      }
      else 
      {
         Airport newAirport(dst);
         newAirport.AddFlight(newFlight); 
         Airports newAirports={newAirport};
         graph[src] = newAirports; 
      }
   }
   
   Airports GetAirports(string key)
   {
         Airports destinations;
         if(graph.find(key) != graph.end())
         {
             destinations=graph[key];
         }
         return destinations;
   }
    
   Flights GetAllFlights(string from,string to)
   {
         Flights destinationFlights;
         if(graph.find(from) != graph.end())
         {
            for(auto&& airport: graph[from])
            {
                if(airport.GetAirportName() == to)
                {
                    destinationFlights=airport.getFlights();
                }
            } 
         }
         return destinationFlights;
   }
   
   void MarkFlightAsVisited(string key,string dst,Flight flight)
   {
         if(graph.find(key) !=  graph.end())
         {
             for(auto&& airport : graph[key])
             {
                   if(airport.GetAirportName() == dst)
                   {
                      Flights flights = airport.getFlights();
                      for(auto&& f : flights)
                      {
                          if(f == flight)
                          {
                              f->setVisited(true); 
                          }
                      }
                   }
             }
         }
   }
   
   void PrintGraph()
   {
     unordered_map<string,Airports>::iterator it = graph.begin();
     int srcCount=1;
     for(; it!=graph.end() ; ++it)
     {
         cout<<"\n"<<srcCount<<"."<<"The Src Node is "<<(*it).first;
         ++srcCount;
         Airports temp = (*it).second;
         int destCount = 1;
         for(auto&& airport : temp)
         {
             cout<<"\n"<<destCount<<"."<<"Destination is " <<airport.GetAirportName();
             ++destCount;
             Flights temp2 = airport.getFlights();
             int flightCount = 1;
             for(auto&& flight : temp2)
             {
                cout<<"\n"<<flightCount<<"."<<flight->flightName();
                ++flightCount;
             }
             cout<<"\n --------------------";
         } 
     } 
   }  
};


#endif
