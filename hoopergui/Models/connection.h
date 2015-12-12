#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

using namespace std;

class connection
{
public:
    connection();
    connection(string firstName, string lastName, string computerName, int year);
    string getFirstName();
    string getLastName();
    string getComputerName();
    int getYearInvented();


private:
    string firstName;
    string lastName;
    string computerName;
    int yearInvented;
};

#endif // CONNECTION_H
