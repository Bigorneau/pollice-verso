CXX = g++
CFLAGS =
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
SRCS = main.cpp game.cpp config.cpp unit.cpp
BIN = pollice-verso

VERSION = $(shell git rev-parse HEAD)

all: $(SRCS)
	$(CXX) $(SRCS) $(LFLAGS) -o $(BIN)

.PHONY: all clean

clean:
	-rm -f $(BIN)
