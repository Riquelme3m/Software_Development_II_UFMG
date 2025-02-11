#include <string>
#include <vector>
#include <map>
#include <iostream>
class Intruso{
    
    private:
        std::vector<std::string> _written_password;
        std::vector<std::map<std::string,std::string>>_associations;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};