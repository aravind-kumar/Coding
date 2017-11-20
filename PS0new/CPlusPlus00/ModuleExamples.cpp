#include <string>
#include <list>
#include "Module.h"
#include "ModuleExamples.h"

using namespace std;

// abbreviations

list<string>* slist () {
  list<string>* result = new list<string>();
  return result;
}

list<string>* slist (string s1) {
  list<string>* result = new list<string>();
  result->push_back (s1);
  return result;
}

list<string>* slist (string s1, string s2) {
  list<string>* result = new list<string>();
  result->push_back (s1);
  result->push_back (s2);
  return result;
}

list<string>* slist (string s1, string s2, string s3) {
  list<string>* result = new list<string>();
  result->push_back (s1);
  result->push_back (s2);
  result->push_back (s3);
  return result;
}

list<string>* slist (string s1,
                     string s2,
                     string s3,
                     string s4) {
  list<string>* result = new list<string>();
  result->push_back (s1);
  result->push_back (s2);
  result->push_back (s3);
  result->push_back (s4);
  return result;
}

list<Module>* mlist (Module m1) {
  list<Module>* result = new list<Module>();
  result->push_back (m1);
  return result;
}

list<Module>* mlist (Module m1, Module m2) {
  list<Module>* result = new list<Module>();
  result->push_back (m1);
  result->push_back (m2);
  return result;
}

list<Module>* mlist (Module m1, Module m2, Module m3) {
  list<Module>* result = new list<Module>();
  result->push_back (m1);
  result->push_back (m2);
  result->push_back (m3);
  return result;
}

list<Module>* mlist (Module m1,
                     Module m2,
                     Module m3,
                     Module m4) {
  list<Module>* result = new list<Module>();
  result->push_back (m1);
  result->push_back (m2);
  result->push_back (m3);
  result->push_back (m4);
  return result;
}

list<Module>* mlist (Module m1,
                     Module m2,
                     Module m3,
                     Module m4,
                     Module m5,
                     Module m6,
                     Module m7,
                     Module m8,
                     Module m9) {
  list<Module>* result = new list<Module>();
  result->push_back (m1);
  result->push_back (m2);
  result->push_back (m3);
  result->push_back (m4);
  result->push_back (m5);
  result->push_back (m6);
  result->push_back (m7);
  result->push_back (m8);
  result->push_back (m9);
  return result;
}
// a description of a module that's been modified since it was compiled
// and must therefore be compiled again before it is used

Module foo
= makeModule ("Foo", slist ("Baz"), 1505109465, 1504097449, "LP64");

// a list of modules that have a circular dependency

list<Module>* circularModules
= mlist (makeModule ("M1", slist ("M2", "M3"), 1500, -1, "ILP32"),
         makeModule ("M2", slist ("M3"),       2000, -1, "ILP32"),
         makeModule ("M3", slist ("M2"),       2500, -1, "ILP32"));

list<Module>* circularModules1
= mlist (makeModule ("M0", slist ("M1"), 1500, -1, "ILP32"),
         makeModule ("M1", slist ("M2"),2000, -1, "ILP32"),
         makeModule ("M2", slist ("M3"),       2500, -1, "ILP32"),
         makeModule ("M3", slist(),2500, -1, "ILP32"));

list<Module>* circularModules2
= mlist (makeModule ("M0", slist ("M1"), 1500, -1, "ILP32"),
         makeModule ("M1", slist ("M2"),2000, -1, "ILP32"),
         makeModule ("M2", slist ("M3"),       2500, -1, "ILP32"),
         makeModule ("M3", slist("M1"),2500, -1, "ILP32"));


// a list of modules, of which only Main needs to be compiled
// (in mode LP64) before Main can be used

list<Module>* modules1
= mlist (makeModule ("Main",
                     slist ("List", "AList"),
                     1504188920,
                     -1,
                     "LP64"),
         makeModule ("List",
                     slist ("Obj"),
                     1472652920,
                     1472658760,
                     "LP64"),
         makeModule ("AList",
                     slist ("List", "Obj"),
                     1472654764,
                     1472659242,
                     "LP64"),
         makeModule ("Obj",
                     slist(),
                     1472630256,
                     1472638841,
                     "LP32"));

// a list of modules, of which List, AList, and Main need to be compiled
// (in that order, in mode ILP32) before Main can be used

list<Module>* modules2
= mlist (makeModule ("Main",
                     slist ("List", "AList"),
                     1504188920,
                     -1,
                     "LP64"),
         makeModule ("List",
                     slist ("Obj"),
                     1472652920,
                     1472658760,
                     "LP64"),
         makeModule ("AList",
                     slist ("List", "Obj"),
                     1472654764,
                     1472659242,
                     "LP64"),
         makeModule ("Obj",
                     slist(),
                     1472630256,
                     1472638841,
                     "ILP32"));

list<Module>* modules3
= mlist (makeModule ("Main",
                     slist ("List", "AList"),
                     3,
                     10,
                     "ILP32"),
         makeModule ("List",
                     slist ("Obj"),
                     1,
                     4,
                     "ILP64"),
         makeModule ("AList",
                     slist ("A1", "A2"),
                     5,
                     4,
                     "ILP32"),
         makeModule ("A1",
                     slist (),
                     1,
                     2,
                     "LP64"),
         makeModule ("A2",
                     slist ("A3"),
                     1,
                     2,
                     "LP64"),
         makeModule ("A3",
                     slist (),
                     2,
                     -1,
                     "LP64"),
         makeModule ("Obj",
                     slist("O1","O2"),
                     1,
                     2,
                     "LP32"),
         makeModule ("O1",
                     slist(),
                     1,
                     4,
                     "LP32"),
        makeModule ("O2",
                     slist("A3"),
                     1,
                     4,
                     "LP32"));
