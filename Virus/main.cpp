#include <iostream>
#include "virus.h"
#include "patient.h"

int main()
{

    Virus covid_19("COVID-19", 100.2, 4);
    
    Virus *child_1_covid_19 = covid_19.reproduce();
    Virus *child_2_covid_19 = covid_19.reproduce();
    Virus *child_3_covid_19 = covid_19.reproduce();
    Virus *grandchild_1_covid_19 = child_1_covid_19->reproduce();
    

    Patient carlos("Carlos", 100.1);

    Patient joao("João", 120.2, &covid_19);

    std::cout<<"Total number of virus : "<< Virus::get_total_number_of_infections()<<std::endl;
   

    if (carlos.isInfected())
    {
        std::cout << "Carlos is infected" << std::endl;
    }
    else
    {
        std::cout << "Carlos is not infected" << std::endl;
    }

    carlos.contact(joao);

    std::cout << "After being in contact with Joao" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    if (carlos.isInfected())
    {
        std::cout << "Carlos is infected" << std::endl;
    }
    else
    {
        std::cout << "Carlos is not infected" << std::endl;
    }

    return 0;
}