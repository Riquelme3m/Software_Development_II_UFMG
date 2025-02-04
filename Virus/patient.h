#ifndef PDS2_PATIENT_H
#define PDS2_PATIENT_H

#include <string>

#include "virus.h"

class Patient
{

private:
    std::string _name;
    double _endurance;
    bool _infected;
    Virus *_virus;

public:
    Patient(std::string name, double endurance);
    Patient(std::string name, double endurance, Virus *virus);
    bool isInfected();
    Virus *get_virus();
    std::string get_name();
    void contact(Patient &contact);
    void heal();
};

#endif