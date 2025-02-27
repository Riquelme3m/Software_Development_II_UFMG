#include "image_message.hpp"

#include<iostream>
#include <fstream>

ImageMessage::ImageMessage(std::string file ){
    _file=file;
}

void ImageMessage::exhibit(){
    std::ifstream file(this->_file);
    std::string line;

    while(std::getline(file,line)){
        std::cout<<line<<std::endl;
    }
    file.close();

}