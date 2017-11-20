CC = g++
CCFLAGS = -Wall -g -std=c++11
COMPILE = -c
CXXTEST = cxxtestgen
CXXFLAGS = --error-printer

all: main

main: Module.o ModuleExamples.o ps00.o temp.o
	$(CC) $(CCFLAGS) Module.o ModuleExamples.o ps00.o temp.o -o ps00 

Module.o: Module.cpp
	$(CC) $(CCFLAGS) $(COMPILE) Module.cpp

ModuleExamples.o: ModuleExamples.cpp
	$(CC) $(CCFLAGS) $(COMPILE) ModuleExamples.cpp

ps00.o: ps00.cpp
	$(CC) $(CCFLAGS) $(COMPILE) ps00.cpp

temp.o: temp.cpp
	$(CC) $(CCFLAGS) $(COMPILE) temp.cpp

test: isCircular bestMode bestPlan
	./isCircularTest && ./bestModeTest && ./bestPlanTest

isCircular: isCircular.cpp all 
	$(CC) $(CCFLAGS) -o isCircularTest isCircularTest.cpp Module.cpp ModuleExamples.cpp ps00.cpp

bestMode: bestMode.cpp all
	$(CC) $(CCFLAGS) -o bestModeTest bestModeTest.cpp Module.cpp ModuleExamples.cpp ps00.cpp

bestPlan: bestPlan.cpp all
	$(CC) $(CCFLAGS) -o bestPlanTest bestPlanTest.cpp Module.cpp ModuleExamples.cpp ps00.cpp

isCircular.cpp: isCircularTest.h
	$(CXXTEST) $(CXXFLAGS) -o isCircularTest.cpp isCircularTest.h

bestMode.cpp: bestModeTest.h
	$(CXXTEST) $(CXXFLAGS) -o bestModeTest.cpp bestModeTest.h

bestPlan.cpp: bestPlanTest.h
	$(CXXTEST) $(CXXFLAGS) -o bestPlanTest.cpp bestPlanTest.h 
clean:
	rm *o
	rm isCircularTest
	rm bestModeTest
	rm bestPlanTest
	rm isCircularTest.cpp
	rm bestModeTest.cpp
	rm bestPlanTest.cpp
