#include "checkingAccount.hpp"
#include <iostream>

void checkingAccount::setFee(float fee){
    _fee=fee;
}
float checkingAccount::getFee(){
    return _fee;
}

void checkingAccount::withdraw(float withdrawValue){
    if(withdrawValue*(1+_fee)>_balance){
        std::cout<<"There is no enough balance to make this transaction"<<std::endl;
        return;
    }
    _balance-=(withdrawValue*(1+_fee));
}

void checkingAccount::deposit(float depositValue){
    _balance +=(depositValue*(1-_fee));
}

checkingAccount::checkingAccount(float balance,float fee):Account(balance),_fee(fee){};

