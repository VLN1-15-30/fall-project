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
    void Update(int rowId, string fieldname, string value,string tableName);

    bool addNewConnection(int pid, int cid);
<<<<<<< HEAD
    QSqlQuery getComputers();
    QSqlQuery getComputersSorted(int sort, int column);
=======
    int getPersonID(QString lastName, QString firstName);
>>>>>>> a059ddacf32288a7b65109bbe37c976d43a5754e



private:
    QSqlDatabase db;

};

#endif // DATA_H
