#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include <iostream>

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


private:
    QSqlDatabase db;

};

#endif // DATA_H
