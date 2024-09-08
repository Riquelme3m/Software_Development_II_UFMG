#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

class Hostel{

    private:
    std::string Name;
    int Bed;
    int Rent;

    public:
    Hostel(std::string name,int bed,int rent);
    std::string getName();
    int getRent();
    int getBed();
    void reserve();


};