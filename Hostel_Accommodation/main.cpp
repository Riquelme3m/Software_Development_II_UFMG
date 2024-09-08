#include<iostream>
#include<string>
#include<fstream>
#include "hostel.h"
#include "student.h"
#include<chrono>
#include<thread>



int main(){

    Hostel h("3star",2,200);
    std::ofstream out("Hostel.txt"); //Create the file named as Hostel.txt
    
    out<<"\t"<<h.getName()<<" : "<<h.getRent()<<" : "<<h.getBed()<<std::endl<<std::endl;//Write on the file
    std::cout<<"Hostel Data Saved Successfully"<<std::endl;
    out.close();
    Student s;

    bool exit=false;

    while(!exit){
        int val;
        std::cout<<"\tWelcome To Hostel Accommodation System"<<std::endl;
        std::cout<<"\t***************************************"<<std::endl;
        std::cout<<"\t1.Reserve a Bed"<<std::endl;
        std::cout<<"\t2.Exit."<<std::endl;
        std::cout<<"\tEnter a Choice"<<std::endl;
        std::cin>>val;
        if(val==1){
            std::string name,rollNo,address;
            std::cout<<"Enter the Student's name : ";
            std::cin>>name;
            std::cout<<"Enter the Enrollment number : ";
            std::cin>>rollNo;
            std::cout<<"Enter the Address : ";
            std::cin>>address;
            s.setName(name);
            s.setRollNo(rollNo);
            s.setAddress(address);

            if(h.getBed()>0){
                h.reserve();
            }
            else if(h.getBed()==0){
                std::cout<<"\tSorry , Bed Not Available!"<<std::endl;
            }

            std::ofstream outFile("Student.txt",std::ios::app); //Creating a file named Student.txt
            outFile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<std::endl<<std::endl;//Writing on the file
            
            std::this_thread::sleep_for(std::chrono::seconds(3));//A short time must be given in order for the program to write on the student's information
        }
        else if(val==2){
            exit=true;
            std::cout<<"Good Luck!"<<std::endl;
        }
    }

    return 0;
}