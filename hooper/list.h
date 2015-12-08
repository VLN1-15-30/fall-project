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
    void initialize();

    vector<person> const getChar();
    vector<computer> const getComputer();
    QSqlQuery getConnections();
    QSqlQuery getComputers();
    QSqlQuery getPersons();

    void setData();
    void addData(person p);
    void addComp (computer c);
    void addConnection(string firstName, string lastName, string computerName);
    void search(string table);
    void printList(QSqlQuery q);
    void printComputerList(QSqlQuery q);
    void performSearchBasedOn(const char& selection, string table);
    void printTable(QSqlQuery q);
    void printComputerTable(QSqlQuery q);
    void printConnectionsTable(QSqlQuery q);
    bool databaseEmpty();
    bool computersDatabaseEmpty();
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

    void deleteRowAtIndex(int rowNumber, int type);
    void deleteCharacterWithName(string lastname, int type);

    void updatePioneer(int row,QSqlQuery pquery);
    void updateComputer(int row, QSqlQuery& cquery);

    int countDatabase(int type);

    char ask_again();
    person returnPersonAtIndex(int index);
    computer returnNewComputer(string name, string type, int year, bool made);
    person returnNewPersonWith(string firstname,string lastname, string sex, int born, int died);

    friend ostream& operator<< (ostream& stream,const List& p);

private:
    vector<computer> computers;
    vector<person> characters;
    vector<person> newEntries;
    data db;
    QSqlQuery q;

};

#endif // LIST
