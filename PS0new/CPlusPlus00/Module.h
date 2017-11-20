#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <list>

using namespace std;

typedef class Module_* Module;

// all times are in seconds since 1 January 1970

class Module_
{
 public:
  string moduleName ();         // returns name of this module
  list<string>* moduleUses ();  // returns names of modules this module uses
  long int modificationTime (); // time this module's code was last modified
  long int compilationTime ();  // time this module was last compiled, or -1
  string compilationMode ();    // mode in which this module was last compiled
  bool operator== (Module);     // delegates to sameModule
  friend Module makeModule (string, list<string>*, long int, long int, string);
 private:
  string name_;             // the name of this module
  list<string>* uses_;      // names of modules this module uses
  long int mtime_;          // time this module's code was last modified
  long int ctime_;          // time this module was last compiled, or -1
  string cmode_;            // mode in which this module was last compiled
  bool sameModule (Module); // returns true if that module equals this one
};

/*
 * Factory method for creating modules.
 * Given:
 *     the name of the module
 *     the list of names of modules used by the module
 *     the time the module's source code was last modified
 *     the time the module was last compiled, or -1
 *     the mode in which the module was last compiled
 *         (meaningless if it hasn't been compiled)
 * Returns: pointer to an object that encapsulates the given information
 */

Module makeModule (string name, list<string>* uses,
                   long int mtime, long int ctime, string cmode);

bool isNonEmpty(Module);

bool isDependencyEmpty(Module mod);

#endif
