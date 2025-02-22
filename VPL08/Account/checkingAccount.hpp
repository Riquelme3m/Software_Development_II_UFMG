#ifndef _CHECKING_ACCOUNT
#define _CHECKING_ACCOUNT
#include "account.hpp"

class checkingAccount : public Account
{
private:
    float _fee;

public:
    void setFee(float fee);//tested
    float getFee(); //tested
    void withdraw(float withdrawValue) override;//tested
    void deposit(float depositValue) override;//tested
    checkingAccount(float balance,float fee);//tested
};

#endif