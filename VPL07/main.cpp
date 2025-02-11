#include <iostream>
#include "intruso.hpp"

int main(){
    int num_entradas, i;
    std::string senha;
    Intruso intruso;
    
    std::cin >> num_entradas;
    std::cin.ignore();

    for(i=0; i < num_entradas; i++){
        std::getline(std::cin, senha);
        std::string senhaModificadaParaInput;
        for(int i=0;i<senha.size();i++){
            if(senha[i] !=' '){
                std::string ch(1,senha[i]);
                senhaModificadaParaInput+=ch;
            }
        }
        intruso.set_senha_vazada(senhaModificadaParaInput);
    }
    std::cout << intruso.crack_senha() <<std::endl;
    
    return 0;
}