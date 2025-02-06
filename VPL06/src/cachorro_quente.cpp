#include "cachorro_quente.hpp"

CachorroQuente::CachorroQuente(int num_salsichas, std::vector<std::string> complementos, bool prensado, int qtd)
{
    this->_num_salsichas = num_salsichas;
    this->_complementos = complementos;
    this->_prensado = prensado;
    this->_quantidade = qtd;
}

float CachorroQuente::calcPreco()
{
    float preco = 5;
    preco += 1.5000 * _num_salsichas;
    preco += 1 * _complementos.size();

    if (_prensado==true)
    {
        preco += 0.500;
    }
    preco *= this->_quantidade;
    return preco;
}

std::string CachorroQuente::descricao() const
{
    std::string quant = std::to_string(_quantidade);
    std::string numSalsicha = std::to_string(_num_salsichas);
    std::string complementosCachorroQuente = "";
    for (int i = 0; i < _complementos.size(); i++)
    {
        if (i != _complementos.size() - 1)
        {
            complementosCachorroQuente += _complementos[i] + ", ";
        }
        else
        {
            complementosCachorroQuente += _complementos[i] + ".";
        }
    }
    return quant + "X" + " cachorro-quente com  " + numSalsicha + " salsichas, " + complementosCachorroQuente;
}