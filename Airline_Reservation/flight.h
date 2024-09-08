#pragma once
#include <string>

class Flight {
private:
    std::string Flight_number, Departure, Destination;
    int Seat;

public:
    Flight(std::string Fnum, std::string Dep, std::string Dest, int seat);
    std::string getFlightnumber();
    std::string getDeparture();
    std::string getDestination();
    int getSeat();
};
