#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou)
{
    // Getting information first
    std::map<std::string, std::string> aux;
    std::string written_password;
    for (int i = 0; i < vazou.size(); i++)
    {
        if (i < 10)
        {
            switch (i)
            {
            case 1:
            {
                std::string f(1, vazou[i - 1]);
                std::string s(1, vazou[i]);
                aux["A"] = f + s;
                break;
            }

            case 3:
            {
                std::string f(1, vazou[i - 1]);
                std::string s(1, vazou[i]);
                aux["B"] = f + s;
                break;
            }
            case 5:
            {
                std::string f(1, vazou[i - 1]);
                std::string s(1, vazou[i]);
                aux["C"] = f + s;
                break;
            }
            case 7:
            {
                std::string f(1, vazou[i - 1]);
                std::string s(1, vazou[i]);
                aux["D"] = f + s;
                break;
            }
            case 9:
            {
                std::string f(1, vazou[i - 1]);
                std::string s(1, vazou[i]);
                aux["E"] = f + s;
                break;
            }

            default:
                break;
            }
        }

        else
        {
            written_password += vazou[i];
        }
    }
    _associations.push_back(aux);
    _written_password.push_back(written_password);
}

std::string Intruso::crack_senha()
{
    std::string cracked_password = "";

    // std::vector<std::string> _written_password;
    // std::vector<std::map<std::string,std::string>>_associations;
    std::string collection_of_written_letters;
    int count = 0;
    while (count < 6)
    {
        for (int i = 0; i < _written_password.size(); i++)
        {
            collection_of_written_letters += _written_password[i][count];
        }

        // I have to map each character of collection_of... to its
        // respective numbers and assign those to collection_of_digits
        // If I find one repeated character
        std::string collection_of_digits = "";
        for (int i = 0; i < _associations.size(); i++)
        {

            char mapper = collection_of_written_letters[i];
            std::string c(1, mapper);
            collection_of_digits += _associations[i][c];
        }
        

        int greatestOcurrence = 0;
        char greatest;

        std::map<char, int> holder;
        for (int i = 0; i < collection_of_digits.size(); i++)
        {
            holder[collection_of_digits[i]]++;
        }
        for (auto i : holder)
        {
            if (i.second > greatestOcurrence)
            {
                greatestOcurrence = i.second;
                greatest = i.first;
            }
        }

        std::string c(1, greatest);

        cracked_password += c;
        
        count++;
        collection_of_written_letters = "";
    }

    std::string cracked_password_formatted;

    for(int i=0;i<cracked_password.size();i++){
        std::string ch(1,cracked_password[i]);
        cracked_password_formatted+=ch;
        if(i!=cracked_password.size()-1){
            cracked_password_formatted+=" ";
        }
    }

    return cracked_password_formatted;
}