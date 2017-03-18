SRCS = game.cpp player.cpp bet.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

CXX = g++
RM = rm -f
INCLUDE = include/
SRC = src/
CPPFLAGS = -I$(INCLUDE)
EXE = perudo

all: tool

$(EXE): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(EXE) $(OBJS)

clean:
	$(RM) *.o
