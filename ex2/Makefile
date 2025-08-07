CC=gcc
CXX=g++
LDFLAGS=-L. -lfoo -Wl,-rpath=$(PWD)

all: main

main: main.c libfoo.so
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

libfoo.so: libfoo.cpp libfoo.h
	$(CXX) $(CFLAGS) -shared -fPIC $< -o $@

clean:
	rm -fr main libfoo.so