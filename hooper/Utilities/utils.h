#ifndef UTILS_H
#define UTILS_H

#include "person.h"
#include "computer.h"
#include <QtSql>


namespace utils {

    void update(int rowId, string fieldname, string value,string tableName);
    void deleteObj(int type, string name);
    int countDatabaseInput(int type);
    void closeDBConnection();

    QSqlDatabase getDatabaseConnection();
}

#endif // UTILS_H
