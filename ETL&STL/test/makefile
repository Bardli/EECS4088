# Source files
SRCS := $(wildcard *.cpp)

# Object files (replace .cpp with nothing for executable names)
EXES := $(SRCS:.cpp=)

# Default rule
all: $(EXES)

# Pattern rule for compiling C++ files
%: %.cpp
	g++ -o $@ $<

# Clean rule
clean:
	rm -f $(EXES)