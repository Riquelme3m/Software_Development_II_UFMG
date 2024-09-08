#include "hostel.h"


    Hostel::Hostel(std::string name,int bed,int rent){
        Name=name;
        Bed=bed;
        Rent=rent;
    }
    std::string Hostel::getName(){
        return Name;
    }
    int Hostel::getRent(){
        return Rent;
    }
    int Hostel::getBed(){
        return Bed;
    }
    void Hostel::reserve(){
        std::ifstream in("Hostel.txt");//File to be read
        std::ofstream out("Hostel Temp.txt");//File to be written on

        std::string line;

        while(getline(in,line)){
            int pos=line.find("3star");//Searching for this substring
            if(pos!=std::string::npos){ //If the operation of searching managed to succed go to reservation
                Bed-=1;

                std::stringstream ss;
                ss<<Bed;
                std::string strBed=ss.str(); //converting integer to string

                int bedPos=line.find_last_of(": ");

                line.replace(bedPos+1,std::string::npos,strBed); //Updating the file where was written the previous number of beds
            }
                out<<line<<std::endl; //Write the line on the new file

            }
        

        out.close();
        in.close();
        remove("Hostel.txt");
        rename("Hostel Temp.txt","Hostel.txt");//Change the original file of storage
        std::cout<<"\t Bed Reserved Successfully"<<std::endl;

    }