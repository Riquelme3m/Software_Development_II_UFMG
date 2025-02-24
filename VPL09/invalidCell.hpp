#ifndef _INVALID_CELL
#define _INVALID_CELL
#include <string>

class invalidCell : public std::exception
{
private:
    int _col;
    int _row;
    std::string _error_message;

public:
    invalidCell(int col, int row);
    const char* what() const noexcept override;
  
};

#endif