#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>

// Class to represent a Fatura (Invoice)
class Fatura {
    private:
        std::string codigo;    // Invoice code
        char tipo_Fatura;      // Type of invoice (e.g., p, b, g)
        double valor;          // Value of the invoice

    public:
        // Constructor to initialize Fatura object with code, type, and value
        Fatura(std::string cod, char tipo, double val) {
            codigo = cod;
            tipo_Fatura = tipo;
            valor = val;
        }

        // Function to print the Fatura details
        void imprimir() {
            std::cout << tipo_Fatura << " " << valor << " " << codigo << std::endl;
        }

        // Getter function for valor (value) of Fatura
        double getValor() {
            return valor;
        }

        // Getter function for tipo_Fatura (type of invoice)
        char getTipo() {
            return tipo_Fatura;
        }
};

// Class to represent a collection of Faturas
class Colecao {
    private:
        std::map<char, int> status;     // Map to store the count of invoices by type (p, b, g)
        std::vector<Fatura> faturas;    // Vector to store the collection of Faturas
        
    public:
        // Constructor to initialize the status of the three invoice types (p, b, g) to 0
        Colecao() {
            status['p'] = 0;   // Pending invoices
            status['b'] = 0;   // Paid invoices
            status['g'] = 0;   // Archived invoices
        }

        // Function to add a Fatura to the collection in sorted order
        void adicionar(Fatura f) {
            // Iterator to traverse the faturas vector
            std::vector<Fatura>::iterator it = faturas.begin(); 

            // Loop through faturas to find the correct position for the new fatura
            for (; it != faturas.end(); ++it) {
                // Insert fatura at the first position where its value is less than or equal to the current one
                if (f.getValor() <= it->getValor()) {
                    faturas.insert(it, f);  // Insert the fatura at the correct position
                    status[f.getTipo()]++;  // Update the status for the invoice type
                    return;                 // Exit after insertion
                }
            }

            // If the loop completes, it means the new fatura has the highest value, so append it to the end
            faturas.push_back(f);
            status[f.getTipo()]++;  // Update the status for the invoice type
        }

        // Function to remove and print the last Fatura in the collection
        void proxima() {
            if (!faturas.empty()) {  // Ensure the collection is not empty
                Fatura fatura_Removida = faturas.back();  // Get the last Fatura
                faturas.pop_back();  // Remove the last Fatura from the vector
                fatura_Removida.imprimir();  // Print the details of the removed Fatura
                status[fatura_Removida.getTipo()]--;  // Decrement the count for its type
            }
        }

        // Function to print all Faturas in the collection
        void imprimirColec() {
            std::vector<Fatura>::iterator it = faturas.begin();  // Iterator for the vector

            // Loop through the faturas and print each one
            for (; it != faturas.end(); ++it) {
                it->imprimir();  // Call the imprimir function to print the details
            }
        }

        // Function to print the status of each invoice type (p, b, g)
        void imprimirStatus() {
            std::map<char, int>::iterator it = status.begin();  // Iterator for the map

            // Loop through the status map and print the count for each invoice type
            for (; it != status.end(); ++it) {
                std::cout << it->first << " " << it->second << std::endl;  // Print type and count
            }
        }
};

// Main function where the program starts executing
int main() {
    Colecao test = Colecao();  // Create a Colecao object to manage invoices
    std::string input;         // String to hold user input

    // Infinite loop to keep accepting user commands
    while (true) {
        std::getline(std::cin, input);  // Get input from the user
        std::istringstream iss(input);  // Create a string stream to process the input

        std::string command;
        iss >> command;  // Extract the command (first word of the input)

        // Check the command and execute corresponding actions
        if (command == "f") {  // If the command is 'f', add a new Fatura
            char tipo_Fatura;
            double valor;
            std::string codigo;

            // Read the type, value, and code of the Fatura from the input
            if (iss >> tipo_Fatura >> valor >> codigo) {
                Fatura fatura = Fatura(codigo, tipo_Fatura, valor);  // Create a Fatura object
                test.adicionar(fatura);  // Add the Fatura to the collection
            }
        }

        // If the input is 'r', remove and print the next Fatura in the collection
        if (input == "r") {
            test.proxima();
        }

        // If the input is 'p', print all Faturas in the collection
        if (input == "p") {
            test.imprimirColec();
        }

        // If the input is 's', print the status of each invoice type
        if (input == "s") {
            test.imprimirStatus();
        }

        // If the input is 'e', exit the program
        if (input == "e") {
            break;
        }
    }

    return 0;  // Return 0 to indicate successful execution
}
