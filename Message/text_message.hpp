#ifndef PDS2_TEXT_MESSAGE_H
#define PDS2_TEXT_MESSAGE_H

#include "message.hpp"
#include <string>

class TextMessage: public MessageIf{
    private:
        std::string _msg;
    public:
        TextMessage(std::string msg);
        virtual void exhibit() override;
};




#endif