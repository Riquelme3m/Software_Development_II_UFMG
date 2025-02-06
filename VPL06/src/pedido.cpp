#include "pedido.hpp"



void Pedido::setEndereco(const std::string &endereco)
{
    this->_endereco = endereco;
}

void Pedido::adicionaProduto(Produto *p)
{
    this->_produtos.push_back(p);
}

float Pedido::calculaTotal() const
{
    float somaValores = 0;
    for (std::list<Produto *>::const_iterator it = _produtos.begin();
         it !=_produtos.end();++it)
    {
        
        somaValores += (*it)->calcPreco();
        
    }
    
    
    return somaValores;
}

std::string Pedido::resumo() const
{
    std::string resumoPedido = "";

    for (auto i : _produtos)
    {
        resumoPedido += (i->descricao());
        resumoPedido += "\n";
    }
    resumoPedido += "Endereco: " + _endereco;
    return resumoPedido;
}
Pedido::~Pedido()
{
    std::list<Produto *>::iterator it = _produtos.begin();
    for (it; it != _produtos.end(); it++)
    {
        delete *it;
    }
}
