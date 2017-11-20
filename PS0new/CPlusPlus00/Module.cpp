#include <string>
#include <list>
#include "Module.h"

using namespace std;

/*
 * Factory method for creating modules.
 * Given:
 *     the name of the module
 *     the list of names of modules used by the module
 *     the time the module's source code was last modified
 *     the time the module was last compiled, or -1
 *     the mode in which the module was last compiled
 *         (meaningless if it hasn't been compiled)
 *
 * Returns: pointer to an object that encapsulates the given information
 */

Module makeModule (string name, list<string>* uses,
                   long mtime, long ctime, string cmode) {
  Module module = new Module_();
  module->name_ = name;
  module->uses_ = uses;
  module->mtime_ = mtime;
  module->ctime_ = ctime;
  module->cmode_ = cmode;
  return module;
}

bool isDependencyEmpty(Module mod)
{
   list<string>* deps = mod->moduleUses();
   return (deps->size()==0);
}
 
bool isNonEmpty(Module mod)
{ 
  bool dependecyResult = isDependencyEmpty(mod);
  return ((mod->moduleName() != "") 
           &&
           (dependecyResult == false));
}

string Module_::moduleName () {
  return name_;
}

list<string>* Module_::moduleUses () {
  return uses_;
}

long int Module_::modificationTime () {
  return mtime_;
}

long int Module_::compilationTime () {
  return ctime_;
}

string Module_::compilationMode () {
  return cmode_;
}

bool Module_::sameModule (Module module) {
  return
    (moduleName().compare (module->moduleName()) == 0) &&
    (moduleUses() == module->moduleUses()) &&
    (modificationTime() == module->modificationTime()) &&
    (compilationTime() == module->compilationTime()) &&
    ((compilationTime() == -1) ||
     (compilationMode().compare (module->compilationMode()) == 0));
}

bool Module_::operator== (Module module) {
  return sameModule (module);
}
  
