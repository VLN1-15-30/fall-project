#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include <iostream>
#include <computer.h>

using namespace std;

class data
{
public:
    data();
    void initialize();
    QSqlQuery getConnections();
    QSqlQuery getConnectionsSorted(int sort, int column);
    bool addNewConnection(int pid, int cid);
    QSqlQuery getComputers();
    QSqlQuery getComputersSorted(int sort, int column);



private:
    QSqlDatabase db;

};

#endif // DATA_H
