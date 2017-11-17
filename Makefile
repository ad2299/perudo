CXX = g++
CPPFLAGS = -I$(INCLUDE)
CXXFLAGS = -O2 $(CPPFLAGS) `pkg-config gtkmm-3.0 --cflags`
LDLIBS = -lpthread `pkg-config gtkmm-3.0 --libs`
RM = rm -f
INCLUDE = include/
SRC = src/
VIEW = views/

SRCS = $(SRC)game.cpp $(SRC)player.cpp $(SRC)bet.cpp $(SRC)perudo.cpp $(VIEW)main_window.cpp 
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = perudo

# Making objects.
.cpp:.o
	$(CXX) $(CXXFLAGS) -c $(SRCS)

# Making executable.
$(EXE): $(OBJS)
	$(CXX) $(LDLIBS) $^ -o $@

clean:
	$(RM) $(SRC)*.o $(SRC)*~ $(SRC)\#*\#
	$(RM) $(VIEW)*.o $(VIEW)*~ $(VIEW)\#*\#
	$(RM) $(INCLUDE)*~ $(INCLUDE)\#*\#
	$(RM) TAGS
	$(RM) $(EXE)


etags:
	make clean
	etags */*.c */*.cpp */*.h */*.hpp
