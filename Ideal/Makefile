CXX = g++
STAND = -std=c++11
OPTS = -O2 -Wall
TARGET = cache
SOURCE_PATH = source/main.cpp
INCLUDE_PATH = include/ideal.hpp

.PHONY: all uninstall clean

all: $(TARGET)

$(TARGET): $(INCLUDE_PATH) $(SOURCE_PATH)
	$(CXX) -o $(TARGET) $(STAND) $(OPTS) $(SOURCE_PATH)

clean:
	rm -rf *.o

uninstall:
	rm -rf $(TARGET)