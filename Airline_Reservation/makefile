CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp flight.cpp
OBJS = $(SRCS:.cpp=.o)

# Binary output
TARGET = airline_reservation

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) -lmysqlcppconn

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
