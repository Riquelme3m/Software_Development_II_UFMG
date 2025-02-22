#include "savingAccount.hpp"
#include <iostream>

void savingAccount::setYield(float yield)
{
    _yield = yield;
}
float savingAccount::getYield()
{
    return _yield;
}

void savingAccount::calculateYield()
{
    std::cout << _balance * (1 + _yield) << std::endl;
}
savingAccount::savingAccount(float balance, float yield) : Account(balance), _yield(yield)
{
}
