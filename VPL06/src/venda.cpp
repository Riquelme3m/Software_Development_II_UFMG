#include "venda.hpp"
#include <sstream>
int Venda::_total_numero_de_pedidos_processados=0;

void Venda::adicionaPedido(Pedido *p){
    _pedidos.push_back(p);
    _total_numero_de_pedidos_processados++;
}

void Venda::imprimeRelatorio() const{

    std::list<Pedido*>::const_iterator it = _pedidos.begin();
    int count=1;
    std::string relatorio="";
    float total_de_vendas=0;
    for(it;it!=_pedidos.end();it++){
        relatorio+=("Pedido "+std::to_string(count)+"\n");
        relatorio+=  ((*it)->resumo())+"\n";
        total_de_vendas+= ((*it)->calculaTotal());
        count++;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << total_de_vendas;
    std::string total_de_vendas_str = oss.str();

    relatorio+="Relatorio de Vendas\n";
    relatorio+= ("Total de vendas: R$") + oss.str() +"\n";
    relatorio+= ("Total de pedidos: ") + std::to_string(_total_numero_de_pedidos_processados);
    std::cout<<relatorio<<std::endl;
}
Venda::~Venda(){
    std::list<Pedido*>::const_iterator it = _pedidos.begin();
    for(it;it!=_pedidos.end();it++){
        delete *(it);
    }
}