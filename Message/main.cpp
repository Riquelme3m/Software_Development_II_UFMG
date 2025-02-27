#include "message.hpp"
#include "image_message.hpp"
#include "text_message.hpp"


void exhibit_on_screen(MessageIf &msg){
    msg.exhibit();
}

int main(){


    TextMessage text = TextMessage("Hey , my name is Batista");
    ImageMessage img = ImageMessage("image_text.txt");

    exhibit_on_screen(text);
    exhibit_on_screen(img);
    








    return 0;
}