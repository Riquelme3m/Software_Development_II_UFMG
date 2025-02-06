#include "person.h"



Person::Person(std::string name):_name(name){};

std::string Person::get_name() const{
    return _name;
}

std::string Person::define_my_type() const{
    return "I am a person";
}