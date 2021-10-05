CXX = g++
STAND = -std=c++11
OPTS = -O2 -Wall
TARGET = cache
SOURCE_PATH = source/main.cpp
INCLUDE_PATH = include/cache.hpp

.PHONY: all uninstall clean

all: $(TARGET)

main.o: $(SOURCE_PATH)
			$(CXX) -c -o main.o $(SOURCE_PATH)
$(TARGET): main.o $(INCLUDE_PATH)
	$(CXX) -o $(TARGET) $(STAND) $(OPTS) $(SOURCE_PATH)

clean:
	rm -rf *.o

uninstall:
	rm -rf $(TARGET)