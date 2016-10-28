GCC=g++
CFLAGS=-g -Wall -std=c++14
TARGET=main
SOURCES:=main.cpp
DEPS:=test.h
# Math libraries
# MATH:=-lm
OBJECTS:=$(SOURCES:.cpp=.o)

%.o: %.cpp
	@echo "Making objects! Input = " $< "OUtput = " $@
	$(GCC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 
	@./main

.PHONY:
test: test.o
	$(GCC) $(CFLAGS) test.o -o test 
	@./test

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)
