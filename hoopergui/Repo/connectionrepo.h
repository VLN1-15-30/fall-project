#ifndef CONNECTIONREPO_H
#define CONNECTIONREPO_H

#include "connection.h"
#include <QtSql>
#include <sstream>
#include <vector>

class connectionRepo
{
public:
    connectionRepo();
    bool addNewConnection(int pid, int cid);
    void updateConnection(int personID, int computerID, string fieldName, int newID);
    int removeConnectionByID(int pid, int cid);

    vector<connection> getConnections();
    vector<connection> getConnectionsSorted(int sort, int column);
    connection getRandomConnection();


private:
    vector<connection> queryConnection(QString sqlQuery);
    QSqlDatabase db;
};

#endif // CONNECTIONREPO_H
