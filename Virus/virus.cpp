#include "virus.h"
#include<iostream>

int Virus::_total_number_of_infections=0;

Virus::Virus(std::string name,double strength,int reproduction_capacity){
    _name=name;
    _strength=strength;
    _reproduction_capacity=reproduction_capacity;
    _number_of_children=0;
    _children = new Virus*[_reproduction_capacity]();
    _total_number_of_infections++;
}



std::string Virus::get_name(){
    return this->_name;
}
double Virus::get_strength(){
    return this->_strength;
}

Virus* Virus::reproduce(){
    if(this->_number_of_children == this->_reproduction_capacity){
        std::cout<<"It's not possible to reproduce anymore"<<std::endl;
        return nullptr;
    }
    Virus* new_virus = new Virus(_name,_strength,_reproduction_capacity); //Create a virus with the same carachteristics
    _children[_number_of_children]=new_virus;
    _number_of_children+=1;
    return _children[_number_of_children-1]; //Return a pointer to this new Child
}

int Virus::get_total_number_of_infections(){
    return Virus::_total_number_of_infections;
}

Virus::~Virus(){
    if(_children != nullptr){
        for(int i=0;i<_number_of_children;i++){
            if(_children[i]!=nullptr){
                std::cout<<"Destructor Called"<<std::endl;
                delete _children[i];
                
                
            }
        }
        std::cout<<"Destruct called upon parent"<<std::endl;
        delete[] _children;
        _total_number_of_infections--;
        
    }
}


