#ifndef STUDENT_H
#define STUDENT_H


#include<string>
#include "person.h"

class Student : public Person
{
private:
    int _enrollment;

public:
    Student(int enrollment, std::string name);
    int get_enrollment() const;
    std::string define_my_type() const override ;
};

#endif