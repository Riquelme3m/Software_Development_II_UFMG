#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    const std::string _name;

public:
    Person(std::string name);

    std::string get_name() const;
    virtual std::string define_my_type() const;
};

#endif