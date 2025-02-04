#ifndef PDS2_VIRUS_H
#define PDS2_VIRUS_H

#include <string>



class Virus{
    private:
        std::string _name;
        double _strength;
        Virus **_children;
        int _number_of_children;
        int _reproduction_capacity;
        static int _total_number_of_infections;
    public:
        Virus(std::string name,double strength,int reproduction_capacity);
        ~Virus();
        std::string get_name();
        double get_strength();
        Virus* reproduce();
        static int get_total_number_of_infections();
        


};

#endif