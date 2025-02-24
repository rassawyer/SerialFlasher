# Project directories
INCLUDE_DIR = include
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Compiler settings
CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR)   # -Wall for warnings, -I to include the "includes" directory
# LDFLAGS = -lm   # Libraries to link, e.g., math library, if needed

# Source and object files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/fileUtils.c $(SRC_DIR)/serial.c $(SRC_DIR)/esp_protocol.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Output binary name
TARGET = $(BUILD_DIR)/SerialFlasher

# Default target to build the project
all: $(TARGET)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $(TARGET)

# Clean up build artifacts
clean:
	rm -f $(BUILD_DIR)/* $(OBJ_FILES)

# Run tests (if applicable, you can add more specific tests)
test: $(TARGET)
	# Example: running tests with the compiled binary
	./$(TARGET)

.PHONY: all clean test

