#include <iostream>
#include <string>
using namespace std;

class Produto
{
    int id;
    std::string nome;
    float preco;

public:
    Produto() = default;
    Produto(int i, string s, float p) : id(i), nome(s), preco(p) {}
    void imprime()
    {
        std::cout << id << " "
                  << nome << " "
                  << preco << "\n";
    }
};

class Eletronico : public Produto
{
    int garantia;

public:
    Eletronico() = default;
    Eletronico(int i, string s, float p, int g = 0) : Produto(i, s, p), garantia(g) {}
    void comprar_garantia(int g)
    {
        garantia = g;
    }
};

int main()
{
    Produto p1;
    Produto p2(3418, "Controle", 399.19);
    Produto p3(1301, "Celular", 1280.99, 60); //This line is wrong
    p3.imprime(); //This line is wrong

    Produto* pel = new Eletronico();
    pel->imprime();
    pel->comprar_garantia(120); //This line is wrong , pel does not have a member comprar_garantia
    Eletronico el1;
    Eletronico el2(1092, "Action Figure", 92.99);
    Eletronico el3(1093, "Chaveiro", 12.99, 60);
    el3.imprime();
    el3.comprar_garantia(120);
}