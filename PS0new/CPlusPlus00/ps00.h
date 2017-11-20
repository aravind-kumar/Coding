#ifndef PS00_H
#define PS00_H

#include <string>
#include <list>
#include "Module.h"

using namespace std;

extern bool isCircular (list<Module>* modules);

extern string bestMode (string m, list<Module>* modules);

extern list<string>* bestPlan (string m, list<Module>* modules);

extern void getAllPaths(string src,string dst,
		        list<Module>* modules,list<Module>& path,
 	                vector< list<Module> >& result);

extern list<Module>* doIntersection(vector< list<Module> > paths);

extern list<Module>* numOfCompilations(string moduleName,
                                       list<Module>* modules,
			               string mode);

extern int getNumOfModulesWithDifferentMode(string modeName,
				            list<Module>* modules,
 				            list<Module>& visitedNodes);


extern int getNumOfModulesWhichArentCompiled(list<Module>* modules,
				             list<Module>& visitedNodes);
#endif
