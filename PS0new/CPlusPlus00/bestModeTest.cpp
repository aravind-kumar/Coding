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
bool suite_bestModeTests_init = false;
#include "bestModeTest.h"

static bestModeTests suite_bestModeTests;

static CxxTest::List Tests_bestModeTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_bestModeTests( "bestModeTest.h", 7, "bestModeTests", suite_bestModeTests, Tests_bestModeTests );

static class TestDescription_suite_bestModeTests_testfilterBasedOnMode : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testfilterBasedOnMode() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 10, "testfilterBasedOnMode" ) {}
 void runTest() { suite_bestModeTests.testfilterBasedOnMode(); }
} testDescription_suite_bestModeTests_testfilterBasedOnMode;

static class TestDescription_suite_bestModeTests_testfilterBasedOnCompileTime : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testfilterBasedOnCompileTime() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 11, "testfilterBasedOnCompileTime" ) {}
 void runTest() { suite_bestModeTests.testfilterBasedOnCompileTime(); }
} testDescription_suite_bestModeTests_testfilterBasedOnCompileTime;

static class TestDescription_suite_bestModeTests_testallPossiblePaths : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testallPossiblePaths() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 12, "testallPossiblePaths" ) {}
 void runTest() { suite_bestModeTests.testallPossiblePaths(); }
} testDescription_suite_bestModeTests_testallPossiblePaths;

static class TestDescription_suite_bestModeTests_testinterSection : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testinterSection() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 13, "testinterSection" ) {}
 void runTest() { suite_bestModeTests.testinterSection(); }
} testDescription_suite_bestModeTests_testinterSection;

static class TestDescription_suite_bestModeTests_testnumOfCompilations : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testnumOfCompilations() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 14, "testnumOfCompilations" ) {}
 void runTest() { suite_bestModeTests.testnumOfCompilations(); }
} testDescription_suite_bestModeTests_testnumOfCompilations;

static class TestDescription_suite_bestModeTests_testbestMode1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testbestMode1() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 15, "testbestMode1" ) {}
 void runTest() { suite_bestModeTests.testbestMode1(); }
} testDescription_suite_bestModeTests_testbestMode1;

static class TestDescription_suite_bestModeTests_testbestMode2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testbestMode2() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 16, "testbestMode2" ) {}
 void runTest() { suite_bestModeTests.testbestMode2(); }
} testDescription_suite_bestModeTests_testbestMode2;

static class TestDescription_suite_bestModeTests_testbestMode3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bestModeTests_testbestMode3() : CxxTest::RealTestDescription( Tests_bestModeTests, suiteDescription_bestModeTests, 17, "testbestMode3" ) {}
 void runTest() { suite_bestModeTests.testbestMode3(); }
} testDescription_suite_bestModeTests_testbestMode3;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
