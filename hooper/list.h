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
    void showList() const;
    void showOrderedList(int column, int order);
    void orderbyNameA_Z(vector <person>& p);
    void orderbyNameZ_A(vector <person>& p);
//    void orderbyBornASCE();
//    void orderbyBornDESC();
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
