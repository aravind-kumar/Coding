#include "ModuleExamples.h"
#include "ps00.h"
#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class isCircularTests : public CxxTest::TestSuite
{
    public:
     void test1();
     void test2();
     void test3();
     void test4();
};

void isCircularTests::test1()
{
   TS_TRACE("Running test1 for circularModules");
   bool result = isCircular(circularModules);
   TS_ASSERT_EQUALS(result, true);
}

void isCircularTests::test2()
{
   TS_TRACE("Running test2 for circularModules1");
   bool result = isCircular(circularModules1);
   TS_ASSERT_EQUALS(result, false);
}

void isCircularTests::test3()
{
   TS_TRACE("Running test3 for circularModules1");
   bool result = isCircular(circularModules2);
   TS_ASSERT_EQUALS(result, true);
}

void isCircularTests::test4()
{
   TS_TRACE("Running test4 for modules1");
   bool result = isCircular(modules1);
   TS_ASSERT_EQUALS(result, false);
}
