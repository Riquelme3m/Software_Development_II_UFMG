/*Implemente uma televisão. A televisão tem um controle de volume 
do som (0-100) e um controle de seleção de canal (1 a 99).
- A operação construtora inicia a TV no canal 10 e volume 0
- A operação que altera o canal pode receber o caracter ‘+’ ou ‘-’ 
para alterar o canal em uma unidade
- A operação que altera o volume recebe um caracter (‘+’, ‘-’ ou 
‘M’ para mudo) referente à ação desejada
- Crie uma função main que constroi o objeto TV, aumenta o 
volume até 3 e muda para o canal 15.
- Quem serão os atributos? É necessário criar getters e setters?
*/




#include<iostream>
using namespace std;

class Television{
    private:
        int volume;
        int channel;

    public:
        Television(){
            volume=0;
            channel=10;
        };
        void Changechannel(char button){
            if((button=='+') && (channel<99)){
                channel+=1;
            }
            else if((button='-') && (channel!=0)){
                channel-=1;
            }
        }
        void ChangeVolume(char button){
            if(button=='+' && volume<100){
                volume+=1;
            }
            else if(button=='-' && volume>0){
                volume-=1;
            }
            else if(button=='M'){
                volume=0;
            }
        }
        int getChannel(){
            return channel;
        }
        int getVolume(){
            return volume;
        }

};

int main(){
    Television SempToshiba;
    std::cout<<SempToshiba.getChannel()<<std::endl;
    std::cout<<SempToshiba.getVolume()<<std::endl;
    SempToshiba.ChangeVolume('+');
    SempToshiba.ChangeVolume('+');
    SempToshiba.ChangeVolume('+');
    SempToshiba.Changechannel('+');
    SempToshiba.Changechannel('+');
    SempToshiba.Changechannel('+');
    SempToshiba.Changechannel('+');
    SempToshiba.Changechannel('+');
    std::cout<<SempToshiba.getVolume()<<std::endl;
    std::cout<<SempToshiba.getChannel()<<std::endl;












    return 0;
}