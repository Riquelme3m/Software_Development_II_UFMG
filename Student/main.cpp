#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "student.h"

void f(Person &person){
    std::cout<<"In function: "<<person.define_my_type()<<std::endl;
}


class Listofstudents
{
private:
    std::vector<Student *> _students;
    

public:
    void insertStudent(Student *student)
    {
        std::vector<Student *>::iterator it = _students.begin();
        std::vector<Student *>::iterator ed = _students.end();

        while (it != ed && (*it)->get_enrollment() < student->get_enrollment())
        {
            it++;
        }
        _students.insert(it, student);
    }

    void getenrollments(){
        for(auto i:_students){
            std::cout<<"Student's name: "<<i->get_name()<<std::endl;
            std::cout<<"Enrollment: "<<i->get_enrollment()<<std::endl;
        }
    }
};

int main()
{

    
    Person me = Person("Riquelme");
    Student *meStudent = new Student(2021014317, me.get_name());
    Person another("Joao");
    Student *anotherStudent = new Student(2022014317, another.get_name());
    Person anothertwo("Carlos");
    Student *anothertwoStudent = new Student(2019014317, anothertwo.get_name());

    Listofstudents UFMG;
    UFMG.insertStudent(meStudent);
    UFMG.insertStudent(anotherStudent);
    UFMG.insertStudent(anothertwoStudent);
    
    UFMG.getenrollments();
    delete meStudent;
    delete anotherStudent;
    delete anothertwoStudent;

    Person somebody = Person("Flavio");
    Student somestudent = Student (2021011,"Jane");
    std::cout<<"This person is: "<<somebody.define_my_type()<<std::endl;
    std::cout<<"This student is:"<<somestudent.define_my_type()<<std::endl;

    Person *p2 = &somestudent;
    std::cout<<p2->define_my_type()<<std::endl;
    


    
    
    


    return 0;
}