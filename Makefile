CXX = g++
CFLAGS =
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRCS = main.cpp game.cpp config.cpp
BIN = pollice-verso

VERSION = $(shell git rev-parse HEAD)

all: $(SRCS)
	$(CXX) $(SRCS) $(LFLAGS) -o $(BIN)

.PHONY: all clean

clean:
	-rm -f $(BIN)
