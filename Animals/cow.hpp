#ifndef COW
#define COW

#include "animal.hpp"

class Cow:public Animal{

    public:
    virtual void make_noise() override;
};


#endif