// You can include more header files here.

#include <list>
#include "Module.h"
#include "ps00.h"
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// Your forward declarations (etc) go here.

////////////////////////////////////////////////////////////////

// The examples refer to
//
//     foo
//     circularModules
//     modules1
//     modules2
//     slist(...)
//     mlist(...)
//
// These are defined in ModuleExamples.c++
// (but slist(...) and mlist(...) aren't mentioned in ModuleExamples.h)

// isPresent: String, ListOfString -> Boolean
// GIVEN: an element to search for in container
// RETURNS: true if the element is present in the container
//	    and false otherwise
bool isPresent(string elem,list<string> container)
{
    return (find(container.begin(),container.end(),elem) != container.end());
}

//isPresent: String,listOfModules -> Module iterator
//GIVEN: moduleName:a string representing the module name.
//       modules:a List of Modules and its dependencies
//RETURNS: an iterator pointing to the module if the the module is present
//	   and End of ListOfModules otherwise
//EXAMPLES: 
list<Module>::iterator isModulePresent(string moduleName,list<Module>* modules)
{
    list<Module>::iterator it;
    for(it=modules->begin();it!=modules->end();++it)
    {
        if((*it)->moduleName() == moduleName)
	{
           return it;
        }
    }
    return modules->end();
}

//doesCycleExsist : Module,listOfString,listOfString,ListOfModules
//GIVEN: a module,a listOfString,a listOfString,listOfModules
//WHERE: module: is the start module
//	 visited: is to keep track of the nodes visited and to prevent 
//		  from an infinite recursion if there exsists a cycle
//	 inRecursion: is to keep track of nodes in the recursion stack
//	 modules: is the list of all the modules
//RETURNS: true iff a cycle exsists and false otherwise
//NOTE:since this a directed graph we need both visited and inrecursion to 
//     keep track of the nodes visited.
//     The visited list keeps track of the nodes visited 
//     If there exisits a cycle visited would help prevent an infinite recursion
//     But because a node is visited doesn't mean that there is cycle
//     it could also mean that are multiple paths to the same node
//     
//EXAMPLES:
bool doesCycleExsist(Module module,list<string>& visited,
		     list<string>& inRecursion,list<Module>* modules)
{
   string moduleName = module->moduleName();
   if(isPresent(moduleName,visited) == false)
   {
       visited.push_back(module->moduleName());
       inRecursion.push_back(module->moduleName());
       for(auto&& dependency: *(module->moduleUses()))
       {
            list<Module>::iterator it = isModulePresent(dependency,modules);
            if(isPresent(dependency,visited) 
               && 
               isPresent(dependency,inRecursion))
            {
               return true;
            }
            else if(doesCycleExsist(*it,visited,inRecursion,modules))
            {
               return true;
            }
       }
   }
   inRecursion.remove(moduleName);
   return false;
}

// isCircular : ListOfModule -> Boolean
// GIVEN: a list of module descriptions
// WHERE: no two descriptions are for the same module name
// RETURNS: true if and only if one or more of the modules
//     depends upon itself
// EXAMPLES:
//
//     isCircular (mlist())  =>  false
//
//     isCircular (modules1)  =>  false
//
//     isCircular (circularModules)  =>  true
bool isCircular(list<Module>* modules) 
{
    bool result=false;
    list<string> visited;
    list<string> stackElements;
    for(auto&& module : *modules)
    {
        result = result | doesCycleExsist(module,visited,stackElements,modules);
    }
    return result;
}


//getAllPaths: String,String,ListOfModules,ListOfModules -> Vector Of ListOfModules
//GIVEN: src: Source from where the seach begins
//	 dst: Destination where the search ends
//       path: A list of Modules which are dependent
//RETURNS: result: a Vector of ListOfModules where ListOfModules represents
//	   a path.Hence returns a vector of paths from the given Source to 
//	   Destination.
//NOTE:This function assumes that the graph is simple directed graph without cycles.
void getAllPaths(string src,string dst,
		 list<Module>* modules,list<Module>& path,
 	         vector<list<Module>>& result)
{
    list<Module>::iterator it = isModulePresent(src,modules);
    if(it != modules->end())
    {
        path.push_back(*it);
        if(src==dst)
        {
           result.push_back(path);
        }
        else
        {
           list<Module>::iterator it = isModulePresent(src,modules);
           if(it != modules->end())
           {
               for(auto&& deps : *((*it)->moduleUses()))
               {
                  getAllPaths(deps,dst,modules,path,result); 
               }
            }
          }
          path.pop_back();     
      }
}

//doIntersection: vector of ListOfModules -> ListOfModule
//GIVEN: a vector of ListOfModules
//RETURNS: A listOfModules which which are unique
//         A Set Intersection is performed on all paths.
//EXAMPLES:
list<Module>* doIntersection(vector<list<Module>> paths)
{
    list<Module>* uniqueMods = new list<Module>;
    for(auto&& modules: paths)
    {
        for(auto&& mod : modules)
        { 
          list<Module>::iterator it = find(uniqueMods->begin(),uniqueMods->end(),mod);
          if(it == uniqueMods->end())
	  {
             uniqueMods->push_back(mod);
          } 
        }
    }
    return uniqueMods;
}

//doIntersection: vector of ListOfModules -> ListOfModule
//GIVEN: a vector of ListOfModules
//RETURNS: A listOfModules which which are unique
//         A Set Intersection is performed on all paths.
//EXAMPLES:
list<Module>* doIntersection(vector<list<Module>*> paths)
{
    list<Module>* uniqueMods = new list<Module>;
    for(auto&& modules: paths)
    {
        for(auto&& mod : *modules)
        { 
          list<Module>::iterator it = find(uniqueMods->begin(),uniqueMods->end(),mod);
          if(it == uniqueMods->end())
	  {
             uniqueMods->push_back(mod);
          } 
        }
    }
    return uniqueMods;
}

//getDependents: String,String,ListOfModules -> ListOfModule
//GIVEN: moduleName:Target module name whose dependents are to be found
//	 rootNode: is the start module for finding the dependents
//	 modules: is the List Of Modules
//RETURNS: Returns all the Unique Modules that dependent on the target module (moduleName).
//EXAMPLES:
list<Module>* getDependents(string rootNode,string moduleName,list<Module>* modules)
{
    typedef list<Module> paths;
    vector<paths> allPossiblePathsFromSrcToDst;
    list<Module> path;
    getAllPaths(rootNode,moduleName,modules,path,allPossiblePathsFromSrcToDst);
    list<Module>* distinctNodes = doIntersection(allPossiblePathsFromSrcToDst);
    return distinctNodes;
}

//getNumOfModulesWhichArentCompiled: ListOfModules -> ListOfModule
//GIVEN: modules:A list of Modules 
//RETURNS:The number and the list of modules (visitedNodes).
//EXAMPLES:
int getNumOfModulesWhichArentCompiled(list<Module>* modules,
				      list<Module>& visitedNodes)
{
    list<Module> result;
    for(auto&& mod : *modules)
    {
         if(mod->modificationTime() > mod->compilationTime ())
         {
            result.push_back(mod); 
         } 
    }
    visitedNodes=result;
    return result.size();
}

//getNumOfModulesWithDifferent: String,ListOfModules,ListOfModules -> Integer,ListOfModules
//GIVEN: modeName:Mode of a module
//	 modules:Modules and its dependencies
//RETURNS: The number and list of modules(by refference) which are compiled in a mode different from the 
//	   given mode.
//EXAMPLES:
int getNumOfModulesWithDifferentMode(string modeName,
				     list<Module>* modules,
 				     list<Module>& visitedNodes)
{
    list<Module> result;
    for(auto&& mod :*modules)
    {
       if(mod->compilationMode() != modeName)
       { 
          result.push_back(mod);
       }
    }
    visitedNodes = result;
    return result.size();
}

//numOfCompilations: String,ListOfModule,String -> ListOfModule
//GIVEN: moduleName: Name of the module
//	 modules: List Of Modules and its dependendencies
//	 mode:Mode in which the modules are to compiled.
//RETURNS: The list of Modules which are to compiled for the given mode
//EXAMPLES:
list<Module>* numOfCompilations(string moduleName,
                               list<Module>* modules,
			       string mode)
{
   list<Module> modulesWithDifferentMode;
   list<Module>* dependentsOfDifferentMode;
   list<Module> modulesWhichArentCompiled;
   list<Module>* dependsOfNonCompiledModules;

   vector<list<Module>*> result; 

   getNumOfModulesWithDifferentMode(mode,modules,modulesWithDifferentMode);   
   getNumOfModulesWhichArentCompiled(modules,modulesWhichArentCompiled);
    

   for(auto&& mod : modulesWithDifferentMode)
   {
     dependentsOfDifferentMode = getDependents(moduleName,mod->moduleName(),modules);
     result.push_back(dependentsOfDifferentMode);
     dependentsOfDifferentMode = doIntersection(result); 
     result.clear();
     result.push_back(dependentsOfDifferentMode);
   }
   
   for(auto&& mod : modulesWhichArentCompiled)
   {   
     dependsOfNonCompiledModules = getDependents(moduleName,mod->moduleName(),modules); 
     result.push_back(dependsOfNonCompiledModules);
     dependsOfNonCompiledModules = doIntersection(result);
     result.clear();
     result.push_back(dependsOfNonCompiledModules);
   }
   return result[0];
}

//FindMin: HashMap<string,integer> -> String
//GIVEN: An UnorderedMap (HashMap) with key as string and value as integer
//RETURNS: The key whose value is the minimum in the given HashMap
//EXAMPLES:
string FindMin(unordered_map<string,int> inputMap)
{
  int result = INT_MAX;
  string resultString="";
  for(auto&& it : inputMap)
  {
      if(it.second<result)
      {
         resultString = it.first; 
         result = it.second;
      }
  }
  return resultString;
}

// bestMode : String ListOfModule -> String
// GIVEN: a module name M and a list of module descriptions
// WHERE: no two descriptions are for the same module name,
//     M is among the modules described,
//     and none of the described modules depend upon themselves
// RETURNS: the name of a mode (LP64, ILP64, LP32, or ILP32)
//     that, when used to compile all of the modules that need to be
//     compiled before module M can be used, would result in
//     compiling the fewest modules
// NOTE: this function may have more than one correct result
// EXAMPLES:
//
//     bestMode ("Main", modules1)  =>  "LP64"
//
//     bestMode ("Main", modules2)  =>  "ILP32"

string bestMode (string m,list<Module>* modules) {
    if(isCircular(modules) == false)
    {
    	list<string> modes={"LP64","ILP64","LP32","ILP32"};
        unordered_map<string,int> resultMap; 
    	for(auto&& mode : modes)
    	{
       	    int count=(numOfCompilations(m,modules,mode))->size(); 
            pair<string,int> resultPair(mode,count);
            resultMap.insert(resultPair);
    	}
        return FindMin(resultMap); 
    }
    return "";
}

//doTopologicalSort: String,ListOfModules,VectorOfStrings -> ListOfStrings (by refference)
//GIVEN: moduleToCompile:Module which has to be compiled (Root/Start of the
//	 graph).
//       modules:ListOfModules and its dependencies
//       visitedNodes: List of String's (Nodes) to prevent from cyclic dependency
//RETURNS: result: The order in which the modules have to compiled.
//EAMPLES:
void doTopologicalSort(string moduleToCompile,list<Module>* modules,
		       vector<string>& visitedNodes,list<string>* result)
{ 
   list<Module>::iterator it = isModulePresent(moduleToCompile,modules);
   if(it != modules->end())
   {
     visitedNodes.push_back((*it)->moduleName());
     
     for(auto&& mod : *((*it)->moduleUses()))
     {
         if(find(visitedNodes.begin(),visitedNodes.end(),mod) == visitedNodes.end())
	 {
           doTopologicalSort(mod,modules,visitedNodes,result); 
         }
     }
     result->push_back(moduleToCompile); 
   }

}

// bestPlan : String ListOfModule -> ListOfString
// GIVEN: a module name M and a list of module descriptions
// WHERE: no two descriptions are for the same module name,
//     M is among the modules described,
//     and none of the described modules depend upon themselves
// RETURNS: a list of names for the modules that need to be compiled
//     using the best mode, in the order they should be compiled,
//     before module M can be used
// NOTE: this function may have more than one correct result
// EXAMPLE:
//
// bestPlan ("Main", modules2)  =>  slist ("List", "AList", "Main")

list<string>* bestPlan(string m, list<Module>* modules) {
   list<string>* result = new list<string>;
   vector<string> visitedNodes;
   string bestModeToCompile = bestMode(m,modules);
   list<Module>* subGraph = numOfCompilations(m,modules,bestModeToCompile);
   doTopologicalSort(m,subGraph,visitedNodes,result);
   //result->reverse();
   return result;
}

// Your help functions (etc) go here.
