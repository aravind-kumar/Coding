#include <cxxtest/TestSuite.h>
#include "ps00.h"
#include "ModuleExamples.h"
#include "Module.h"

class bestPlanTests : public CxxTest::TestSuite
{
    public:
      void test1();
      void test2();
}; 


void bestPlanTests::test1()
{
  int i = 0;
  vector<string> result = {"List","AList","Main"};
  for(auto&& modName : *(bestPlan("Main",modules2)))
  {
      TS_ASSERT_EQUALS(modName,result[i]);
      ++i;
  }
}

void bestPlanTests::test2()
{
   int i=0;
   vector<string> result = {"O1","A3","O2","Obj","List","A2","AList","Main"};
   for(auto&& modName : *(bestPlan("Main",modules3)))
   {
      TS_ASSERT_EQUALS(modName,result[i]);
      ++i;
   }
}
