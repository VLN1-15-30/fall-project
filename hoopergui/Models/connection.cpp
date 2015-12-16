#include "connection.h"

connection::connection()
{

}

connection::connection(string firstName, string lastName, string computerName, int year)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->computerName = computerName;
    this->yearInvented = year;
}

string connection::getFirstName()
{
    return firstName;
}

string connection::getLastName()
{
    return lastName;
}

string connection::getComputerName()
{
    return computerName;
}

int connection::getYearInvented()
{
    return yearInvented;
}




