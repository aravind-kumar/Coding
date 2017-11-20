#include <cxxtest/TestSuite.h>
#include "ps00.h"
#include "ModuleExamples.h"
#include <string>
#include <vector>

class bestModeTests: public CxxTest::TestSuite
{
   public:
      void testfilterBasedOnMode();
      void testfilterBasedOnCompileTime();
      void testallPossiblePaths();
      void testinterSection();
      void testnumOfCompilations();
      void testbestMode1();
      void testbestMode2();
      void testbestMode3();
};

void bestModeTests::testfilterBasedOnMode()
{
   list<Module> modulesWithDifferentMode;
   int i = 0;
   getNumOfModulesWithDifferentMode("ILP32",modules2,modulesWithDifferentMode);
   vector<string> resultString={"Main","List","AList"};
  
   TS_ASSERT_EQUALS(modulesWithDifferentMode.size(),resultString.size()); 
    
   for(auto&& module: modulesWithDifferentMode)
   {
      string moduleName = module->moduleName();
      TS_ASSERT_EQUALS(moduleName,resultString[i]);
      ++i;
   }
}

void bestModeTests::testfilterBasedOnCompileTime()
{
    int i=0;
    list<Module> modulesWhichArentCompiled;
    getNumOfModulesWhichArentCompiled(modules2,modulesWhichArentCompiled);
    
    vector<string> resultString={"Main"};
   
    TS_ASSERT_EQUALS(modulesWhichArentCompiled.size(),resultString.size()); 
   
    for(auto&& module: modulesWhichArentCompiled)
    {
      string moduleName = module->moduleName();
      TS_ASSERT_EQUALS(moduleName,resultString[i]);
      ++i;
    }
}

void checkSizes(vector< list<Module> > moduleList,
		vector< list<string> > result)
{
   TS_ASSERT_EQUALS(moduleList.size(),result.size());
   for(int i=0;i<moduleList.size();++i)
   {
      list<Module> mod = moduleList[i];
      list<string> ans = result[i];

      TS_ASSERT_EQUALS(mod.size(),ans.size());
   }  
}

void checkResult(vector< list<Module> > moduleList,
		vector< list<string> > result)
{
   list<Module>::iterator moduleIterator;
   list<string>::iterator resultIterator;
   for(int i=0;i<moduleList.size();++i)
   {
      list<Module> mod = moduleList[i];
      list<string> ans = result[i];
      moduleIterator = mod.begin();
      resultIterator = ans.begin();
      for(;moduleIterator != mod.end();++moduleIterator,++resultIterator)
      {
         string moduleName = (*moduleIterator)->moduleName();
         string resultName = (*resultIterator);
         TS_ASSERT_EQUALS(moduleName,resultName);
      }
   }

}

void bestModeTests::testallPossiblePaths()
{
   list<Module> path;
   typedef list<Module> paths;
   vector<paths> allPossiblePathsFromSrcToDst;
   getAllPaths("Main","Obj",modules2,path,allPossiblePathsFromSrcToDst);
   
   list<string> path1 = {"Main","List","Obj"};
   list<string> path2 = {"Main","AList","List","Obj"};
   list<string> path3 = {"Main","AList","Obj"};
   vector< list<string> > result ={path1,path2,path3};
 
   checkSizes(allPossiblePathsFromSrcToDst,result);
   checkResult(allPossiblePathsFromSrcToDst,result);
}

unsigned int numOfModules(string moduleName,list<Module>* modules)
{
   int count=0;
   for(auto&& mod: *modules)
   {
      if(mod->moduleName() == moduleName)
      {
          ++count;
      } 
   }
   return count;
}

void bestModeTests::testinterSection()
{
   list<Module> path;
   typedef list<Module> paths;
   vector<paths> allPossiblePathsFromSrcToDst;
   getAllPaths("Main","Obj",modules2,path,allPossiblePathsFromSrcToDst);

   list<Module>* common = doIntersection(allPossiblePathsFromSrcToDst); 
   
   TS_ASSERT_EQUALS(numOfModules("Main",common),1);
   TS_ASSERT_EQUALS(numOfModules("List",common),1);
   TS_ASSERT_EQUALS(numOfModules("AList",common),1);
   TS_ASSERT_EQUALS(numOfModules("Obj",common),1);
}

void bestModeTests::testnumOfCompilations()
{
   TS_ASSERT_EQUALS(numOfCompilations("Main",modules2,"LP64")->size(),4);
   TS_ASSERT_EQUALS(numOfCompilations("Main",modules2,"ILP64")->size(),4);
   TS_ASSERT_EQUALS(numOfCompilations("Main",modules2,"LP32")->size(),4);
   TS_ASSERT_EQUALS(numOfCompilations("Main",modules2,"ILP32")->size(),3);
}

void bestModeTests::testbestMode1()
{
  TS_ASSERT_EQUALS(bestMode("Main",modules2),"ILP32");
}

void bestModeTests::testbestMode2()
{
  TS_ASSERT_EQUALS(bestMode("Main",modules3),"LP64");
}

void bestModeTests::testbestMode3()
{
  TS_ASSERT_EQUALS(bestMode("Main",modules1),"LP32");
}
