CXX = g++
STAND = -std=c++11
OPTS = -O2 -Wall
TARGET = cache
SOURCE_PATH = source/main.cpp
INCLUDE_PATH = include/cache.hpp

.PHONY: all uninstall

all: $(TARGET) clean

main.o: $(SOURCE_PATH)
			$(CXX) -c -o main.o $(SOURCE_PATH)
cache.o: $(INCLUDE_PATH)
			$(CXX) -c -o cache.o $(INCLUDE_PATH)

$(TARGET): cache.o main.o
	$(CXX) -o $(TARGET) $(STAND) $(OPTS) $(SOURCE_PATH)

clean:
	rm -rf *.o

uninstall:
	rm -rf $(TARGET)