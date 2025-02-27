
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


int fatorial(int n){
    if(n<0) throw std::invalid_argument("n<0 inválido");
    if(n<=1)return 1;
    return n*fatorial(n-1);
}

TEST_CASE("Testando o fatorial geral"){
    
    CHECK_EQ(2,fatorial(2));
    CHECK_EQ(6,fatorial(3));
    CHECK_EQ(24,fatorial(4));
    CHECK_EQ(3628800,fatorial(10));
}

TEST_CASE("Testando o caso especial"){
    CHECK(fatorial(0)==1);
}
TEST_CASE("Testando o caso negativo"){
    CHECK_THROWS(fatorial(-1));
    CHECK_THROWS(fatorial(-3));
}
