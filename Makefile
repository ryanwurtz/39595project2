CC=g++
CFLAGS=-std=c++17 -Wall -g
FILES = hash_list.cpp hash_list.h hash_map.cpp hash_map.h

# The source files we use for building custom_tests
ALL_SRC=$(wildcard *.cpp)

# The name of the resulting executable
APP=test

p2:
	$(CC) $(CFLAGS) $(FILES) -o p2
	./p2

custom_tests:
	$(CC) $(CFLAGS) $(ALL_SRC) -o $(APP)	

clean:
	rm -f $(APP)
	rm p2
