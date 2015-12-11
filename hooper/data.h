#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include <iostream>
#include <computer.h>
#include <string>
#include <person.h>
#include <sstream>
#include <connection.h>

using namespace std;

class data
{
public:
    data();

    void update(int rowId, string fieldname, string value,string tableName);
    void deleteObj(int type, string name);
    void closeDBConnection();
    void initialize();

    bool addNewConnection(int pid, int cid);
    bool addNewComputer(string name, string type, int year, bool made);
    bool addNewPerson(string firstname, string lastname, string sex, int born, int died);
    void updateConnection(int personID, int computerID, string fieldName, int newID);

    vector<connection> getConnections();
    vector<connection> getConnectionsSorted(int sort, int column);
    vector<computer> getComputers();
    vector<computer> getComputersSorted(int sort, int column);
    vector<person> getPersons();
    vector<person> getPersonsSorted(int sort, int column);
    vector<person> searchPerson(string field, string obj);
    vector<computer> searchComputer (string field, string obj);
    QSqlQuery getRandom(int type);

    int getComputerByID(QString computerName);
    int removeConnectionByID(int pid, int cid);
    int countDatabaseInput(int type);
    int getPersonID(QString lastName, QString firstName);


private:
    QSqlDatabase db;
    vector<person> queryPerson(QString sqlQuery);
    vector<computer> queryComputer(QString sqlQuery);
    vector<connection> queryConnection(QString sqlQuery);

};

#endif // DATA_H
