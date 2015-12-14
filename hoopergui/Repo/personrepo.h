#ifndef PERSONREPO_H
#define PERSONREPO_H

#include "person.h"
#include <QtSql>
#include <vector>
#include <sstream>


class personRepo
{
public:
    personRepo();

    bool addNewPerson(string firstname, string lastname, string sex, int born, int died);
    int getPersonID(QString lastName, QString firstName);

    person getRandomPerson();
    vector<person> getPersons();
    vector<person> getPersonsSorted(int sort, int column);
    vector<person> searchPerson(string field, string obj);

private:
    vector<person> queryPerson(QString sqlQuery);
    QSqlDatabase db;

};

#endif // PERSONREPO_H
