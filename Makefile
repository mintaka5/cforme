# usage:
# make :: compiles all binaries
# make clean :: remove all binaries and objects

CXX = g++

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

LDFLAGS = -lm -lssl -lcrypto

CFLAGS = -g -Wall -Ic:/msys64/mingw64/include/openssl

cforme: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	-del -fR $(OBJ) cforme