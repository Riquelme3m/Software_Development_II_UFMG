#include"account.hpp"
#include"savingAccount.hpp"
#include "checkingAccount.hpp"
#include<iostream>


int main(){


    Account* first = new checkingAccount(1000,0.1);
    first->withdraw(100);
    first->showBalance();





    return 0;
}