# Directories
SRC_DIR = src
BUILD_DIR = build
OUTPUT_DIR = output
INCLUDE_DIR = headers

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(INCLUDE_DIR)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Output binary name
TARGET = $(OUTPUT_DIR)/SideInvaders

# Default target
all: $(TARGET)

# Link object files to binary
$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create output directory
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Clean build and output
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)
