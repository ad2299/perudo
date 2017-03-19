CXX = g++
RM = rm -f
INCLUDE = include/
SRC = src/
CPPFLAGS = -I$(INCLUDE)

SRCS = $(SRC)game.cpp $(SRC)player.cpp $(SRC)bet.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = perudo

.cpp:.o
	$(CXX) $(CPPFLAGS) -c $(SRCS)

$(EXE): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(EXE) $(OBJS)

clean:
	$(RM) $(SRC)*.o
	$(RM) $(EXE)
