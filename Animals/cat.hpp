#ifndef CAT
#define CAT
#include "animal.hpp"

class Cat: public Animal{
    public:
    virtual void make_noise() override;
};


#endif