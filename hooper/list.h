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

using namespace std;

class List
{
public:
    List();
    void initialize();
    void writeToFile(vector <person>& p);
    void OverWriteToFile(vector <person>& p);

    vector<person> const getChar();
    vector<computer> const getComputers();

    void setData();
    void addData(person p);
    void addComp (computer c);
    void addConnection(int personID, int computerID);
    void search();
    void printList(vector <person>& p);
    void performSearchBasedOn(const char& selection);
    void printTable(vector <person>& p);
    void printComputerTable(vector <computer>& c);
    bool databaseEmpty();
    bool computersDatabaseEmpty();
    void showOrdered(int column, int order, int format);
    void orderbyNameA_Z(int format);
    void orderbyNameZ_A(int format);
    void orderbyBornASC(int format);
    void orderbyBornDESC(int format);
    void discover(int type);
    void removeCharacter();
    void removeComputer();
    void removeComputerWithIndex();
    void removeCharacterWithIndex();

    void tableBegin();
    void computerTableBegin();

    void deleteRowAtIndex(int rowNumber, int type);
    void deleteCharacterWithName(string lastname, int type);

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
    QSqlDatabase db;

};

#endif // LIST
