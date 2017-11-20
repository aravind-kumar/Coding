#ifndef MODULE_EXAMPLES_H
#define MODULE_EXAMPLES_H

#include <string>
#include <list>
#include "Module.h"

using namespace std;

extern Module foo;                     // a module that's been changed
extern list<Module>* circularModules;  // example of circularity
extern list<Module>* circularModules1;  // example of circularity
extern list<Module>* circularModules2;  // example of circularity
extern list<Module>* modules1;         // only Main needs to be compiled
extern list<Module>* modules2;         // List, AList, Main need compiling
extern list<Module>* modules3;         // List, AList, Main need compiling

#endif
