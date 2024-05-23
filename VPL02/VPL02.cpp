#include<iostream>

using namespace std;

class Categoria{
private:
    int codigo_Categoria;
    double valor_Caixa;
public:

    Categoria(int codigo_Categoria,double valor_Caixa) {
        this->codigo_Categoria=codigo_Categoria,
        this->valor_Caixa=valor_Caixa;
    }
    Categoria();

    // Recupera o código correspondente a uma categoria.
    int getCodigo() {
        return codigo_Categoria;
    }

    // Recupera o valor em caixa de uma categoria.
    double getValorCaixa(){
        return valor_Caixa;
    }

    // Adiciona uma quantia ao caixa de uma categoria.
    void adicionaCaixa(double valor) {
        valor_Caixa+=valor;
    }

    // Remove uma quantia ao caixa de uma categoria.
    void gastaCaixa(double valor) {
        valor_Caixa-=valor;
    }
    // *********************************

};



class Orcamento {
private:
  Categoria Saude;
  Categoria Educacao;
  Categoria Seguranca;
  Categoria Previdencia;
  Categoria Administracao_Publica;

public:
  Orcamento(double impostos):
    Saude(0,impostos*0.15),
    Educacao(1,impostos*0.15),
    Seguranca(2,impostos*0.2),
    Previdencia(3,impostos*0.35), 
    Administracao_Publica(4,impostos*0.15){}
  


  ~Orcamento(){
    
  }



    // Reduz o valor no caixa da categoria especificada.
    void gastoCategoria(int codigo_categoria, double valor) {
        switch(codigo_categoria){
          case 0:
            Saude.gastaCaixa(valor);
          break;
          case 1:
            Educacao.gastaCaixa(valor);
          break;
          case 2:
            Seguranca.gastaCaixa(valor);
          break;
          case 3:
            Previdencia.gastaCaixa(valor);
          break;
          case 4:
            Administracao_Publica.gastaCaixa(valor);
          break;
          default:
            std::cout<<"Código de categoria inválido"<<std::endl;
          break;
        }
    }

    // Retorna o valor em caixa da categoria especificada.
    double getSaldo(int codigo_categoria) {
      switch(codigo_categoria){
        case 0:
          return Saude.getValorCaixa();
        break;
        case 1:
          return Educacao.getValorCaixa();
        break;
        case 2:
          return Seguranca.getValorCaixa();
        break;
        case 3:
          return Previdencia.getValorCaixa();
        break;
        case 4:
          return Administracao_Publica.getValorCaixa();
        break;
        default:
          std::cout<<"Código de categoria inválido"<<std::endl;
          return 0.0;
        break;
      }
    }

    // Retorna o ponteiro para o objeto da categoria especificada.
    Categoria* getCategoria(int codigo_categoria) {
      switch(codigo_categoria){
        case 0:
          return &(this->Saude);
        break;
        case 1:
          return &Educacao;
        break;
        case 2:
          return &(this->Seguranca);
        break;
        case 3:
          return &Previdencia;
        break;
        case 4:
          return &(this->Administracao_Publica);
        break;
        
        default:
        std::cout<<"Código inválido"<<std::endl;
        return 0;
        break;
      }
    }

    // *********************************
};



int main() {

  Orcamento* orcamento=nullptr;
  char test = 0;
  while(cin >> test) {
      switch (test) {
        case 'o': { // Inicia novo orçamento
          double valor = 0;
          cin >> valor;
          orcamento=new Orcamento(valor);
          
        }
        break;
        case 'g': { // Gastar em uma categoria
          int categoria = 0;
          double valor = 0;
          cin >> categoria >> valor;

          orcamento->gastoCategoria(categoria,valor);

          cout << categoria << ": " << orcamento->getSaldo(categoria) << endl;
        }
        break;
        case 'p': { // Imprimir todas as categorias e seus saldos
          for (int categoria = 0; categoria < 5; categoria++) {
            cout << categoria << ": " << orcamento->getCategoria(categoria)->getValorCaixa() << endl;
          }
        }
        break;
        default: {
          cout << "----------" << endl;
        } break;
      }
  }
  delete orcamento;
  return 0;
}
