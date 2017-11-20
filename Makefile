
CC=g++

CFLAGS=-g -Wall --std=c++14

SRCEXT := cpp
SOURCES := $(shell find . -type f -name *.$(SRCEXT))
OBJECTS=$(SOURCES:.cpp=.o)



