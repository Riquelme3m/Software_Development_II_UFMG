#include <iostream>
#include <string>

class Date
{
    int _day, _month, _year;

public:
    Date(int day, int month, int year) : _day(day), _month(month), _year(year) {};

    std::string print()
    {
        return std::to_string(_day) + "/" + std::to_string(_month) + "/" + std::to_string(_year);
    }
};
class Hour
{
    int _hour, _minute, _second;

public:
    Hour(int hour, int minute, int second) : _hour(hour), _minute(minute), _second(second) {};

    std::string print()
    {
        return std::to_string(_hour) + ":" + std::to_string(_minute) + ":"+ std::to_string(_second);
    }
};

class Calendar{
    Date _date;
    Hour _hour;
    public:
    Calendar(int year,int month,int day,int hour,int minute,int second): _date(year,month,day),_hour(hour,minute,second){};
    std::string print(){
        std::string currentDate = _date.print();
        currentDate+="\n";
        currentDate+=_hour.print();
        return currentDate;
    }
};

int main()
{
    Calendar* myCalendar = new Calendar(2025,22,2,2,45,0);
    std::cout<<myCalendar->print()<<std::endl;
    return 0;
}