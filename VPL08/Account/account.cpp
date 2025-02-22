#include <iostream>
#include "account.hpp"


Account::Account(float balance){
    _balance=balance;
}
void Account::showBalance()
{
    std::cout << "The current balance is : " << _balance << std::endl;
}

void Account::withdraw(float withdrawValue)
{
    if (withdrawValue > _balance)
    {
        std::cout << "Impossible to withdraw more money that you current have" << std::endl;
        return;
    }
    _balance-=withdrawValue;
}
void Account::deposit(float depositValue)
{
    _balance+=depositValue;
}

float Account::getBalance()
{
    return _balance;
}
void Account::setBalance(float newBalance)
{
    if(newBalance<0){
        std::cout<<"Impossible to make this transaction"<<std::endl;
        return;
    }
    _balance=newBalance;
}