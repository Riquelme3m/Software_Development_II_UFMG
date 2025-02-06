#include "acai.hpp"

Acai::Acai(int tamanho, std::vector<std::string> &complementos, int qtd)
{
    this->_tamanho = tamanho;
    this->_complementos = complementos;
    this->_quantidade = qtd;
};

float Acai::calcPreco()
{
    float preco = 0;
    preco += 0.0200 * _tamanho;
    preco += _complementos.size() * 2;
    preco *= _quantidade;
    return preco;
}

std::string Acai::descricao() const
{
    std::string descricaoAcai = std::to_string(_quantidade) + "X acai " + std::to_string(_tamanho) + " com ";
    for (int i = 0; i < _complementos.size(); i++)
    {
        if (i < _complementos.size() - 1; i++)
        {
            descricaoAcai += (_complementos[i] + ", ");
        }
        else
        {
            descricaoAcai += (_complementos[i] + ".");
        }
    }
    return descricaoAcai;
}