# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c++11

# Source files
SRCS = main.cpp PressureSource.cpp PA33X.cpp AltimeterSource.cpp PA200.cpp Sensor.cpp SensorThread.cpp InertiaSource.cpp MTi_30_AHRS.cpp DataBridge.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)