#include "student.h"


Student::Student(int enrollment,std::string name): _enrollment(enrollment),Person(name){};
int Student::get_enrollment() const {
    return _enrollment;
}
std::string Student::define_my_type() const{
    return "I am a student";
}