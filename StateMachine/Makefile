# Makefile

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files
SRC = statemachine.cpp GPIO.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = statemachineDemo

# Compilation rules
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lpthread

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean the build
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
