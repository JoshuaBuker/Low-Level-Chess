# Compiler
CXX = gcc

# Compiler flags
CXXFLAGS = -Wall -I./

# Find all source files
SRC_DIRS = ./
SRCS = $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
OUTPUT = chessProgram

# Default target
all: $(OUTPUT) clean

# Link the object files to create the executable
$(OUTPUT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(OBJS) -mconsole

# Compile each source file into an object file
%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove the compiled files
clean:
	rm -f $(OBJS)

.PHONY: all clean