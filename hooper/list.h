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
    void orderbyNameA_Z(int format);
    void orderbyNameZ_A(int format);
    void orderbyBornASC(int format);
    void orderbyBornDESC(int format);
    void discoverAPioneer();
    void removeCharacter();
    void removeCharacterWithIndex();
    void tableBegin();
    void deleteRowAtIndex(int rowNumber);
    void deleteCharacterWithName(string lastname);


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
