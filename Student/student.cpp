#include <iostream>
#include <string>
#include <vector>

class Person
{

private:
    const std::string _name;

public:
    Person(std::string name) : _name(name)
    {
    }

    std::string get_name() const
    {
        return _name;
    }
};

class Student : public Person
{
private:
    int _enrollment;

public:
    Student(int enrollment, std::string name) : _enrollment(enrollment), Person(name)
    {
    }
    int get_enrollment() const
    {
        return _enrollment;
    }
};

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

    Person me("Riquelme");
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

    return 0;
}