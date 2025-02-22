#ifndef _SAVING_ACCOUNT
#define _SAVING_ACCOUNT
#include "account.hpp"

class savingAccount : public Account
{
private:
    float _yield;

public:
    savingAccount(float balance,float yield);//tested
    void setYield(float yield);//tested
    float getYield();//tested
    void calculateYield();//tested
       
};

#endif