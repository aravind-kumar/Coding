/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_bestPlanTests_init = false;
#include "bestPlanTest.h"

static bestPlanTests suite_bestPlanTests;

static CxxTest::List Tests_bestPlanTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_bestPlanTests( "bestPlanTest.h", 6, "bestPlanTests", suite_bestPlanTests, Tests_bestPlanTests );

static class TestDescription_suite_bestPlanTests_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestPlanTests_test1() : CxxTest::RealTestDescription( Tests_bestPlanTests, suiteDescription_bestPlanTests, 9, "test1" ) {}
 void runTest() { suite_bestPlanTests.test1(); }
} testDescription_suite_bestPlanTests_test1;

static class TestDescription_suite_bestPlanTests_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestPlanTests_test2() : CxxTest::RealTestDescription( Tests_bestPlanTests, suiteDescription_bestPlanTests, 10, "test2" ) {}
 void runTest() { suite_bestPlanTests.test2(); }
} testDescription_suite_bestPlanTests_test2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
