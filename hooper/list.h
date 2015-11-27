#ifndef LIST
#define LIST

#include <string>
#include <iostream>
#include <vector>
#include <person.h>
#include <fstream>

using namespace std;

class List
{
public:
    List();
    void initialize(string fileName );
    void writeToFile(vector <person>& p);
    void addData ();
    char ask_again();
    friend ostream& operator<< (ostream& stream,const List& p);

private:
    vector<person> charachters;
    vector <person> newEntries;

    int numberOfEntries;
    int addedEntries;
    int totalEntries;
};


#endif // LIST

