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
bool suite_isCircularTests_init = false;
#include "isCircularTest.h"

static isCircularTests suite_isCircularTests;

static CxxTest::List Tests_isCircularTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_isCircularTests( "isCircularTest.h", 5, "isCircularTests", suite_isCircularTests, Tests_isCircularTests );

static class TestDescription_suite_isCircularTests_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_isCircularTests_test1() : CxxTest::RealTestDescription( Tests_isCircularTests, suiteDescription_isCircularTests, 8, "test1" ) {}
 void runTest() { suite_isCircularTests.test1(); }
} testDescription_suite_isCircularTests_test1;

static class TestDescription_suite_isCircularTests_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_isCircularTests_test2() : CxxTest::RealTestDescription( Tests_isCircularTests, suiteDescription_isCircularTests, 9, "test2" ) {}
 void runTest() { suite_isCircularTests.test2(); }
} testDescription_suite_isCircularTests_test2;

static class TestDescription_suite_isCircularTests_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_isCircularTests_test3() : CxxTest::RealTestDescription( Tests_isCircularTests, suiteDescription_isCircularTests, 10, "test3" ) {}
 void runTest() { suite_isCircularTests.test3(); }
} testDescription_suite_isCircularTests_test3;

static class TestDescription_suite_isCircularTests_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_isCircularTests_test4() : CxxTest::RealTestDescription( Tests_isCircularTests, suiteDescription_isCircularTests, 11, "test4" ) {}
 void runTest() { suite_isCircularTests.test4(); }
} testDescription_suite_isCircularTests_test4;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
