#include "flight.h"

Flight::Flight(std::string Fnum, std::string Dep, std::string Dest, int seat) {
    Flight_number = Fnum,
    Departure = Dep,
    Destination = Dest,
    Seat = seat;
}

std::string Flight::getFlightnumber() {
    return Flight_number;
}

std::string Flight::getDeparture() {
    return Departure;
}

std::string Flight::getDestination() {
    return Destination;
}

int Flight::getSeat() {
    return Seat;
}
