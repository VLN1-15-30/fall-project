#ifndef COMPUTERREPO_H
#define COMPUTERREPO_H

#include "computer.h"
#include <QtSql>
#include <vector>
#include <sstream>


class computerRepo
{
public:
    computerRepo();

    bool addNewComputer(string name, string type, int year, bool made);
    int getComputerByID(QString computerName);

    computer getRandomComputer();
    vector<computer> getComputers();
    vector<computer> getComputersSorted(int sort, int column);
    vector<computer> searchComputer (string field, string obj);

private:
    vector<computer> queryComputer(QString sqlQuery);
    QSqlDatabase db;
};

#endif // COMPUTERREPO_H
