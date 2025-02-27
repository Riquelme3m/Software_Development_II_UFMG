#ifndef DOG
#define DOG
#include "animal.hpp"

class Dog : public Animal
{
public:
    virtual void make_noise() override;
};

#endif