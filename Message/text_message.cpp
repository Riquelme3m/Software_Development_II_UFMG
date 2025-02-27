#include "text_message.hpp"
#include <iostream>


TextMessage::TextMessage(std::string msg){
    _msg=msg;
}

void TextMessage::exhibit(){
    std::cout<<"This is the message: "<<this->_msg<<std::endl;
}