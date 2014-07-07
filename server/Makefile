CXX = g++
CFLAGS =
LFLAGS = -lsfml-network
SRCS = main.cpp
BIN = arena

VERSION = $(shell git rev-parse HEAD)

all: $(SRCS)
	$(CXX) $(SRCS) $(LFLAGS) -o $(BIN)

.PHONY: all clean

clean:
	-rm -f $(BIN)
