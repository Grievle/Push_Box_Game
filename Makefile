CC = g++
CPPFLAGS=-W -Wall
TARGET = map
OBJECTS = map.o

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJECTS)

map.o:map.cpp
	$(CC) $(CPPFLAGS) -c -o map.o map.cpp
