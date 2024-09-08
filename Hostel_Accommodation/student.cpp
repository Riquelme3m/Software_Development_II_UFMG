#include "student.h"

Student::Student():Name(""),RollNo(""),Address(""){

}
void Student::setName(std::string name){
    Name=name;
}

void Student::setRollNo(std::string rollno){
    RollNo=rollno;
}
void Student::setAddress(std::string address){
    Address=address;
}

std::string Student::getName(){
    return Name;
}
std::string Student::getRollNo(){
    return RollNo;
}
std::string Student::getAddress(){
    return Address;
}