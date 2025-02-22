#include<iostream>


class Lamp{

    private:
    int _watts;
    float _price;


    public:
        Lamp(){
            std::cout<<"Calling A constructor"<<std::endl;
        }
        Lamp(int watts){
            _watts=watts;
            std::cout<<"Calling B constructor"<<std::endl;
        }
        Lamp(int watts,float price){
            _watts=watts;
            _price=price;
            std::cout<<"Calling C constructor"<<std::endl;
        }
        float operator+(Lamp const &lp) const{
            return this->_price + lp._price;
        }

       

};





int main(){

    Lamp *first = new Lamp(10,22.35);
    Lamp *second = new Lamp(20,30.35);
    float sum = *first + *second;
    std::cout<<sum<<std::endl;

    




    delete first;
    delete second;











    return 0;
}