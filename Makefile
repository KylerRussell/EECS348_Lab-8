CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = lab8.exe

SOURCES = main.cpp matrix.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)
