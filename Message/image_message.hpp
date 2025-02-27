#ifndef PDS2_IMAGE_TEXT_H
#define PDS2_IMAGE_TEXT_H

#include <string>
#include "message.hpp"


class ImageMessage : public MessageIf{
    private:
        std::string _file;

    public:
        ImageMessage(std::string file);
        virtual void exhibit() override;


};






#endif