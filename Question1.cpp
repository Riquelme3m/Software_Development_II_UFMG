/*
Q1 - Faça um programa que leia e armazene 2 sequências de 
7 inteiros cada. Em seguida imprima:
- Os quadrados de cada elemento da primeira sequência
- A soma de cada elemento das duas sequências, nas 
respectivas posições
- A soma de cada elemento da primeira sequência com a 
segunda sequência invertida.

Atenção: use o laço compacto pelo menos uma vez.

Passo 1: Leia duas sequências
1 5 7 3 22 0 11
3 9 56 0 0 1 0

Passo 3: Calcule e imprima os requisitos da questão
Quadrados: 1 25 49 9 484 0 121
Soma: 4 14 63 3 22 1 11
Soma invertida: 1 6 7 3 78 9 14
*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
    std::vector<int> a(7),b(7);
    for(int& x:a){
      std::cin>>x;
    }
    for(int& x:b){
      std::cin>>x;
    }
    for(int x:a){
      std::cout<<x*x<<" ";
    }
    std::cout<<std::endl;
    for(int i=0;i<a.size();i++){
      std::cout<<a[i]+b[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0;i<b.size();i++){
      std::cout<<a[i]+b[b.size()-1-i]<<" ";
      
    }
    std::cout<<std::endl;
  
}