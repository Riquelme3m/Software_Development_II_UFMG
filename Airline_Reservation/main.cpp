#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include"flight.h"
#include<string>

//Defining the specifications to connect to the database

const std::string server = "tcp://172.27.240.1:3306"; 
const std::string username = "Anyone";  
const std::string password = "12345678"; 
const std::string schema = "airlinecompany"; 


void connectTodatabase();
void insertIntodatabase(const std::string& insertQuery);




int main(){

    connectTodatabase(); // Making the connection with the database

    Flight f1("101","G","Canada",50);
    Flight f2("102","KLM","Finland",60);
    Flight f3("104","Air France","Netherlands",55);

    std::string insert1="INSERT INTO Airline (FlightNumber,Departure,Destination,Seat) VALUES ('"+ f1.getFlightnumber() +"','"+ f1.getDeparture() +"','"+ f1.getDestination() +"'," + std::to_string(f1.getSeat()) + ")";
    std::string insert2="INSERT INTO Airline (FlightNumber,Departure,Destination,Seat) VALUES ('"+ f2.getFlightnumber() +"','"+ f2.getDeparture() +"','"+ f2.getDestination() +"'," + std::to_string(f2.getSeat()) + ")";
    std::string insert3="INSERT INTO Airline (FlightNumber,Departure,Destination,Seat) VALUES ('"+ f3.getFlightnumber() +"','"+ f3.getDeparture() +"','"+ f3.getDestination() +"'," + std::to_string(f3.getSeat()) + ")";

    insertIntodatabase(insert1); // Inserting data into the database
    insertIntodatabase(insert2);
    insertIntodatabase(insert3);

    // Create a statement after connecting to the database
    sql::Driver* driver = get_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect(server, username, password));
    con->setSchema(schema);

    std::unique_ptr<sql::Statement> stmt(con->createStatement());

    while(true){
        std::cout<<std::endl;
        std::cout<<"Welcome to Airlines Reservation System"<<std::endl;
        std::cout<<"**************************************"<<std::endl;
        std::cout<<"1. Reserve A Seat In a Flight: "<<std::endl;
        std::cout<<"2. Exit: "<<std::endl;
        std::cout<<"Enter Your Choice : ";
        int choice;
        std::cin>>choice;

        if(choice==1){
            try{ 
                
                // Getting the database from the database in order to show to the user
                std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Airline"));

                std::cout << "FlightNumber | Departure | Destination | Seat" << std::endl;
                std::cout << "---------------------------------------------" << std::endl;

                while(res->next()){
                    std::cout << res->getString("FlightNumber") << " | ";
                    std::cout << res->getString("Departure") << " | ";
                    std::cout << res->getString("Destination") << " | ";
                    std::cout << res->getInt("Seat") << std::endl;
                }

            }
            catch(sql::SQLException& e){
                std::cout<<"SQL Error: "<<e.what()<<std::endl;
            }

            std::string flight;
            std::cout<<std::endl;
            std::cout<<"Enter the Flight Number: ";
            std::cin>>flight;

            try{ 
                // Checking if the flight exists
                std::string check="SELECT Seat FROM Airline WHERE FlightNumber= '"+flight+"'";
                std::unique_ptr<sql::ResultSet> checkRes(stmt->executeQuery(check));

                if(checkRes->next()){
                    // If the flight exists, I am going to update the number of seats
                    int availableSeats=checkRes->getInt("Seat");
                    if(availableSeats>0){
                        std::string update="UPDATE Airline SET Seat = '"+std::to_string(availableSeats-1) +"' WHERE FlightNumber = '"+flight+"'";
                        stmt->executeUpdate(update);
                        std::cout<<"Seat reserved successfully!"<<std::endl;

                    }
                    else{
                        std::cout<<"There are not available seats for this flight."<<std::endl;
                    }
                }

                else{
                    std::cout<<"Flight not found"<<std::endl;
                }

            }
            catch(sql::SQLException& e){
                std::cout<<"SQL Error: "<<e.what()<<std::endl;
            }
        }

        else if(choice==2){
            break;
        }

        else{
            std::cout<<"Please enter a valid option."<<std::endl;
        }  
    }

    return 0;
}
//Declaration of basic functions to connect to the database and insert data .


void connectTodatabase(){
    try {
    sql::Driver* driver = get_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect(server, username, password));
    con->setSchema(schema);

    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT 'Hello World!' AS _message"));  // Example query
    while (res->next()) {
        //std::cout << "\t... MySQL replies: ";
        //std::cout << res->getString("_message") << std::endl;
    }
} catch (sql::SQLException& e) {
    std::cout << "# ERR: SQLException in " << __FILE__;
    std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
    std::cout << "# ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
}
    std::cout<<"You are connected to the database : "<<schema<<std::endl;

}

void insertIntodatabase(const std::string& insertQuery) {
    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect(server, username, password));
        con->setSchema(schema);

        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        stmt->executeUpdate(insertQuery);
        //std::cout << "Flight inserted successfully into the database." << std::endl;
    } catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}
