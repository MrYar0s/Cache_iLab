CXX = g++
STAND = -std=c++11
OPTS = -O2 -Wall
TARGET = cache
SOURCE_PATH = source/main.cpp

.PHONY: all uninstall

all: $(TARGET)

$(TARGET): $(SOURCE_PATH)
	$(CXX) -o $(TARGET) $(STAND) $(OPTS) $(SOURCE_PATH) -I include/

uninstall:
	rm -rf $(TARGET)