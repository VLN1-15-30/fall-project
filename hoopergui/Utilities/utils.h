#ifndef UTILS_H
#define UTILS_H

#include "Models/person.h"
#include "Models/computer.h"
#include "Models/connection.h"
#include <QtSql>


namespace utils {

    void update(int rowId, string fieldname, string value,string tableName);
    void deleteObj(int type, string name);
    int countDatabaseInput(int type);
    void closeDBConnection();
    void writeToFile(vector<person>& p, int num);
    void writeToFile(vector<computer>& c, int num);
    void writeToFile(vector<connection>& conn, int num);

    QSqlDatabase getDatabaseConnection();
}

#endif // UTILS_H
