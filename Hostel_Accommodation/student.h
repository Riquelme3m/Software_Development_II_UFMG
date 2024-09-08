#pragma once
#include<string>

class Student{

private:
    std::string Name;
    std::string RollNo;
    std::string Address;

public:
    Student();
    void setName(std::string name);
    void setRollNo(std::string rollNo);
    void setAddress(std::string address);
    std::string getName();
    std::string getRollNo();
    std::string getAddress();


};