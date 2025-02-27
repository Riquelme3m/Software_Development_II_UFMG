#include<iostream>


class Polygon{

    private:
        double _height;
        double _depth;


    public:
        Polygon(double height,double depth): _height(height),_depth(depth){};
        virtual double calculateArea(){
            return _height*_depth;
        }

};

class Square : public Polygon{
    private:
        double _side;
    public:
    Square(double side): _side(side) , Polygon(side,side){};
    double calculateArea ()override{
        return _side*_side;
    }
};

class Triangle : public Polygon{
    private:
        double _width;
        double _height;
    public:
        Triangle(double width,double height):_width(width),_height(height),Polygon(width,height){};
        double calculateArea() override{
            return (_width*_height)/2;
        }
};



int main(){

    Square* s1 = new Square(10);
    Triangle* t1 = new Triangle(10,10);

    std::cout<<"Square area is : "<<s1->calculateArea()<<std::endl;
    std::cout<<"Triangle area is : "<<t1->calculateArea()<<std::endl;








    return 0;
}