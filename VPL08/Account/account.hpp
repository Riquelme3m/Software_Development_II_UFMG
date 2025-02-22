#ifndef _ACCOUNT
#define _ACCOUNT

class Account{
    protected:
        float _balance;

    public:
        Account(float balance);
        void showBalance();
        virtual void withdraw(float withdrawValue);
        virtual void deposit(float depositValue);
        float getBalance();
        void setBalance(float newBalance);
};



#endif