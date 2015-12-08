#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include <iostream>
#include <computer.h>
#include <string>

using namespace std;

class data
{
public:
    data();
    void initialize();
    QSqlQuery getConnections();
    QSqlQuery getConnectionsSorted(int sort, int column);
    void Update(int rowId, string fieldname, string value,string tableName);

    bool addNewConnection(int pid, int cid);
    bool addNewComputer(string name, string type, int year, bool made);
    bool addNewPerson(string firstname, string lastname, string sex, int born, int died);
    QSqlQuery getComputers();
    QSqlQuery getComputersSorted(int sort, int column);
    int getPersonID(QString lastName, QString firstName);
    QSqlQuery getPersons();
    QSqlQuery getPersonsSorted(int sort, int column);
    int getComputerByID(QString computerName);
    int removeConnectionByID(int pid, int cid);




private:
    QSqlDatabase db;

};

#endif // DATA_H
