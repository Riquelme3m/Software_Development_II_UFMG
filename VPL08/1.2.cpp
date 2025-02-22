#include <iostream>
#include <string>

class ASCIIArt
{
private:
public:
    static void print(std::string word)
    {
        int length = word.size();
        for (int i = 0; i < length + 4; i++)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
        int count = 0;
        for (int i = 0; i < length + 4; i++)
        {
            if (i == 0 || i == (length + 4) - 1)
            {
                std::cout << "-";
            }
            else if (i == 1 || i == (length + 4) - 2)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << word[count];
                count++;
            }
        }
        std::cout << std::endl;
        for (int i = 0; i < length + 4; i++)
        {
            if ((i == ((length + 4) / 2) - 1))
            {
                std::cout << "\\";
            }
            else if ((i == ((length + 4) / 2)))
            {
                std::cout << "/";
            }
            else
            {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }

    static void print(char c)
    {
        std::string word = "ASCII ART";
        int count = 0;
        for (int i = 0; i < 13; i++)
        {
            std::cout << c;
        }
        std::cout << std::endl;
        for (int i = 0; i < 13; i++)
        {
            if (i == 0 || i == 12)
            {
                std::cout << c;
            }
            else if (i == 1 || i == 11)
            {
                std::cout << " ";
            }
            else{
                std::cout<<word[count];
                count++;
            }
        }
        std::cout<<std::endl;
        for (int i = 0; i < 13; i++){
            if(i==((13/2)-1)){
                std::cout<<"\\";
            }
            else if(i==((13/2))){
                std::cout<<"/";
            }
            else{
                std::cout<<c;
            }

        }
        std::cout<<std::endl;

    }

    static void print(int c){
        // for the first line I can have a string like
        // -O- and every time unless it's the last iteration I print
        // - to separate each one
        std::string firstLine = "-O-";
        for(int i=0;i<c;i++){
            if(i!=(c-1)){
                std::cout<<firstLine;
                std::cout<<"-";
            }
            else{
                std::cout<<firstLine;
                
            }
        }
        std::cout<<std::endl;
        std::string secondLine = "/|\\";
        for(int i=0;i<c;i++){
            if(i!=(c-1)){
                std::cout<<secondLine;
                std::cout<<"-";
            }
            else{
                std::cout<<secondLine;
                
            }
        }
        std::cout<<std::endl;
        std::string thirdLine = "/-\\";
        for(int i=0;i<c;i++){
            if(i!=(c-1)){
                std::cout<<thirdLine;
                std::cout<<"-";
            }
            else{
                std::cout<<thirdLine;
                
            }
        }
        std::cout<<std::endl;
    }
};

int main()
{

    ASCIIArt::print("codigo");
    std::cout<<std::endl;
    ASCIIArt::print('m');
    std::cout<<std::endl;
    ASCIIArt::print(3);
    return 0;
}