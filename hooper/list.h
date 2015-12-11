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
#include <data.h>

using namespace std;

class List
{
public:
    List();

    QSqlQuery getConnections();
    QSqlQuery getComputers();
    vector<person> getPersons();

    bool databaseEmpty();
    bool computersDatabaseEmpty();

    void initialize();
    void setData();
    void addData(person p);
    void addComp (computer c);
    void addConnection(string firstName, string lastName, string computerName);
    void search(string table);
    void printList(QSqlQuery q);
    void printComputerList(QSqlQuery q);
    void printConnectionsList(QSqlQuery q);
    void performSearchBasedOn(const char& selection, string& table);
    void printTable(vector<person>& p);
    void printComputerTable(QSqlQuery q);
    void printConnectionsTable(QSqlQuery q);
    void showOrdered(int choice, int column, int order, int view);
    void orderbyPersons(int sort, int column, int view);
    void orderbyComputers(int sort, int column, int view);
    void orderbyConnections(int sort, int column);
    void discover(int type);
    void removeCharacter();
    void removeComputer();
    void removeConnection(string firstname, string lastName, string computerName);
    void closeDatabase();
    void tableBegin();
    void computerTableBegin();
    void connectionsTableBegin();
    void deleteCharacterWithName(string lastname, int type);
    void updatePioneer(int row,QSqlQuery pquery);
    void updateComputer(int row, QSqlQuery& cquery);
    void updateConnectionPerson(int personID, int computerID);
    void updateConnectionComputer(int personID, int computerID);
    void updateConnections(string firstName, string lastName, string computerName);
    int countDatabase(int type);
    int getPersonID(string lastName, string firstName);
    int getComputerID(string computerName);





    char ask_again();
    computer returnNewComputer(string name, string type, int year, bool made);
    person returnPersonAtIndex(int index);
    person returnNewPersonWith(string firstname,string lastname, string sex, int born, int died);
    friend ostream& operator<< (ostream& stream,const List& p);

private:
    vector<person> characters;
    data db;
    QSqlQuery q;

};

#endif // LIST
