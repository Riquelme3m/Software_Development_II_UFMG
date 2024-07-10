/*
Escreva um algoritmo para realizar a cifra de César, uma das
abordagens mais antigas de criptografia. Ela consiste em deslocar
cada letra do alfabeto um número fixo de vezes. Por exemplo, para 
um deslocamento d = 2 temos:
a -> c
h -> j
z -> b (note que demos a volta no alfabeto)

Seu programa deve ler uma frase, ler o deslocamento requisitado e 
imprimir a mesma frase criptografada. Note que o comando cin por 
padrão finaliza a leitura ao encontrar o primeiro espaçamento. 
Use portanto o comando std::getline(std::cin, variavel);

Entrada
meteu essa, ze?
2

Saída
ogvgw guuc, bg?
*/

#include<iostream>
#include<string>
int main(){
  std::string phrase;
  int leap;
  std::getline(std::cin,phrase);
  std::cin>>leap;

  for(char &c:phrase){
     if(c>='A' && c<='Z'){
       c+=leap;
      if(c>'Z'){
        c=c-'Z'+'A'-1;
        
      }
     }
    else if(c>='a' && c<='z'){
      c+=leap;
      if(c>'z'){
        c=c-'z'+'a'-1;
      }
      
    }
  }
  std::cout<<phrase<<std::endl;


  return 0;
}