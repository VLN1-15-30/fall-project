#ifndef LIST
#define LIST

#include <string>
#include <iostream>
#include <vector>
#include <person.h>
#include <computer.h>
#include <fstream>
#include <algorithm>
#include <QtSql>
#include "connectionrepo.h"
#include "personrepo.h"
#include "computerrepo.h"
#include "Utilities/utils.h"


using namespace std;

class List
{
public:
    List();

    vector<connection> getConnections();
    vector<computer> getComputers();
    vector<person> getPersons();

    bool databaseEmpty();
    bool computersDatabaseEmpty();

    bool addPerson(person p);
    bool addComp (computer c);
    bool addConnection(string firstName, string lastName, string computerName);

    void search(string table);
    vector<person> getSearchPerson(string column, string target);
    vector<computer> getSearchComputer(string column, string target);
    vector<person> orderbyPersons(int sort, int column);
    vector<computer> orderbyComputers(int sort, int column);
    vector<connection> orderbyConnections(int sort, int column);
    person returnPersonAtIndex(int index);
    person discoverPerson();
    computer discoverComputer();
    void removeConnection(string firstname, string lastName, string computerName);
    void closeDatabase();
    void deleteCharacterWithName(string lastname, int type);
    void update(int identiy,string fieldName, string value, string tableName);
    void updateComputer(int row, vector<computer>& c);
    void updateConnection(int personID, int computerID, string fieldName, int newID);
    int countDatabase(int type);
    int getPersonID(string lastName, string firstName);
    int getComputerID(string computerName);




private:
    vector<person> characters;
    personRepo personR;
    computerRepo computerR;
    connectionRepo connectionR;
    QSqlQuery q;

};

#endif // LIST
