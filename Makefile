# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -I./ -I./gameLogic/header -I./util/header

# Find all source files
SRC_DIRS = ./ ./gameLogic/source ./util/source
SRCS = $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
OUTPUT = game

# Default target
all: $(OUTPUT) clean

# Link the object files to create the executable
$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJS) -mconsole

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove the compiled files
clean:
	rm -f $(OBJS)

.PHONY: all clean