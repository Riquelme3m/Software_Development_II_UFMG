#include "invalidCell.hpp"

invalidCell::invalidCell(int row,int col): _col(col),_row(row){
    _error_message = "Celula ("+std::to_string(_row)+", "+std::to_string(_col)+") nao e valida. Deseja continuar e ignora-la? (s/n)?";
}

const char* invalidCell::what() const noexcept {
    return _error_message.c_str();
}
