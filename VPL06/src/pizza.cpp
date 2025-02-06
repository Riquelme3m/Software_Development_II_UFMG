#include "pizza.hpp"

Pizza::Pizza(const std::string& sabor,int pedacos,bool borda_recheada,int qtd){
    _sabor=sabor;
    _pedacos=pedacos;
    _borda_recheada=borda_recheada;
    _quantidade=qtd;
    
}


float Pizza::calcPreco()
{
    float preco=0;
    preco+= _pedacos*5;

    if(_borda_recheada){
        preco+=10;
    }
    if(_sabor.find("special")!=std::string::npos){
        preco+=8;
    }
    preco*=_quantidade;
    return preco;
}

std::string Pizza::descricao() const
{
    std::string descricaoPizza =
        std::to_string(this->_quantidade) + "X pizza " + this->_sabor;

    if (_borda_recheada)
    {
        return descricaoPizza + " com borda recheada";
    }
    return descricaoPizza + " sem borda recheada";
}