GCC=g++
CFLAGS=-g -Wall -std=c++14
TARGET=main
SOURCES:=main.cpp 
DEPS:=string.h
THREAD:=-lpthread
# Math libraries
# MATH:=-lm
OBJECTS:=$(SOURCES:.cpp=.o)


%.o: %.cpp
	$(GCC) $(CFLAGS) -c $< -o $@ $(THREAD)

.PHONY: all
all: $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(THREAD)
	@./main

.PHONY:
test:  test.o
	$(GCC) $(CFLAGS) $< -o test $(THREAD)  

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS) 
