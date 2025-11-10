# Directories
SRC_DIR = src
BUILD_DIR = build
OUTPUT_DIR = output
INCLUDE_DIR = headers
DLL_DIR = C:\Users\lukem\SFML-3.0.2\bin

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(INCLUDE_DIR) -I"C:/Users/lukem/SFML-3.0.2/include"
LDFLAGS = -mconsole -L"C:/Users/lukem/SFML-3.0.2/lib" -lsfml-graphics -lsfml-window -lsfml-system   

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Output binary name
TARGET = $(OUTPUT_DIR)/SideInvaders.exe

# Default target
all: $(TARGET)

# Link object files to binary
$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)
	xcopy /Y /E /I "assets" "$(OUTPUT_DIR)\assets"
	copy "$(DLL_DIR)\sfml-graphics-3.dll" "$(OUTPUT_DIR)\"
	copy "$(DLL_DIR)\sfml-window-3.dll" "$(OUTPUT_DIR)\"
	copy "$(DLL_DIR)\sfml-system-3.dll" "$(OUTPUT_DIR)\"

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory (Windows command)
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Create output directory (Windows command)
$(OUTPUT_DIR):
	if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)

# Clean build and output
clean:
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
	if exist $(OUTPUT_DIR) rmdir /S /Q $(OUTPUT_DIR)
