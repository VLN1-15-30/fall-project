#ifndef LIST
#define LIST

#include <string>
#include <iostream>
#include <vector>
#include <person.h>
#include <fstream>
#include <algorithm>

using namespace std;

class List
{
public:
    List();
    void initialize(string fileName );
    void writeToFile(vector <person>& p);
    vector<person> const getChar() const {return charachters;}
    void addData ();
    void search();
    void printData(vector <person>& p);
    void performSearchBasedOn(const char& selection);
    void showList() const;
    void showOrderedList(int column, int order);
    void orderbyNameA_Z(vector <person>& p);
    void orderbyNameZ_A(vector <person>& p);
    void orderbyBornASC(vector <person>& p);
    void orderbyBornDESC(vector <person>& p);
    char ask_again();
    friend ostream& operator<< (ostream& stream,const List& p);

private:
    vector<person> charachters;
    vector<person> newEntries;

    int numberOfEntries;
    int addedEntries;
    int totalEntries;
};

#endif // LIST
