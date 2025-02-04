#include "patient.h"



Patient::Patient(std::string name,double endurance){
    _name=name;
    _endurance=endurance;
    _infected=false;
    _virus=nullptr;
   
}

Patient::Patient(std::string name,double endurance, Virus* virus){
    _name=name;
    _endurance=endurance;
    _infected=true;
    _virus=virus;

}

bool Patient::isInfected(){
    return _infected;
}

Virus* Patient::get_virus(){
    return _virus;
}

std::string Patient::get_name(){
    return _name;
}

void Patient::contact(Patient &contact){
    if(contact.isInfected() && !this->isInfected()){
        if(contact.get_virus()->get_strength() > _endurance){
            _infected=true;
            _virus = contact.get_virus();
        }
    }
}

void Patient::heal(){

}