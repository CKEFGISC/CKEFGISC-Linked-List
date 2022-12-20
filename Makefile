CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -O2 -I./include
LDFLAGS = -L.
LDLIBS = -llist

.PHONY: all clean

all: liblist.a

example: example.cpp liblist.a
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

liblist.a: LinkedList.o
	ar -rcs $@ $<

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o *.a

