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
    void setData();
    void addData(person p);
    void addComp (computer c);
    void addConnection(int personID, int computerID);
    void search();
    void printList(vector <person>& p);
    void performSearchBasedOn(const char& selection);
    void printTable(vector <person>& p);
    bool databaseEmpty();
    void showOrdered(int column, int order, int format);
    void orderbyNameA_Z();
    void orderbyNameZ_A(vector <person>& p);
    void orderbyBornASC(vector <person>& p);
    void orderbyBornDESC(vector <person>& p);
    void discoverAPioneer();
    void removeCharacter();
    void removeCharacterWithIndex();
    void tableBegin();

    int countDatabase();
    char ask_again();
    person returnPersonAtIndex(int index);
    person returnNewPersonWith(string firstname,string lastname, string sex, int born, int died);

    friend ostream& operator<< (ostream& stream,const List& p);

private:
    vector<person> characters;
    vector<person> newEntries;
    QSqlDatabase db;

};

#endif // LIST
