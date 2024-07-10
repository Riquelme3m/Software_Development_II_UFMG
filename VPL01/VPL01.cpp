#include<iostream>


int main(){


  std::string word;
  std::cin>>word;
  int countera=0,countere=0,counteri=0,countero=0,counteru=0;
  for(char c:word){
     switch(c){
       case 'a':
        countera+=1;

       break;
       case 'e':
        countere+=1;
       
        break;
       case 'i':
         counteri+=1;

        break;
       case 'o':
         countero+=1;

        break;
       case 'u':
        counteru+=1;
        break;



       default:
        break;
     }
    
  }

  if(countera!=0){
    std::cout<<"a : "<<countera<<std::endl;
  }
  if(countere!=0){
    std::cout<<"e : "<<countere<<std::endl;
  }
  if(counteri!=0){
    std::cout<<"i : "<<counteri<<std::endl;
  }
  if(countero!=0){
    std::cout<<"o : "<<countero<<std::endl;
  }
  if(counteru!=0){
    std::cout<<"u : "<<counteru<<std::endl;
  }












  return 0;
}