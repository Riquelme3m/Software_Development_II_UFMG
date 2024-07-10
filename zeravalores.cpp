/*Escreva uma função “zera_valores” que 
recebe um vetor de inteiros, encontra 
valores menores que seus vizinhos imediatos 
(esquerda e direita) e os substitui por zero.
Vetor de entrada: 1 4 5 2 3 1 7 
Vetor ao final da função: 1 4 5 0 3 0 7*/

#include<iostream>
#include<vector>


std::vector<int> zera_Valores(std::vector<int>& x){
    for(int i=1;i<x.size()-1;i++){
        if(x[i]<x[i-1] && x[i]<x[i+1]){
            x[i]=0;
        }
    }
    return x;
};

int main(){

    std::vector<int> myvector={1,4,5,2,3,1,7};
    zera_Valores(myvector);
    for(int x:myvector){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;





    return 0;
}