#include"animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "cow.hpp"
#include<iostream>


int main(){

    Animal* cat= new Cat();
    Animal *dog = new Dog();
    Animal *cow = new Cow();

    
    cat->make_noise();
    dog->make_noise();
    cow->make_noise();
    
    
    
    
    delete cat;
    delete dog;
    delete cow;
    
    
    
    return 0;
}





